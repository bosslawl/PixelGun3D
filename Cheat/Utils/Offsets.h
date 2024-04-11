#pragma once
#include "../../Utils/Utils.h"
#include "../../Utils/Obfuscation//Obfuscate.h"

namespace Offsets {
	inline uintptr_t String2Offset(const char* c) {
		int base = 16;
		static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
			|| sizeof(uintptr_t) == sizeof(unsigned long long),
			"");

		if (sizeof(uintptr_t) == sizeof(unsigned long)) {
			return strtoul(c, nullptr, base);
		}

		return strtoull(c, nullptr, base);
	}

	inline uintptr_t IsDebugBuild = String2Offset(OBFUSCATE("0x0"));
	inline uintptr_t TimeOffset = String2Offset(OBFUSCATE("0x0"));
	inline uintptr_t ACOne = String2Offset(OBFUSCATE("0xB1EDF0")); // DataSystem.DataValidiation.GClass264 .cctor
	inline uintptr_t ACTwo = String2Offset(OBFUSCATE("0xB1AF00")); // DataSystem.DataValidation.FluentValidators.Class2536 .ctor
	inline uintptr_t ACThree = String2Offset(OBFUSCATE("0x6FDBE0")); // DveeloperConsoleController HandleBanUs
	inline uintptr_t ACFour = String2Offset(OBFUSCATE("0xB38D90")); // GamePauseController method_3
	inline uintptr_t ACFive = String2Offset(OBFUSCATE("0xBB0960")); // Rilisoft.GClass317 smethod_66
	inline uintptr_t ACSix = String2Offset(OBFUSCATE("0xBAFED0")); // Rilisoft.GClass317 smethod_67
	inline uintptr_t ACSeven = String2Offset(OBFUSCATE("0xBAC620")); // Rilisoft.GClass317 smethod_71
	inline uintptr_t ACEight = String2Offset(OBFUSCATE("0xBC27E0")); // Rilisoft.GClass317 smethod_76
	inline uintptr_t ACNine = String2Offset(OBFUSCATE("0xBB29A0")); // Rilisoft.GClass317 smethod_131
	inline uintptr_t ACTen = String2Offset(OBFUSCATE("0xBAF2D0")); // Rilisoft.GClass317 smethod_157
	inline uintptr_t ACEleven = String2Offset(OBFUSCATE("0xBB2900")); // Rilisoft.GClass317 smethod_158
	inline uintptr_t ACTwelve = String2Offset(OBFUSCATE("0xBC73E0")); // Rilisoft.GClass317 smethod_175
	inline uintptr_t ACThirteen = String2Offset(OBFUSCATE("0xBC38D0")); // Rilisoft.GClass317 smethod_176
	inline uintptr_t ACFourteen = String2Offset(OBFUSCATE("0xBB62D0"));	// Rilisoft.GClass317 smethod_201
	inline uintptr_t ACFifteen = String2Offset(OBFUSCATE("0xBAE2B0")); // Rilisoft.GClass317 smethod_61
	inline uintptr_t ACSixteen = String2Offset(OBFUSCATE("0xBA8910")); // Rilisoft.GClass317 smethod_129
	inline uintptr_t ACSeventeen = String2Offset(OBFUSCATE("0xBC74B0")); // Rilisoft.GClass317 smethod_180
	inline uintptr_t ACEighteen = String2Offset(OBFUSCATE("0xBB6BA0")); // Rilisoft.GClass317 smethod_190
	inline uintptr_t ACNineteen = String2Offset(OBFUSCATE("0xBBFC00")); // Rilisoft.GClass317 smethod_227
	inline uintptr_t ACTwenty = String2Offset(OBFUSCATE("0xBADD70")); // Rilisoft.GClass317 smethod_16
	inline uintptr_t ACTwentyOne = String2Offset(OBFUSCATE("0xBC4620")); // Rilisoft.GClass317 smethod_17
	inline uintptr_t ACTwentyTwo = String2Offset(OBFUSCATE("0xBA9DD0")); // Rilisoft.GClass317 smethod_42
	inline uintptr_t ACTwentyThree = String2Offset(OBFUSCATE("0xBB4C40")); // ?
	inline uintptr_t ACTwentyFour = String2Offset(OBFUSCATE("0xBBC930")); // Rilisoft.GClass317 smethod_69
	inline uintptr_t ACTwentyFive = String2Offset(OBFUSCATE("0xBACE80")); // Rilisoft.GClass317 smethod_24
	inline uintptr_t ACTwentySix = String2Offset(OBFUSCATE("0xBAC620")); // Rilisoft.GClass317 smethod_71
	inline uintptr_t ACTwentySeven = String2Offset(OBFUSCATE("0xBB7FD0")); // Rilisoft.GClass317 smethod_73
	inline uintptr_t ACTwentyEight = String2Offset(OBFUSCATE("0xBB2FE0")); // Rilisoft.GClass317 smethod_27
	inline uintptr_t ACTwentyNine = String2Offset(OBFUSCATE("0xBA4490")); // Rilisoft.GClass317 smethod_74
	inline uintptr_t ACThirty = String2Offset(OBFUSCATE("0xBC1110")); // Rilisoft.GClass317 smethod_75
	inline uintptr_t ACThirtyOne = String2Offset(OBFUSCATE("0xBB20A0")); // Rilisoft.GClass317 smethod_77
	inline uintptr_t ACThirtyTwo = String2Offset(OBFUSCATE("0xBAB520")); // Rilisoft.GClass317 smethod_88
	inline uintptr_t ACThirtyThree = String2Offset(OBFUSCATE("0xBB1B80")); // Rilisoft.GClass317 smethod_89
	inline uintptr_t ACThirtyFour = String2Offset(OBFUSCATE("0xBB4940")); // Rilisoft.GClass317 smethod_103
	inline uintptr_t ACThirtyFive = String2Offset(OBFUSCATE("0xBB7440")); // Rilisoft.GClass317 smethod_130
	inline uintptr_t ACThirtySix = String2Offset(OBFUSCATE("0xBB29A0")); // Rilisoft.GClass317 smethod_131
	inline uintptr_t ACThirtySeven = String2Offset(OBFUSCATE("0xBA8C80")); // Rilisoft.GClass317 smethod_36
	inline uintptr_t ACThirtyEight = String2Offset(OBFUSCATE("0xBAB9A0")); // Rilisoft.GClass317 smethod_143
	inline uintptr_t ACThirtyNine = String2Offset(OBFUSCATE("0xBA78A0")); // Rilisoft.GClass317 smethod_39
	inline uintptr_t ACFourty = String2Offset(OBFUSCATE("0xBBE400")); // Rilisoft.GClass317 smethod_40
	inline uintptr_t ACFourtyOne = String2Offset(OBFUSCATE("0xBA6650")); // Rilisoft.GClass317 smethod_41
	inline uintptr_t ACFourtyTwo = String2Offset(OBFUSCATE("0xBA9DD0")); // Rilisoft.GClass317 smethod_42
	inline uintptr_t ACFourtyThree = String2Offset(OBFUSCATE("0xBC3EE0")); // Rilisoft.GClass317 smethod_43
	inline uintptr_t PlayerMoveCUpdate = String2Offset(OBFUSCATE("0x1B61D20")); // Player_move_c Update
	inline uintptr_t WeaponSoundsUpdate = String2Offset(OBFUSCATE("0x7EF390")); // WeaponSounds Update
	inline uintptr_t PetEngineUpdate = String2Offset(OBFUSCATE("0xDDB840")); // Rilisoft.PetEngine Update
	inline uintptr_t XRay = String2Offset(OBFUSCATE("0x1AF82B0")); // Player_move_c method_205
	inline uintptr_t NextHitCritical = String2Offset(OBFUSCATE("0x7E84E0"));// WeaponSounds SetNextHitCritical
	inline uintptr_t Invisibility = String2Offset(OBFUSCATE("0x1ABF8D0")); // Player_move_c MakeInvisibleForSeconds
	inline uintptr_t SpeedModifier = String2Offset(OBFUSCATE("0x774D40")); // ItemRecord get_SpeedModifier
	inline uintptr_t JetpackFly = String2Offset(OBFUSCATE("0x1B17E60")); // Player_move_c method_159
	inline uintptr_t GodmodeOne = String2Offset(OBFUSCATE("0x1AF9130")); // Player_move_c method_451
	inline uintptr_t GodmodeTwo = String2Offset(OBFUSCATE("0x217C6C0")); // GClass147 method_16
	inline uintptr_t InfiniteGems = String2Offset(OBFUSCATE("0x4BB8D0")); // Class9 smethod_6
	inline uintptr_t ReloadModifier = String2Offset(OBFUSCATE("0x72CC90")); // Class1837 smethod_13
	inline uintptr_t GadgetCooldown = String2Offset(OBFUSCATE("0x1E846F0")); // Class835 get_Single_2
	inline uintptr_t PetHealth = String2Offset(OBFUSCATE("0xDD5F90")); // PetEngine method_37
	inline uintptr_t PetDamage = String2Offset(OBFUSCATE("0x213A620")); // PetInfo get_Attack
	inline uintptr_t PetSpeed = String2Offset(OBFUSCATE("0x213AAB0")); // PetInfo get_SpeedModif
	inline uintptr_t Lottery = String2Offset(OBFUSCATE("0x783EA0")); // Class1877 get_Int32_0
	inline uintptr_t FireRate = String2Offset(OBFUSCATE("0x113B040")); // BalanceController smethod_82
	inline uintptr_t MaxLevelOne = String2Offset(OBFUSCATE("0x7531F0")); // ExperienceController get_Int32_0
	inline uintptr_t MaxLevelTwo = String2Offset(OBFUSCATE("0x753FA0")); // ExperienceController get_Int32_1
}