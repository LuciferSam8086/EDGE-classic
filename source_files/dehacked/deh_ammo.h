//------------------------------------------------------------------------
//  AMMO Handling
//------------------------------------------------------------------------
// 
//  DEH_EDGE  Copyright (C) 2004-2005  The EDGE Team
// 
//  This program is under the GNU General Public License.
//  It comes WITHOUT ANY WARRANTY of any kind.
//  See COPYING.txt for the full details.
//
//------------------------------------------------------------------------

#ifndef __DEH_AMMO_HDR__
#define __DEH_AMMO_HDR__

namespace Deh_Edge
{

// Ammunition types defined.
typedef enum
{
	am_bullet,    // Pistol / chaingun ammo.
	am_shell,     // Shotgun / double barreled shotgun.
	am_cell,      // Plasma rifle, BFG.
	am_rocket,    // Missile launcher.

	am_unused,	  // Not used

	am_noammo,     // Fist / chainsaw
	NUMAMMO
}
ammotype_e;

namespace Ammo
{
	extern int plr_max[4];
	extern int pickups[4];

	void Init();
	void Shutdown();

	void MarkAmmo(int a_num);
	void AmmoDependencies();

	const char *GetAmmo(int type);

	void AlterAmmo(int new_val);
}

}  // Deh_Edge

#endif /* __DEH_AMMO_HDR__ */
