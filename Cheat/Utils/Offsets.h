#pragma once
#include "../../Utils/Utils.h"
#include "../../Utils/Obfuscation//Obfuscate.h"

namespace Offsets {
	inline uintptr_t String2Offset(const char* c) {
		int base = 16;
		// See if this function catches all possibilities.
		// If it doesn't, the function would have to be amended
		// whenever you add a combination of architecture and
		// compiler that is not yet addressed.
		static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
			|| sizeof(uintptr_t) == sizeof(unsigned long long),
			"");

		// Now choose the correct function ...
		if (sizeof(uintptr_t) == sizeof(unsigned long)) {
			return strtoul(c, nullptr, base);
		}

		// All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
		return strtoull(c, nullptr, base);
	}

	inline uintptr_t TimeOffset = String2Offset(OBFUSCATE("0x0"));
	inline uintptr_t IsDebugBuild = String2Offset(OBFUSCATE("0x0"));
	inline uintptr_t PlayerMoveCUpdate = String2Offset(OBFUSCATE("0x1B61D20"));
	inline uintptr_t WeaponSoundsUpdate = String2Offset(OBFUSCATE("0x7EF390"));
	inline uintptr_t XRay = String2Offset(OBFUSCATE("0x1AF82B0"));
	inline uintptr_t NextHitCritical = String2Offset(OBFUSCATE("0x7E84E0"));
	inline uintptr_t AddHealthFromWeaponOnline = String2Offset(OBFUSCATE("0x1AA6220"));
	inline uintptr_t AddAmmoFromWeaponOnline = String2Offset(OBFUSCATE("0x1AA6090"));
	inline uintptr_t Invisibility = String2Offset(OBFUSCATE("0x1ABF8D0"));
	inline uintptr_t SpeedModifier = String2Offset(OBFUSCATE("0x774D40"));
	inline uintptr_t MovePlayer = String2Offset(OBFUSCATE("0x43C5CB0"));
	inline uintptr_t JetpackFly = String2Offset(OBFUSCATE("0x1B17E60"));
}