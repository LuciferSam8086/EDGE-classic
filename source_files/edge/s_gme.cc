//----------------------------------------------------------------------------
//  EDGE GME Music Player
//----------------------------------------------------------------------------
// 
//  Copyright (c) 2022 - The EDGE Team.
// 
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//----------------------------------------------------------------------------

#include "i_defs.h"

#include "endianess.h"
#include "file.h"
#include "filesystem.h"
#include "sound_gather.h"

#include "playlist.h"

#include "s_cache.h"
#include "s_blit.h"
#include "s_music.h"
#include "s_gme.h"
#include "w_wad.h"

#include "gme.h"

#define GME_BUFFER 1024 * 10

extern bool dev_stereo;  // FIXME: encapsulation
extern int  dev_freq;

class gmeplayer_c : public abstract_music_c
{
public:
	 gmeplayer_c();
	~gmeplayer_c();
private:

	enum status_e
	{
		NOT_LOADED, PLAYING, PAUSED, STOPPED
	};
	
	int status;
	bool looping;

	Music_Emu *gme_track;

	s16_t *mono_buffer;

public:
	bool OpenMemory(byte *data, int length);

	virtual void Close(void);

	virtual void Play(bool loop);
	virtual void Stop(void);

	virtual void Pause(void);
	virtual void Resume(void);

	virtual void Ticker(void);
	virtual void Volume(float gain);

private:

	void PostOpenInit(void);

	bool StreamIntoBuffer(epi::sound_data_c *buf);
	
};

//----------------------------------------------------------------------------

gmeplayer_c::gmeplayer_c() : status(NOT_LOADED)
{
	mono_buffer = new s16_t[GME_BUFFER * 2];
}

gmeplayer_c::~gmeplayer_c()
{
	Close();

	if (mono_buffer)
		delete[] mono_buffer;
}

void gmeplayer_c::PostOpenInit()
{   
	// Loaded, but not playing
	status = STOPPED;
}


static void ConvertToMono(s16_t *dest, const s16_t *src, int len)
{
	const s16_t *s_end = src + len*2;

	for (; src < s_end; src += 2)
	{
		// compute average of samples
		*dest++ = ( (int)src[0] + (int)src[1] ) >> 1;
	}
}

bool gmeplayer_c::StreamIntoBuffer(epi::sound_data_c *buf)
{
	s16_t *data_buf;

	bool song_done = false;

	if (!dev_stereo)
		data_buf = mono_buffer;
	else
		data_buf = buf->data_L;

	gme_err_t stream_error = gme_play(gme_track, GME_BUFFER, data_buf);

	if (stream_error) // ERROR
	{
		I_Debugf("[gmeplayer_c::StreamIntoBuffer] Failed: %s\n", stream_error);
		return false;
	}

	if (gme_track_ended(gme_track))
		song_done = true;

	buf->length = GME_BUFFER / (dev_stereo ? 2 : 1);

	if (!dev_stereo)
		ConvertToMono(buf->data_L, mono_buffer, buf->length);

	if (song_done)  /* EOF */
	{
		if (! looping)
			return false;
		gme_err_t seek_error = gme_seek_samples(gme_track, 0);
		if (seek_error)
			return false;
		return true;
	}

    return (true);
}


void gmeplayer_c::Volume(float gain)
{
	// not needed, music volume is handled in s_blit.cc
	// (see mix_channel_c::ComputeMusicVolume).
}


bool gmeplayer_c::OpenMemory(byte *data, int length)
{
	SYS_ASSERT(data);

	gme_track = gme_new_emu(NULL, dev_freq);

	gme_err_t open_error = gme_open_data(data, length, &gme_track, dev_freq);

    if (open_error)
    {
		I_Warning("[gmeplayer_c::Open](DataLump) Failed: %s\n", open_error);
		return false;
    }

	PostOpenInit();
	return true;
}


void gmeplayer_c::Close()
{
	if (status == NOT_LOADED)
		return;

	// Stop playback
	if (status != STOPPED)
		Stop();
		
	gme_delete(gme_track);

	status = NOT_LOADED;
}


void gmeplayer_c::Pause()
{
	if (status != PLAYING)
		return;

	status = PAUSED;
}


void gmeplayer_c::Resume()
{
	if (status != PAUSED)
		return;

	status = PLAYING;
}


void gmeplayer_c::Play(bool loop)
{
    if (status != NOT_LOADED && status != STOPPED) return;

	status = PLAYING;
	looping = loop;

	gme_start_track(gme_track, 0);

	// Load up initial buffer data
	Ticker();
}


void gmeplayer_c::Stop()
{
	if (status != PLAYING && status != PAUSED)
		return;

	S_QueueStop();

	status = STOPPED;
}


void gmeplayer_c::Ticker()
{
	while (status == PLAYING)
	{
		epi::sound_data_c *buf = S_QueueGetFreeBuffer(GME_BUFFER, 
				(dev_stereo) ? epi::SBUF_Interleaved : epi::SBUF_Mono);

		if (! buf)
			break;

		if (StreamIntoBuffer(buf))
		{
			if (buf->length > 0)
			{
				S_QueueAddBuffer(buf, dev_freq);
			}
			else
			{
				S_QueueReturnBuffer(buf);
			}
		}
		else
		{
			// finished playing
			S_QueueReturnBuffer(buf);
			Stop();
		}
	}
}


//----------------------------------------------------------------------------

abstract_music_c * S_PlayGMEMusic(byte *data, int length, float volume, bool looping)
{
	gmeplayer_c *player = new gmeplayer_c();

	if (! player->OpenMemory(data, length))
	{
		delete[] data;
		delete player;
		return NULL;
	}

	// gme_open_data makes a copy of the data, so can free it here
	delete[] data;

	player->Volume(volume);
	player->Play(looping);

	return player;
}

//--- editor settings ---
// vi:ts=4:sw=4:noexpandtab
