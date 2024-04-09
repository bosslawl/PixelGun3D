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

	inline uintptr_t IsDebugBuild = String2Offset(OBFUSCATE("0x0"));
	inline uintptr_t ACOne = String2Offset(OBFUSCATE("0xB1EDF0"));
	inline uintptr_t ACTwo = String2Offset(OBFUSCATE("0xB1AF00"));
	inline uintptr_t ACThree = String2Offset(OBFUSCATE("0x6FDBE0"));
	inline uintptr_t TimeOffset = String2Offset(OBFUSCATE("0x0"));
	inline uintptr_t PlayerMoveCUpdate = String2Offset(OBFUSCATE("0x1B61D20"));
	inline uintptr_t WeaponSoundsUpdate = String2Offset(OBFUSCATE("0x7EF390"));
	inline uintptr_t PetEngineUpdate = String2Offset(OBFUSCATE("0xDDB840"));
	inline uintptr_t XRay = String2Offset(OBFUSCATE("0x1AF82B0"));
	inline uintptr_t NextHitCritical = String2Offset(OBFUSCATE("0x7E84E0"));
	inline uintptr_t Invisibility = String2Offset(OBFUSCATE("0x1ABF8D0"));
	inline uintptr_t SpeedModifier = String2Offset(OBFUSCATE("0x774D40"));
	inline uintptr_t MovePlayer = String2Offset(OBFUSCATE("0x43C5CB0"));
	inline uintptr_t JetpackFly = String2Offset(OBFUSCATE("0x1B17E60"));
	inline uintptr_t GodmodeOne = String2Offset(OBFUSCATE("0x1AF9130"));
	inline uintptr_t GodmodeTwo = String2Offset(OBFUSCATE("0x217C6C0"));
	inline uintptr_t InfiniteGems = String2Offset(OBFUSCATE("0x4BB8D0"));
	inline uintptr_t NoReload = String2Offset(OBFUSCATE("0x72CC90"));
	inline uintptr_t GadgetCooldown = String2Offset(OBFUSCATE("0x1E846F0"));
	inline uintptr_t PetHealth = String2Offset(OBFUSCATE("0xDD5F90"));
	inline uintptr_t PetDamage = String2Offset(OBFUSCATE("0x213A620"));
	inline uintptr_t PetSpeed = String2Offset(OBFUSCATE("0x213AAB0"));
}