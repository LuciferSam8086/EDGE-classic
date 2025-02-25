//------------------------------------------------------------------------
//  MOBJ Definitions
//------------------------------------------------------------------------
//
//  DEH_EDGE  Copyright (C) 2004-2005  The EDGE Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License (in COPYING.txt) for more details.
//
//------------------------------------------------------------------------
//
//  DEH_EDGE is based on:
//
//  +  DeHackEd source code, by Greg Lewis.
//  -  DOOM source code (C) 1993-1996 id Software, Inc.
//  -  Linux DOOM Hack Editor, by Sam Lantinga.
//  -  PrBoom's DEH/BEX code, by Ty Halderman, TeamTNT.
//
//------------------------------------------------------------------------

#include "deh_i_defs.h"
#include "deh_edge.h"

#include "deh_info.h"
#include "deh_sounds.h"
#include "deh_mobj.h"


namespace Deh_Edge
{

mobjinfo_t mobjinfo[NUMMOBJTYPES_COMPAT] =
{
	// MT_PLAYER
	{
		"OUR_HERO",       // name
		-1,		// doomednum
		S_PLAY,		// spawnstate
		100,		// spawnhealth
		S_PLAY_RUN1,		// seestate
		sfx_None,		// seesound
		0,		// reactiontime
		sfx_None,		// attacksound
		S_PLAY_PAIN,		// painstate
		255,		// painchance
		sfx_plpain,		// painsound
		S_NULL,		// meleestate
		S_PLAY_ATK1,		// missilestate
		S_PLAY_DIE1,		// deathstate
		S_PLAY_XDIE1,		// xdeathstate
		sfx_pldeth,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_DROPOFF|MF_PICKUP|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_POSSESSED
	{
		"ZOMBIEMAN",       // name
		3004,		// doomednum
		S_POSS_STND,		// spawnstate
		20,		// spawnhealth
		S_POSS_RUN1,		// seestate
		sfx_posit1,		// seesound
		8,		// reactiontime
		sfx_pistol,		// attacksound
		S_POSS_PAIN,		// painstate
		200,		// painchance
		sfx_popain,		// painsound
		0,		// meleestate
		S_POSS_ATK1,		// missilestate
		S_POSS_DIE1,		// deathstate
		S_POSS_XDIE1,		// xdeathstate
		sfx_podth1,		// deathsound
		8,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_posact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_POSS_RAISE1		// raisestate
	},

	// MT_SHOTGUY
	{
		"SHOTGUN_GUY",       // name
		9,		// doomednum
		S_SPOS_STND,		// spawnstate
		30,		// spawnhealth
		S_SPOS_RUN1,		// seestate
		sfx_posit2,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_SPOS_PAIN,		// painstate
		170,		// painchance
		sfx_popain,		// painsound
		0,		// meleestate
		S_SPOS_ATK1,		// missilestate
		S_SPOS_DIE1,		// deathstate
		S_SPOS_XDIE1,		// xdeathstate
		sfx_podth2,		// deathsound
		8,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_posact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_SPOS_RAISE1		// raisestate
	},

	// MT_VILE
	{
		"ARCHVILE",       // name
		64,		// doomednum
		S_VILE_STND,		// spawnstate
		700,		// spawnhealth
		S_VILE_RUN1,		// seestate
		sfx_vilsit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_VILE_PAIN,		// painstate
		10,		// painchance
		sfx_vipain,		// painsound
		0,		// meleestate
		S_VILE_ATK1,		// missilestate
		S_VILE_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_vildth,		// deathsound
		15,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		500,		// mass
		0,		// damage
		sfx_vilact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_FIRE
	{
		"*ARCHVILE_FIRE",       // (attack) name
		-1,		// doomednum
		S_FIRE1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_UNDEAD
	{
		"REVENANT",       // name
		66,		// doomednum
		S_SKEL_STND,		// spawnstate
		300,		// spawnhealth
		S_SKEL_RUN1,		// seestate
		sfx_skesit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_SKEL_PAIN,		// painstate
		100,		// painchance
		sfx_popain,		// painsound
		S_SKEL_FIST1,		// meleestate
		S_SKEL_MISS1,		// missilestate
		S_SKEL_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_skedth,		// deathsound
		10,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		500,		// mass
		0,		// damage
		sfx_skeact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_SKEL_RAISE1		// raisestate
	},

	// MT_TRACER
	{
		"*REVENANT_MISSILE",       // (attack) name
		-1,		// doomednum
		S_TRACER,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_skeatk,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_TRACEEXP1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_barexp,		// deathsound
		10*FRACUNIT,		// speed
		11*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		10,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_SMOKE
	{
		"SMOKE",       // name
		-1,		// doomednum
		S_SMOKE1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_FATSO
	{
		"MANCUBUS",       // name
		67,		// doomednum
		S_FATT_STND,		// spawnstate
		600,		// spawnhealth
		S_FATT_RUN1,		// seestate
		sfx_mansit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_FATT_PAIN,		// painstate
		80,		// painchance
		sfx_mnpain,		// painsound
		0,		// meleestate
		S_FATT_ATK1,		// missilestate
		S_FATT_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_mandth,		// deathsound
		8,		// speed
		48*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		1000,		// mass
		0,		// damage
		sfx_posact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		MBF21_MAP07BOSS1, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_FATT_RAISE1		// raisestate
	},

	// MT_FATSHOT
	{
		"*MANCUBUS_FIREBALL",       // (attack) name
		-1,		// doomednum
		S_FATSHOT1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_firsht,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_FATSHOTX1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		20*FRACUNIT,		// speed
		6*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		8,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_CHAINGUY
	{
		"HEAVY_WEAPON_DUDE",       // name
		65,		// doomednum
		S_CPOS_STND,		// spawnstate
		70,		// spawnhealth
		S_CPOS_RUN1,		// seestate
		sfx_posit2,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_CPOS_PAIN,		// painstate
		170,		// painchance
		sfx_popain,		// painsound
		0,		// meleestate
		S_CPOS_ATK1,		// missilestate
		S_CPOS_DIE1,		// deathstate
		S_CPOS_XDIE1,		// xdeathstate
		sfx_podth2,		// deathsound
		8,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_posact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_CPOS_RAISE1		// raisestate
	},

	// MT_TROOP
	{
		"IMP",       // name
		3001,		// doomednum
		S_TROO_STND,		// spawnstate
		60,		// spawnhealth
		S_TROO_RUN1,		// seestate
		sfx_bgsit1,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_TROO_PAIN,		// painstate
		200,		// painchance
		sfx_popain,		// painsound
		S_TROO_ATK1,		// meleestate
		S_TROO_ATK1,		// missilestate
		S_TROO_DIE1,		// deathstate
		S_TROO_XDIE1,		// xdeathstate
		sfx_bgdth1,		// deathsound
		8,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_bgact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_TROO_RAISE1		// raisestate
	},

	// MT_SERGEANT
	{
		"DEMON",       // name
		3002,		// doomednum
		S_SARG_STND,		// spawnstate
		150,		// spawnhealth
		S_SARG_RUN1,		// seestate
		sfx_sgtsit,		// seesound
		8,		// reactiontime
		sfx_sgtatk,		// attacksound
		S_SARG_PAIN,		// painstate
		180,		// painchance
		sfx_dmpain,		// painsound
		S_SARG_ATK1,		// meleestate
		0,		// missilestate
		S_SARG_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_sgtdth,		// deathsound
		10,		// speed
		30*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		400,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_SARG_RAISE1		// raisestate
	},

	// MT_SHADOWS
	{
		"SPECTRE",       // name
		58,		// doomednum
		S_SARG_STND,		// spawnstate
		150,		// spawnhealth
		S_SARG_RUN1,		// seestate
		sfx_sgtsit,		// seesound
		8,		// reactiontime
		sfx_sgtatk,		// attacksound
		S_SARG_PAIN,		// painstate
		180,		// painchance
		sfx_dmpain,		// painsound
		S_SARG_ATK1,		// meleestate
		0,		// missilestate
		S_SARG_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_sgtdth,		// deathsound
		10,		// speed
		30*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		400,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_SHADOW|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_SARG_RAISE1		// raisestate
	},

	// MT_HEAD
	{
		"CACODEMON",       // name
		3005,		// doomednum
		S_HEAD_STND,		// spawnstate
		400,		// spawnhealth
		S_HEAD_RUN1,		// seestate
		sfx_cacsit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_HEAD_PAIN,		// painstate
		128,		// painchance
		sfx_dmpain,		// painsound
		0,		// meleestate
		S_HEAD_ATK1,		// missilestate
		S_HEAD_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_cacdth,		// deathsound
		8,		// speed
		31*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		400,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_FLOAT|MF_NOGRAVITY|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_HEAD_RAISE1		// raisestate
	},

	// MT_BRUISER
	{
		"BARON_OF_HELL",       // name
		3003,		// doomednum
		S_BOSS_STND,		// spawnstate
		1000,		// spawnhealth
		S_BOSS_RUN1,		// seestate
		sfx_brssit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_BOSS_PAIN,		// painstate
		50,		// painchance
		sfx_dmpain,		// painsound
		S_BOSS_ATK1,		// meleestate
		S_BOSS_ATK1,		// missilestate
		S_BOSS_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_brsdth,		// deathsound
		8,		// speed
		24*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		1000,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		MBF21_E1M8BOSS, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_BOSS_RAISE1		// raisestate
	},

	// MT_BRUISERSHOT
	{
		"*BARON_FIREBALL",       // (attack) name
		-1,		// doomednum
		S_BRBALL1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_firsht,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_BRBALLX1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		15*FRACUNIT,		// speed
		6*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		8,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_KNIGHT
	{
		"HELL_KNIGHT",       // name
		69,		// doomednum
		S_BOS2_STND,		// spawnstate
		500,		// spawnhealth
		S_BOS2_RUN1,		// seestate
		sfx_kntsit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_BOS2_PAIN,		// painstate
		50,		// painchance
		sfx_dmpain,		// painsound
		S_BOS2_ATK1,		// meleestate
		S_BOS2_ATK1,		// missilestate
		S_BOS2_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_kntdth,		// deathsound
		8,		// speed
		24*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		1000,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_BOS2_RAISE1		// raisestate
	},

	// MT_SKULL
	{
		"LOST_SOUL",       // name
		3006,		// doomednum
		S_SKULL_STND,		// spawnstate
		100,		// spawnhealth
		S_SKULL_RUN1,		// seestate
		0,		// seesound
		8,		// reactiontime
		sfx_sklatk,		// attacksound
		S_SKULL_PAIN,		// painstate
		256,		// painchance
		sfx_dmpain,		// painsound
		0,		// meleestate
		S_SKULL_ATK1,		// missilestate
		S_SKULL_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		8,		// speed
		16*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		50,		// mass
		3,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_FLOAT|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_SPIDER
	{
		"THE_SPIDER_MASTERMIND",       // name
		7,		// doomednum
		S_SPID_STND,		// spawnstate
		3000,		// spawnhealth
		S_SPID_RUN1,		// seestate
		sfx_spisit,		// seesound
		8,		// reactiontime
		sfx_shotgn,		// attacksound
		S_SPID_PAIN,		// painstate
		40,		// painchance
		sfx_dmpain,		// painsound
		0,		// meleestate
		S_SPID_ATK1,		// missilestate
		S_SPID_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_spidth,		// deathsound
		12,		// speed
		128*FRACUNIT,		// radius
		100*FRACUNIT,		// height
		1000,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		MBF21_E3M8BOSS | MBF21_E4M8BOSS,  // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BABY
	{
		"ARACHNOTRON",       // name
		68,		// doomednum
		S_BSPI_STND,		// spawnstate
		500,		// spawnhealth
		S_BSPI_SIGHT,		// seestate
		sfx_bspsit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_BSPI_PAIN,		// painstate
		128,		// painchance
		sfx_dmpain,		// painsound
		0,		// meleestate
		S_BSPI_ATK1,		// missilestate
		S_BSPI_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_bspdth,		// deathsound
		12,		// speed
		64*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		600,		// mass
		0,		// damage
		sfx_bspact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		MBF21_MAP07BOSS2, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_BSPI_RAISE1		// raisestate
	},

	// MT_CYBORG
	{
		"THE_CYBERDEMON",       // name
		16,		// doomednum
		S_CYBER_STND,		// spawnstate
		4000,		// spawnhealth
		S_CYBER_RUN1,		// seestate
		sfx_cybsit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_CYBER_PAIN,		// painstate
		20,		// painchance
		sfx_dmpain,		// painsound
		0,		// meleestate
		S_CYBER_ATK1,		// missilestate
		S_CYBER_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_cybdth,		// deathsound
		16,		// speed
		40*FRACUNIT,		// radius
		110*FRACUNIT,		// height
		1000,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		MBF21_E2M8BOSS | MBF21_E4M6BOSS,  // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_PAIN
	{
		"PAIN_ELEMENTAL",       // name
		71,		// doomednum
		S_PAIN_STND,		// spawnstate
		400,		// spawnhealth
		S_PAIN_RUN1,		// seestate
		sfx_pesit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_PAIN_PAIN,		// painstate
		128,		// painchance
		sfx_pepain,		// painsound
		0,		// meleestate
		S_PAIN_ATK1,		// missilestate
		S_PAIN_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_pedth,		// deathsound
		8,		// speed
		31*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		400,		// mass
		0,		// damage
		sfx_dmact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_FLOAT|MF_NOGRAVITY|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_PAIN_RAISE1		// raisestate
	},

	// MT_WOLFSS
	{
		"WOLFENSTEIN_SS",       // name
		84,		// doomednum
		S_SSWV_STND,		// spawnstate
		50,		// spawnhealth
		S_SSWV_RUN1,		// seestate
		sfx_sssit,		// seesound
		8,		// reactiontime
		0,		// attacksound
		S_SSWV_PAIN,		// painstate
		170,		// painchance
		sfx_popain,		// painsound
		0,		// meleestate
		S_SSWV_ATK1,		// missilestate
		S_SSWV_DIE1,		// deathstate
		S_SSWV_XDIE1,		// xdeathstate
		sfx_ssdth,		// deathsound
		8,		// speed
		20*FRACUNIT,		// radius
		56*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_posact,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_SSWV_RAISE1		// raisestate
	},

	// MT_KEEN
	{
		"COMMANDER_KEEN",       // name
		72,		// doomednum
		S_KEENSTND,		// spawnstate
		100,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_KEENPAIN,		// painstate
		256,		// painchance
		sfx_keenpn,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_COMMKEEN,		// deathstate
		S_NULL,		// xdeathstate
		sfx_keendt,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		72*FRACUNIT,		// height
		10000000,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY|MF_SHOOTABLE|MF_COUNTKILL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BOSSBRAIN
	{
		"BOSS_BRAIN",       // name
		88,		// doomednum
		S_BRAIN,		// spawnstate
		250,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_BRAIN_PAIN,		// painstate
		255,		// painchance
		sfx_bospn,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_BRAIN_DIE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_bosdth,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		10000000,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SHOOTABLE,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BOSSSPIT
	{
		"BRAIN_SHOOTER",       // name
		89,		// doomednum
		S_BRAINEYE,		// spawnstate
		1000,		// spawnhealth
		S_BRAINEYESEE,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		32*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOSECTOR,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BOSSTARGET
	{
		"BRAIN_SPAWNSPOT",       // name
		87,		// doomednum
		S_NULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		32*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOSECTOR,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_SPAWNSHOT
	{
		"*BRAIN_CUBE",       // (attack) name
		-1,		// doomednum
		S_SPAWN1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_bospit,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		10*FRACUNIT,		// speed
		6*FRACUNIT,		// radius
		32*FRACUNIT,		// height
		100,		// mass
		3,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY|MF_NOCLIP,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_SPAWNFIRE
	{
		"*SPAWNFIRE",       // name
		-1,		// doomednum
		S_SPAWNFIRE1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BARREL
	{
		"BARREL",       // name
		2035,		// doomednum
		S_BAR1,		// spawnstate
		20,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_BEXP,		// deathstate
		S_NULL,		// xdeathstate
		sfx_barexp,		// deathsound
		0,		// speed
		10*FRACUNIT,		// radius
		42*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SHOOTABLE|MF_NOBLOOD,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_TROOPSHOT
	{
		"*IMP_FIREBALL",       // (attack) name
		-1,		// doomednum
		S_TBALL1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_firsht,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_TBALLX1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		10*FRACUNIT,		// speed
		6*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		3,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_HEADSHOT
	{
		"*CACO_FIREBALL",       // (attack) name
		-1,		// doomednum
		S_RBALL1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_firsht,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_RBALLX1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		10*FRACUNIT,		// speed
		6*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		5,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_ROCKET
	{
		"*CYBERDEMON_MISSILE",       // (attack) name
		-1,		// doomednum
		S_ROCKET,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_rlaunc,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_EXPLODE1,		// deathstate
		S_NULL,		// xdeathstate
		sfx_barexp,		// deathsound
		20*FRACUNIT,		// speed
		11*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		20,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_PLASMA
	{
		"*PLAYER_PLASMA",       // (attack) name
		-1,		// doomednum
		S_PLASBALL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_plasma,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_PLASEXP,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		25*FRACUNIT,		// speed
		13*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		5,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BFG
	{
		"*PLAYER_BFG9000",       // (attack) name
		-1,		// doomednum
		S_BFGSHOT,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		0,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_BFGLAND,		// deathstate
		S_NULL,		// xdeathstate
		sfx_rxplod,		// deathsound
		25*FRACUNIT,		// speed
		13*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		100,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_ARACHPLAZ
	{
		"*ARACHNOTRON_PLASMA",       // name
		-1,		// doomednum
		S_ARACH_PLAZ,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_plasma,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_ARACH_PLEX,		// deathstate
		S_NULL,		// xdeathstate
		sfx_firxpl,		// deathsound
		25*FRACUNIT,		// speed
		13*FRACUNIT,		// radius
		8*FRACUNIT,		// height
		100,		// mass
		5,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_PUFF
	{
		"PUFF",       // name
		-1,		// doomednum
		S_PUFF1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_BLOOD
	{
		"BLOOD",       // name
		-1,		// doomednum
		S_BLOOD1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_TFOG
	{
		"TELEPORT_FOG",       // name
		-1,		// doomednum
		S_TFOG,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_IFOG
	{
		"RESPAWN_FOG",       // name
		-1,		// doomednum
		S_IFOG,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_TELEPORTMAN
	{
		"TELEPORT_FLASH",       // name
		14,		// doomednum
		S_NULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOSECTOR,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_EXTRABFG
	{
		"*BFG9000_SPRAY",       // name
		-1,		// doomednum
		S_BFGEXP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC0
	{
		"GREEN_ARMOUR",       // name
		2018,		// doomednum
		S_ARM1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC1
	{
		"BLUE_ARMOUR",       // name
		2019,		// doomednum
		S_ARM2,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC2
	{
		"HEALTH_POTION",       // name
		2014,		// doomednum
		S_BON1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC3
	{
		"ARMOUR_HELMET",       // name
		2015,		// doomednum
		S_BON2,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC4
	{
		"BLUE_KEY",       // name
		5,		// doomednum
		S_BKEY,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC5
	{
		"RED_KEY",       // name
		13,		// doomednum
		S_RKEY,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC6
	{
		"YELLOW_KEY",       // name
		6,		// doomednum
		S_YKEY,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC7
	{
		"YELLOW_SKULLKEY",       // name
		39,		// doomednum
		S_YSKULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC8
	{
		"RED_SKULLKEY",       // name
		38,		// doomednum
		S_RSKULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC9
	{
		"BLUE_SKULLKEY",       // name
		40,		// doomednum
		S_BSKULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_NOTDMATCH,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC10
	{
		"STIMPACK",       // name
		2011,		// doomednum
		S_STIM,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC11
	{
		"MEDIKIT",       // name
		2012,		// doomednum
		S_MEDI,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC12
	{
		"SOULSPHERE",       // name
		2013,		// doomednum
		S_SOUL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_INV
	{
		"INVULNERABILITY_SPHERE",       // name
		2022,		// doomednum
		S_PINV,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC13
	{
		"BERSERKER",       // name
		2023,		// doomednum
		S_PSTR,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_INS
	{
		"BLURSPHERE",       // name
		2024,		// doomednum
		S_PINS,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC14
	{
		"RADIATION_SUIT",       // name
		2025,		// doomednum
		S_SUIT,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC15
	{
		"AUTOMAP",       // name
		2026,		// doomednum
		S_PMAP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC16
	{
		"LIGHT_SPECS",       // name
		2045,		// doomednum
		S_PVIS,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MEGA
	{
		"MEGASPHERE",       // name
		83,		// doomednum
		S_MEGA,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL|MF_COUNTITEM,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_CLIP
	{
		"CLIP",       // name
		2007,		// doomednum
		S_CLIP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC17
	{
		"BOX_OF_BULLETS",       // name
		2048,		// doomednum
		S_AMMO,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC18
	{
		"ROCKET",       // name
		2010,		// doomednum
		S_ROCK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC19
	{
		"BOX_OF_ROCKETS",       // name
		2046,		// doomednum
		S_BROK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC20
	{
		"CELLS",       // name
		2047,		// doomednum
		S_CELL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC21
	{
		"CELL_PACK",       // name
		17,		// doomednum
		S_CELP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC22
	{
		"SHELLS",       // name
		2008,		// doomednum
		S_SHEL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC23
	{
		"BOX_OF_SHELLS",       // name
		2049,		// doomednum
		S_SBOX,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC24
	{
		"BACKPACK",       // name
		8,		// doomednum
		S_BPAK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC25
	{
		"BFG",       // name
		2006,		// doomednum
		S_BFUG,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_CHAINGUN
	{
		"CHAINGUN",       // name
		2002,		// doomednum
		S_MGUN,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC26
	{
		"CHAINSAW",       // name
		2005,		// doomednum
		S_CSAW,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC27
	{
		"MISSILE_LAUNCHER",       // name
		2003,		// doomednum
		S_LAUN,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC28
	{
		"PLASMA_RIFLE",       // name
		2004,		// doomednum
		S_PLAS,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_SHOTGUN
	{
		"SHOTGUN",       // name
		2001,		// doomednum
		S_SHOT,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_SUPERSHOTGUN
	{
		"SUPER_SHOTGUN",       // name
		82,		// doomednum
		S_SHOT2,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPECIAL,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC29
	{
		"TALL_TECH_LAMP",       // name
		85,		// doomednum
		S_TECHLAMP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC30
	{
		"SMALL_TECH_LAMP",       // name
		86,		// doomednum
		S_TECH2LAMP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC31
	{
		"SMALL_BOLLARD_LAMP",       // name
		2028,		// doomednum
		S_COLU,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC32
	{
		"TALL_GREEN_COLUMN",       // name
		30,		// doomednum
		S_TALLGRNCOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC33
	{
		"SHORT_GREEN_COLUMN",       // name
		31,		// doomednum
		S_SHRTGRNCOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC34
	{
		"TALL_RED_COLUMN",       // name
		32,		// doomednum
		S_TALLREDCOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC35
	{
		"SHORT_RED_COLUMN",       // name
		33,		// doomednum
		S_SHRTREDCOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC36
	{
		"SKULL_ON_COLUMN",       // name
		37,		// doomednum
		S_SKULLCOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC37
	{
		"BEATING_HEART_COLUMN",       // name
		36,		// doomednum
		S_HEARTCOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC38
	{
		"EYE_SYMBOL",       // name
		41,		// doomednum
		S_EVILEYE,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC39
	{
		"FLOATING_SKULLROCK",       // name
		42,		// doomednum
		S_FLOATSKULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC40
	{
		"TORCHED_TREE",       // name
		43,		// doomednum
		S_TORCHTREE,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC41
	{
		"BRONZE_BLUE_TORCH",       // name
		44,		// doomednum
		S_BLUETORCH,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC42
	{
		"BRONZE_GREEN_TORCH",       // name
		45,		// doomednum
		S_GREENTORCH,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC43
	{
		"BRONZE_RED_TORCH",       // name
		46,		// doomednum
		S_REDTORCH,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC44
	{
		"WOODEN_BLUE_TORCH",       // name
		55,		// doomednum
		S_BTORCHSHRT,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC45
	{
		"WOODEN_GREEN_TORCH",       // name
		56,		// doomednum
		S_GTORCHSHRT,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC46
	{
		"WOODEN_RED_TORCH",       // name
		57,		// doomednum
		S_RTORCHSHRT,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC47
	{
		"SPIKY_STUMP",       // name
		47,		// doomednum
		S_STALAGTITE,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC48
	{
		"TECHNOCOLUMN",       // name
		48,		// doomednum
		S_TECHPILLAR,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC49
	{
		"BLACK_CANDLE",       // name
		34,		// doomednum
		S_CANDLESTIK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC50
	{
		"CANDELABRA",       // name
		35,		// doomednum
		S_CANDELABRA,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC51
	{
		"TWITCHING_BLOKE_I",       // name
		49,		// doomednum
		S_BLOODYTWITCH,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		68*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC52
	{
		"HANGING_DEAD_BLOKE_I",       // name
		50,		// doomednum
		S_MEAT2,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		84*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC53
	{
		"HANGING_DEAD_BLOKE_II",       // name
		51,		// doomednum
		S_MEAT3,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		84*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC54
	{
		"HANGING_DEAD_BLOKE_III",       // name
		52,		// doomednum
		S_MEAT4,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		68*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC55
	{
		"HANGING_DEAD_BLOKE_IV",       // name
		53,		// doomednum
		S_MEAT5,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		52*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC56
	{
		"HANGING_DEAD_BLOKE_V",       // name
		59,		// doomednum
		S_MEAT2,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		84*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC57
	{
		"HANGING_DEAD_BLOKE_VI",       // name
		60,		// doomednum
		S_MEAT4,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		68*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC58
	{
		"HANGING_DEAD_BLOKE_VII",       // name
		61,		// doomednum
		S_MEAT3,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		52*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC59
	{
		"HANGING_DEAD_BLOKE_VIII",       // name
		62,		// doomednum
		S_MEAT5,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		52*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC60
	{
		"TWITCHING_BLOKE_II",       // name
		63,		// doomednum
		S_BLOODYTWITCH,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		68*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC61
	{
		"DEAD_CACODEMON",       // name
		22,		// doomednum
		S_HEAD_DIE6,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC62
	{
		"DEAD_PLAYER",       // name
		15,		// doomednum
		S_PLAY_DIE7,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC63
	{
		"DEAD_FORMER_HUMAN",       // name
		18,		// doomednum
		S_POSS_DIE5,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC64
	{
		"DEAD_DEMON",       // name
		21,		// doomednum
		S_SARG_DIE6,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC65
	{
		"DEAD_LOSTSOUL",       // name
		23,		// doomednum
		S_SKULL_DIE6,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC66
	{
		"DEAD_IMP",       // name
		20,		// doomednum
		S_TROO_DIE5,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC67
	{
		"DEAD_FORMER_SARG",       // name
		19,		// doomednum
		S_SPOS_DIE5,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC68
	{
		"DEAD_GIBBER_PLAYER1",       // name
		10,		// doomednum
		S_PLAY_XDIE9,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC69
	{
		"DEAD_GIBBED_PLAYER2",       // name
		12,		// doomednum
		S_PLAY_XDIE9,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC70
	{
		"HEADS_ON_A_STICK",       // name
		28,		// doomednum
		S_HEADSONSTICK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC71
	{
		"POOL_OF_BLOOD",       // name
		24,		// doomednum
		S_GIBS,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		0,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC72
	{
		"SKULL_ON_A_STICK",       // name
		27,		// doomednum
		S_HEADONASTICK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC73
	{
		"SKULL_CENTREPIECE",       // name
		29,		// doomednum
		S_HEADCANDLES,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC74
	{
		"SKEWERED_BLOKE",       // name
		25,		// doomednum
		S_DEADSTICK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC75
	{
		"DYING_SKEWERED_BLOKE",       // name
		26,		// doomednum
		S_LIVESTICK,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC76
	{
		"BIG_TREE",       // name
		54,		// doomednum
		S_BIGTREE,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		32*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC77
	{
		"BURNING_BARREL",       // name
		70,		// doomednum
		S_BBAR1,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC78
	{
		"GUTTED_HUNG_BLOKE_I",       // name
		73,		// doomednum
		S_HANGNOGUTS,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		88*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC79
	{
		"GUTTED_HUNG_BLOKE_II",       // name
		74,		// doomednum
		S_HANGBNOBRAIN,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		88*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC80
	{
		"GUTTED_TORSO_I",       // name
		75,		// doomednum
		S_HANGTLOOKDN,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC81
	{
		"GUTTED_TORSO_II",       // name
		76,		// doomednum
		S_HANGTSKULL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC82
	{
		"GUTTED_TORSO_III",       // name
		77,		// doomednum
		S_HANGTLOOKUP,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC83
	{
		"GUTTED_TORSO_IV",       // name
		78,		// doomednum
		S_HANGTNOBRAIN,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		16*FRACUNIT,		// radius
		64*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_SOLID|MF_SPAWNCEILING|MF_NOGRAVITY,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC84
	{
		"POOL_OF_BLOOD_I",       // name
		79,		// doomednum
		S_COLONGIBS,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC85
	{
		"POOL_OF_BLOOD_II",       // name
		80,		// doomednum
		S_SMALLPOOL,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// MT_MISC86
	{
		"BRAINSTEM",       // name
		81,		// doomednum
		S_BRAINSTEM,		// spawnstate
		1000,		// spawnhealth
		S_NULL,		// seestate
		sfx_None,		// seesound
		8,		// reactiontime
		sfx_None,		// attacksound
		S_NULL,		// painstate
		0,		// painchance
		sfx_None,		// painsound
		S_NULL,		// meleestate
		S_NULL,		// missilestate
		S_NULL,		// deathstate
		S_NULL,		// xdeathstate
		sfx_None,		// deathsound
		0,		// speed
		20*FRACUNIT,		// radius
		16*FRACUNIT,		// height
		100,		// mass
		0,		// damage
		sfx_None,		// activesound
		MF_NOBLOCKMAP,		// flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL		// raisestate
	},

	// ============= BOOM and MBF things =============

	// MT_PUSH
	{
		"POINT_PUSHER",       // name
		5001,           // doomednum
		S_TNT1,         // spawnstate
		1000,           // spawnhealth
		S_NULL,         // seestate
		sfx_None,       // seesound
		8,              // reactiontime
		sfx_None,       // attacksound
		S_NULL,         // painstate
		0,              // painchance
		sfx_None,       // painsound
		S_NULL,         // meleestate
		S_NULL,         // missilestate
		S_NULL,         // deathstate
		S_NULL,         // xdeathstate
		sfx_None,       // deathsound
		0,              // speed
		FRACUNIT/8,     // radius   /* MOD */
		FRACUNIT/8,     // height   /* MOD */
		10,             // mass
		0,              // damage
		sfx_None,       // activesound
		MF_NOBLOCKMAP,  // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL          // raisestate
	},

	// MT_PULL
	{
		"POINT_PULLER",       // name
		5002,           // doomednum
		S_TNT1,         // spawnstate
		1000,           // spawnhealth
		S_NULL,         // seestate
		sfx_None,       // seesound
		8,              // reactiontime
		sfx_None,       // attacksound
		S_NULL,         // painstate
		0,              // painchance
		sfx_None,       // painsound
		S_NULL,         // meleestate
		S_NULL,         // missilestate
		S_NULL,         // deathstate
		S_NULL,         // xdeathstate
		sfx_None,       // deathsound
		0,              // speed
		FRACUNIT/8,     // radius   /* MOD */
		FRACUNIT/8,     // height   /* MOD */
		10,             // mass
		0,              // damage
		sfx_None,       // activesound
		MF_NOBLOCKMAP,  // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL          // raisestate
	},

	// Marine's best friend :)      // killough 7/19/98

	// MT_DOGS
	{
		"DOG",       // name
		888,   // doomednum
		S_DOGS_STND,    // spawnstate
		500,    // spawnhealth
		S_DOGS_RUN1,    // seestate
		sfx_dgsit,   // seesound
		8,    // reactiontime
		sfx_dgatk,   // attacksound
		S_DOGS_PAIN,    // painstate
		180,    // painchance
		sfx_dgpain,   // painsound
		S_DOGS_ATK1,    // meleestate
		0,    // missilestate
		S_DOGS_DIE1,    // deathstate
		S_NULL,   // xdeathstate
		sfx_dgdth,   // deathsound
		10,   // speed
		12*FRACUNIT,    // radius
		28*FRACUNIT,    // height
		100,    // mass
		0,    // damage
		sfx_dgact,    // activesound
		MF_SOLID|MF_SHOOTABLE|MF_COUNTKILL, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_DOGS_RAISE1   // raisestate
	},

	// MT_PLASMA1
	{
		"BETA_PLASMA_1",       // name
		-1,   // doomednum
		S_PLS1BALL,    // spawnstate
		1000,    // spawnhealth
		S_NULL,    // seestate
		sfx_plasma,   // seesound
		8,    // reactiontime
		sfx_None,   // attacksound
		S_NULL,    // painstate
		0,    // painchance
		sfx_None,   // painsound
		S_NULL,    // meleestate
		0,    // missilestate
		S_PLS1EXP,    // deathstate
		S_NULL,   // xdeathstate
		sfx_firxpl,   // deathsound
		25*FRACUNIT,   // speed
		13*FRACUNIT,    // radius
		8*FRACUNIT,    // height
		100,    // mass
		4,    // damage
		sfx_None,    // activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_BOUNCES, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL   // raisestate
	},

	// MT_PLASMA2
	{
		"BETA_PLASMA_2",       // name
		-1,   // doomednum
		S_PLS2BALL,    // spawnstate
		1000,    // spawnhealth
		S_NULL,    // seestate
		sfx_plasma,   // seesound
		8,    // reactiontime
		sfx_None,   // attacksound
		S_NULL,    // painstate
		0,    // painchance
		sfx_None,   // painsound
		S_NULL,    // meleestate
		0,    // missilestate
		S_PLS2BALLX1,    // deathstate
		S_NULL,   // xdeathstate
		sfx_firxpl,   // deathsound
		25*FRACUNIT,   // speed
		6*FRACUNIT,    // radius
		8*FRACUNIT,    // height
		100,    // mass
		4,    // damage
		sfx_None,    // activesound
		MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_BOUNCES, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL   // raisestate
	},

	// MT_SCEPTRE
	{
		"BETA_SCEPTRE",       // name
		2016,   // doomednum
		S_BON3,    // spawnstate
		1000,    // spawnhealth
		S_NULL,    // seestate
		sfx_None,   // seesound
		8,    // reactiontime
		sfx_None,   // attacksound
		S_NULL,    // painstate
		0,    // painchance
		sfx_None,   // painsound
		S_NULL,    // meleestate
		0,    // missilestate
		S_NULL,    // deathstate
		S_NULL,   // xdeathstate
		sfx_None,   // deathsound
		0,   // speed
		10*FRACUNIT,    // radius
		16*FRACUNIT,    // height
		100,    // mass
		0,    // damage
		sfx_None,    // activesound
		MF_SPECIAL|MF_COUNTITEM, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL   // raisestate
	},

	// MT_BIBLE
	{
		"BETA_BIBLE",       // name
		2017,   // doomednum
		S_BON4,    // spawnstate
		1000,    // spawnhealth
		S_NULL,    // seestate
		sfx_None,   // seesound
		8,    // reactiontime
		sfx_None,   // attacksound
		S_NULL,    // painstate
		0,    // painchance
		sfx_None,   // painsound
		S_NULL,    // meleestate
		0,    // missilestate
		S_NULL,    // deathstate
		S_NULL,   // xdeathstate
		sfx_None,   // deathsound
		0,   // speed
		20*FRACUNIT,    // radius
		10*FRACUNIT,    // height
		100,    // mass
		0,    // damage
		sfx_None,    // activesound
		MF_SPECIAL|MF_COUNTITEM, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL   // raisestate
	},

	// MT_MUSICSOURCE
	{
		"MUSIC_SOURCE",       // name
		14164,   // doomednum ....not sure what to put here yet - Dasho
		S_TNT1,    // spawnstate
		1000,    // spawnhealth
		S_NULL,    // seestate
		sfx_None,   // seesound
		8,    // reactiontime
		sfx_None,   // attacksound
		S_NULL,    // painstate
		0,    // painchance
		sfx_None,   // painsound
		S_NULL,    // meleestate
		0,    // missilestate
		S_NULL,    // deathstate
		S_NULL,   // xdeathstate
		sfx_None,   // deathsound
		0,   // speed
		16,    // radius
		16,    // height
		100,    // mass
		0,    // damage
		sfx_None,    // activesound
		MF_NOBLOCKMAP, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL   // raisestate
	},

	// MT_GIBDTH
	{
		"GIB_DEATH",       // name
		-1,   // doomednum
		S_TNT1,    // spawnstate
		1000,    // spawnhealth
		S_NULL,    // seestate
		sfx_None,   // seesound
		8,    // reactiontime
		sfx_None,   // attacksound
		S_NULL,    // painstate
		0,    // painchance
		sfx_None,   // painsound
		S_NULL,    // meleestate
		0,    // missilestate
		S_NULL,    // deathstate
		S_NULL,   // xdeathstate
		sfx_None,   // deathsound
		0,   // speed
		4*FRACUNIT,    // radius
		4*FRACUNIT,    // height
		100,    // mass
		0,    // damage
		sfx_None,    // activesound
		MF_NOBLOCKMAP|MF_DROPOFF, // flags
		0, // MBF21 flags
		-2, // Infighting group
		-2, // Projectile group
		-2, // Splash group
		sfx_None, // Rip sound
		0, // Fast speed
		0, // Melee range
		S_NULL   // raisestate
	},
};


mobjinfo_t brain_explode_mobj =
{
	"BRAIN_DEATH_MISSILE",       // name
	-1,		// doomednum
	S_BRAINEXPLODE1,	// spawnstate
	1000,		// spawnhealth
	S_NULL,		// seestate
	sfx_rlaunc,		// seesound
	8,		// reactiontime
	sfx_None,		// attacksound
	S_NULL,		// painstate
	0,		// painchance
	sfx_None,		// painsound
	S_NULL,		// meleestate
	S_NULL,		// missilestate
	S_NULL,		// deathstate
	S_NULL,		// xdeathstate
	sfx_barexp,		// deathsound
	20*FRACUNIT,		// speed
	11*FRACUNIT,		// radius
	8*FRACUNIT,		// height
	100,		// mass
	128,		// damage
	sfx_None,		// activesound
	MF_NOBLOCKMAP|MF_MISSILE|MF_DROPOFF|MF_NOGRAVITY,		// flags
	0, // MBF21 flags
	-2, // Infighting group
	-2, // Projectile group
	-2, // Splash group
	sfx_None, // Rip sound
	0, // Fast speed
	0, // Melee range
	S_NULL		// raisestate
};

}  // Deh_Edge
