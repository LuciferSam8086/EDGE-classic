//------------------------------------------------------------------------
//  Image Handling
//------------------------------------------------------------------------
// 
//  Copyright (c) 2003-2008  The EDGE Team.
//  Migrated to use stb_image in 2021 - Dashodanger
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
//------------------------------------------------------------------------

#ifndef __EPI_IMAGE_FUNCS_H__
#define __EPI_IMAGE_FUNCS_H__

#include "file.h"
#include "image_data.h"
#include <filesystem>

namespace epi
{

typedef enum
{
	FMT_Unknown = 0,
	FMT_PNG,
	FMT_TGA,
	FMT_JPEG,
	FMT_DOOM,
	FMT_OTHER  // e.g. gif, dds, bmp
}
image_format_e;

// determine image format from the first 32 bytes (or so) of the file.
// the file_size is the total size of the file or lump, and helps to
// distinguish DOOM patch format from other things.
image_format_e Image_DetectFormat(byte *header, int header_len, int file_size);

// determine image format from the filename (by its extension).
image_format_e Image_FilenameToFormat(const std::filesystem::path& filename);

// loads the given image, which must be PNG, TGA or JPEG format.
// Returns NULL if something went wrong.  The result image will be RGB
// or RGBA (never paletted).  The image size (width and height) will be
// rounded to the next power-of-two.
image_data_c *Image_Load(file_c *f);

// reads the principle information from the image header.
// (should be much faster than loading the whole image).
// The image must be PNG, TGA or JPEG format, it cannot be used
// with DOOM patches.  Returns false if something went wrong.
//
// NOTE: size returned here is the real size, and may be different
// from the image returned by Load() which rounds to power-of-two.
bool Image_GetInfo(file_c *f, int *width, int *height, int *bpp);

// saves the image (in JPEG format) to the given file.  Returns false if
// something went wrong.  The image _MUST_ be RGB (bpp == 3).
bool JPEG_Save(std::filesystem::path fn, image_data_c *img);

// saves the image (in PNG format) to the given file.
// Returns false if failed to save (e.g. file already exists).
// The image _MUST_ be RGB or RGBA.
bool PNG_Save(std::filesystem::path fn, image_data_c *img);

}  // namespace epi

#endif  /* __EPI_IMAGE_JPEG_H__ */

//--- editor settings ---
// vi:ts=4:sw=4:noexpandtab
