#pragma once
#include "../../Utils/Utils.h"
#include "../../Utils/Obfuscation//Obfuscate.h"

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

namespace Offsets {
	// UnityEngine
	namespace UnityEngine {
		inline uintptr_t IsDebugBuild = String2Offset(OBFUSCATE("0x0"));
		inline uintptr_t TimeOffset = String2Offset(OBFUSCATE("0x0"));
		inline uintptr_t TextMesh = String2Offset(OBFUSCATE("0x0"));
		inline uintptr_t StringOffset = String2Offset(OBFUSCATE("0x37C38D0")); // string.Ctor
		inline uintptr_t PreRender = String2Offset(OBFUSCATE("0x42D0540")); // PostProcessLayer OnPreRender
	}

#	// Anticheat bypass
	namespace ACBypass {
		inline uintptr_t ACOne = String2Offset(OBFUSCATE("0xB16E90")); // DataSystem.DataValidiation.GClass264 smethod_0
		inline uintptr_t ACTwo = String2Offset(OBFUSCATE("0xB18F10")); // DataSystem.DataValidation.FluentValidators.Class2536 .ctor
		inline uintptr_t ACThree = String2Offset(OBFUSCATE("0x6FE690")); // DveeloperConsoleController HandleBanUs
		inline uintptr_t ACFour = String2Offset(OBFUSCATE("0x45D440")); // GamePauseController method_3
		inline uintptr_t ACFive = String2Offset(OBFUSCATE("0xBAFE60")); // Rilisoft.GClass317 smethod_66
		inline uintptr_t ACSix = String2Offset(OBFUSCATE("0xBC7AA0")); // Rilisoft.GClass317 smethod_67
		inline uintptr_t ACSeven = String2Offset(OBFUSCATE("0xBC7370")); // Rilisoft.GClass317 smethod_71
		inline uintptr_t ACEight = String2Offset(OBFUSCATE("0xBA7F60")); // Rilisoft.GClass317 smethod_76
		inline uintptr_t ACNine = String2Offset(OBFUSCATE("0xBBEEB0")); // Rilisoft.GClass317 smethod_131
		inline uintptr_t ACTen = String2Offset(OBFUSCATE("0xBC8640")); // Rilisoft.GClass317 smethod_157
		inline uintptr_t ACEleven = String2Offset(OBFUSCATE("0xBBC220")); // Rilisoft.GClass317 smethod_158
		inline uintptr_t ACTwelve = String2Offset(OBFUSCATE("0xBC1660")); // Rilisoft.GClass317 smethod_175
		inline uintptr_t ACThirteen = String2Offset(OBFUSCATE("0xBB25B0")); // Rilisoft.GClass317 smethod_176
		inline uintptr_t ACFourteen = String2Offset(OBFUSCATE("0xBC56D0"));	// Rilisoft.GClass317 smethod_201
		inline uintptr_t ACFifteen = String2Offset(OBFUSCATE("0xBA89D0")); // Rilisoft.GClass317 smethod_61
		inline uintptr_t ACSixteen = String2Offset(OBFUSCATE("0xBA5ED0")); // Rilisoft.GClass317 smethod_129
		inline uintptr_t ACSeventeen = String2Offset(OBFUSCATE("0xBC1470")); // Rilisoft.GClass317 smethod_180
		inline uintptr_t ACEighteen = String2Offset(OBFUSCATE("0xBC87C0")); // Rilisoft.GClass317 smethod_190
		inline uintptr_t ACNineteen = String2Offset(OBFUSCATE("0xBB80C0")); // Rilisoft.GClass317 smethod_227
		inline uintptr_t ACTwenty = String2Offset(OBFUSCATE("0xBB9D40")); // Rilisoft.GClass317 smethod_16
		inline uintptr_t ACTwentyOne = String2Offset(OBFUSCATE("0xBC00D0")); // Rilisoft.GClass317 smethod_17
		inline uintptr_t ACTwentyTwo = String2Offset(OBFUSCATE("0xBBC9D0")); // Rilisoft.GClass317 smethod_42
		inline uintptr_t ACTwentyThree = String2Offset(OBFUSCATE("0xBB4C40")); // ?
		inline uintptr_t ACTwentyFour = String2Offset(OBFUSCATE("0xBBB3E0")); // Rilisoft.GClass317 smethod_69
		inline uintptr_t ACTwentyFive = String2Offset(OBFUSCATE("0xBA9010")); // Rilisoft.GClass317 smethod_24
		inline uintptr_t ACTwentySix = String2Offset(OBFUSCATE("0xBC7370")); // Rilisoft.GClass317 smethod_71
		inline uintptr_t ACTwentySeven = String2Offset(OBFUSCATE("0xBBE5C0")); // Rilisoft.GClass317 smethod_73
		inline uintptr_t ACTwentyEight = String2Offset(OBFUSCATE("0xBBA210")); // Rilisoft.GClass317 smethod_27
		inline uintptr_t ACTwentyNine = String2Offset(OBFUSCATE("0xBC9150")); // Rilisoft.GClass317 smethod_74
		inline uintptr_t ACThirty = String2Offset(OBFUSCATE("0xBC4B60")); // Rilisoft.GClass317 smethod_75
		inline uintptr_t ACThirtyOne = String2Offset(OBFUSCATE("0xBAE020")); // Rilisoft.GClass317 smethod_77
		inline uintptr_t ACThirtyTwo = String2Offset(OBFUSCATE("0xBB5070")); // Rilisoft.GClass317 smethod_88
		inline uintptr_t ACThirtyThree = String2Offset(OBFUSCATE("0xBB5DF0")); // Rilisoft.GClass317 smethod_89
		inline uintptr_t ACThirtyFour = String2Offset(OBFUSCATE("0xBB2250")); // Rilisoft.GClass317 smethod_103
		inline uintptr_t ACThirtyFive = String2Offset(OBFUSCATE("0xBC06C0")); // Rilisoft.GClass317 smethod_130
		inline uintptr_t ACThirtySix = String2Offset(OBFUSCATE("0xBBEEB0")); // Rilisoft.GClass317 smethod_131
		inline uintptr_t ACThirtySeven = String2Offset(OBFUSCATE("0xBB1F90")); // Rilisoft.GClass317 smethod_36
		inline uintptr_t ACThirtyEight = String2Offset(OBFUSCATE("0xBC46F0")); // Rilisoft.GClass317 smethod_143
		inline uintptr_t ACThirtyNine = String2Offset(OBFUSCATE("0xBC6360")); // Rilisoft.GClass317 smethod_39
		inline uintptr_t ACFourty = String2Offset(OBFUSCATE("0xBB0470")); // Rilisoft.GClass317 smethod_40
		inline uintptr_t ACFourtyOne = String2Offset(OBFUSCATE("0xBAB100")); // Rilisoft.GClass317 smethod_41
		inline uintptr_t ACFourtyTwo = String2Offset(OBFUSCATE("0xBA9DD0")); // Rilisoft.GClass317 smethod_42
		inline uintptr_t ACFourtyThree = String2Offset(OBFUSCATE("0xBC3EE0")); // Rilisoft.GClass317 smethod_43
		inline uintptr_t ACFourtyFour = String2Offset(OBFUSCATE("0xBC5300")); // Rilisoft.GClass317 smethod_65
		inline uintptr_t ACFourtyFive = String2Offset(OBFUSCATE("0xBAC940")); // Rilisoft.GClass317 smethod_29
		inline uintptr_t ACFourtySix = String2Offset(OBFUSCATE("0xB15AE0")); // DataSystem.DataValidiation.GClass264 .cctor
		inline uintptr_t ACFourtySeven = String2Offset(OBFUSCATE("0x148DA10")); // NetworkStartTableNGUIController method_96
		inline uintptr_t ACFourtyEight = String2Offset(OBFUSCATE("0x1F67010")); // CheatDetectedBanner smethod_0
		inline uintptr_t ACFourtyNine = String2Offset(OBFUSCATE("0x1F671F0")); // CheatDetectedBanner smethod_1
		inline uintptr_t ACFifty = String2Offset(OBFUSCATE("0x1F67330")); // CheatDetectedBanner Update
		inline uintptr_t ACFiftyOne = String2Offset(OBFUSCATE("0x21D7440")); // CustomHungerBase smethod_0
		inline uintptr_t ACFiftyTwo = String2Offset(OBFUSCATE("0xBC1660")); // Rilisoft.GClass317 smethod_175
		inline uintptr_t ACFiftyThree = String2Offset(OBFUSCATE("0xBBC220")); // Rilisoft.GClass317 smethod_158
	}

	// Player_move_c
	namespace PlayerMoveC {
		inline uintptr_t PlayerMoveCUpdate = String2Offset(OBFUSCATE("0x0")); // Player_move_c Update
		inline uintptr_t XRay = String2Offset(OBFUSCATE("0x1B290B0")); // Player_move_c method_205
		inline uintptr_t MatchInvisibility = String2Offset(OBFUSCATE("0x0")); // Player_move_c MakeInvisibleForSeconds
		inline uintptr_t JetpackFly = String2Offset(OBFUSCATE("0x1AD22B0")); // Player_move_c method_159
		inline uintptr_t GodmodeOne = String2Offset(OBFUSCATE("0x1AD8570")); // Player_move_c method_451
	}

	// WeaponSounds
	namespace WeaponSounds {
		inline uintptr_t WeaponSoundsUpdate = String2Offset(OBFUSCATE("0x0")); // WeaponSounds Update
		inline uintptr_t NextHitCritical = String2Offset(OBFUSCATE("0x7E91C0"));// WeaponSounds SetNextHitCritical
	}

	// PetEngine
	namespace PetEngine {
		inline uintptr_t PetEngineUpdate = String2Offset(OBFUSCATE("0xDFD690")); // Rilisoft.PetEngine Update
		inline uintptr_t PetHealth = String2Offset(OBFUSCATE("0xDD7B20")); // PetEngine method_37
		inline uintptr_t PetDamage = String2Offset(OBFUSCATE("0x213E3D0")); // PetInfo get_Attack
		inline uintptr_t PetSpeed = String2Offset(OBFUSCATE("0x213E860")); // PetInfo get_SpeedModif
	}

	// Miscellaneous
	namespace Miscellaneous {
		inline uintptr_t SpeedModifier = String2Offset(OBFUSCATE("0x7757F0")); // ItemRecord get_SpeedModifier
		inline uintptr_t GodmodeTwo = String2Offset(OBFUSCATE("0x2180FC0")); // GClass147 method_16
		inline uintptr_t InfiniteGems = String2Offset(OBFUSCATE("0x4BBE80")); // Class9 smethod_6
		inline uintptr_t ReloadModifier = String2Offset(OBFUSCATE("0x729120")); // Class1837 smethod_13
		inline uintptr_t GadgetCooldown = String2Offset(OBFUSCATE("0x1E8C370")); // Class834 get_Single_2
		inline uintptr_t Lottery = String2Offset(OBFUSCATE("0x781F00")); // Class1877 get_Int32_0
		inline uintptr_t FireRate = String2Offset(OBFUSCATE("0x111B350")); // BalanceController smethod_82
		inline uintptr_t MaxLevelOne = String2Offset(OBFUSCATE("0x752C60")); // ExperienceController get_Int32_0
		inline uintptr_t MaxLevelTwo = String2Offset(OBFUSCATE("0x7530A0")); // ExperienceController get_Int32_1
		inline uintptr_t WebInstance = String2Offset(OBFUSCATE("0x37C38D0")); // Progress.Class2248 get_CLass2248_0
		inline uintptr_t AddCurrency = String2Offset(OBFUSCATE("0x9E3BD0")); // Progress.Class2248 method_144
		inline uintptr_t HealthOnline = String2Offset(OBFUSCATE("0x1AABE00")); // PlayerDamageable AddHealthFromWeaponOnline
		inline uintptr_t AmmoOnline = String2Offset(OBFUSCATE("0x1AABC70")); // PlayerDamageable AddAmmoFromWeaponOnline
		inline uintptr_t PixelPass = String2Offset(OBFUSCATE("0x18881E0")); // Class5646 get_Boolean_3
		inline uintptr_t RewardMultiplier = String2Offset(OBFUSCATE("0xC326E0")); // Class2905 method_3
		inline uintptr_t DoubleRewards = String2Offset(OBFUSCATE("0xC33660")); // Class2905 method_7
	}
}

template<typename T> inline T& GetField(void* instance, uint64_t offset) {
	return (T&)(*(T*)((uint64_t)instance + offset));
}
namespace FieldOffsets {
	// Player_move_c
	namespace PlayerMoveC {
		inline uintptr_t NickLabel = String2Offset(OBFUSCATE("0x3B8")); // Player_move_c nickLabel
	}

	// WeaponSounds
	namespace WeaponSounds {
		inline uintptr_t WeaponSoundsPlayer = String2Offset(OBFUSCATE("0x500")); // WeaponSounds player_move_c_0

		inline uintptr_t RecoilCeoff = String2Offset(OBFUSCATE("0xC0")); // recoilCeoff
		inline uintptr_t RecoilCeoffZoom = String2Offset(OBFUSCATE("0x124")); // recoilCeoffZoom
		inline uintptr_t ScatterCeoff = String2Offset(OBFUSCATE("0xB8")); // moveScatterCoeff
		inline uintptr_t ScatterCeoffZoom = String2Offset(OBFUSCATE("0x11C")); // moveScatterCoeffZoom

		inline uintptr_t Range = String2Offset(OBFUSCATE("0x658")); // range
		inline uintptr_t DamageRange = String2Offset(OBFUSCATE("0x5E8")); // damageRange
		inline uintptr_t ShootDistance = String2Offset(OBFUSCATE("0x664")); // shootDistance

		inline uintptr_t ShootDelay = String2Offset(OBFUSCATE("0x1AC")); // shootDelay
		inline uintptr_t BulletDelay = String2Offset(OBFUSCATE("0x1B0")); // bulletDelay
		inline uintptr_t BurstDelay = String2Offset(OBFUSCATE("0x5D8")); // delayInBurstShooting

		inline uintptr_t ZoomXRay = String2Offset(OBFUSCATE("0xC6")); // zoomXray

		inline uintptr_t ScopeSpeed = String2Offset(OBFUSCATE("0xF8")); // scopeSpeed
		inline uintptr_t Zooming = String2Offset(OBFUSCATE("0xC5")); // isZooming

		inline uintptr_t FirstCritical = String2Offset(OBFUSCATE("0x388")); // firstKillCritical

		inline uintptr_t UnlimitedAmmo = String2Offset(OBFUSCATE("0x469")); // isUnlimitedAmmo

		inline uintptr_t ChargeLoop = String2Offset(OBFUSCATE("0x1D8")); // chargeLoop
		inline uintptr_t ChargeMax = String2Offset(OBFUSCATE("0x1E0")); // chargeMax
		inline uintptr_t ChargeTime = String2Offset(OBFUSCATE("0x1E4")); // chargeTime
		inline uintptr_t Charging = String2Offset(OBFUSCATE("0x1CA")); // isCharging

		inline uintptr_t BuffPoints = String2Offset(OBFUSCATE("0x390")); // isBuffPoints
		inline uintptr_t BuffPointsKill = String2Offset(OBFUSCATE("0x3A0")); // buffPointsKIllDesigner
		inline uintptr_t BuffPointsAssist = String2Offset(OBFUSCATE("0x3A8")); // buffPointsAssistDesigner
		inline uintptr_t BuffPointsRevenge = String2Offset(OBFUSCATE("0x398")); // buffPointsRevengerDesigner
		inline uintptr_t BonusPointsKill = String2Offset(OBFUSCATE("0x39C")); // buffBonusPointsForKill
		inline uintptr_t BonusPointsAssist = String2Offset(OBFUSCATE("0x3A4")); // buffBonusPointsForAssist
		inline uintptr_t BonusPointsRevenge = String2Offset(OBFUSCATE("0x394")); // buffPointsRevenge

		inline uintptr_t SectorsAOE = String2Offset(OBFUSCATE("0x3C0")); // isSectorsAOE
		inline uintptr_t FrontAngle = String2Offset(OBFUSCATE("0x3C4")); // sectorsAOEAngleFront
		inline uintptr_t BackAngle = String2Offset(OBFUSCATE("0x3C8")); // sectorsAOEAngleBack
		inline uintptr_t FrontMultiplier = String2Offset(OBFUSCATE("0x3CC")); // sectorsAOEDamageMultiplierFront
		inline uintptr_t BackMultiplier = String2Offset(OBFUSCATE("0x3D4")); // sectorsAOEDamageMultiplierBack
		inline uintptr_t SideMultiplier = String2Offset(OBFUSCATE("0x3D0")); // sectorsAOEDamageMultiplierSide
		inline uintptr_t SectorsRadiusAOE = String2Offset(OBFUSCATE("0x3D8")); // sectorsAOERadiusSectorsAoE

		inline uintptr_t KoofZoom = String2Offset(OBFUSCATE("0x104")); // maxKoofZoom
		inline uintptr_t UpKoof = String2Offset(OBFUSCATE("0x108")); // upKoofFireZoom
		inline uintptr_t DownKoofFirst = String2Offset(OBFUSCATE("0x10C")); // downKoofFirstZoom
		inline uintptr_t DownKoofZoom = String2Offset(OBFUSCATE("0x110")); // downKoofZoom
		inline uintptr_t MaxKoof = String2Offset(OBFUSCATE("0x8C")); // maxKoof
		inline uintptr_t TekKoof = String2Offset(OBFUSCATE("0x90")); // tekKoof
		inline uintptr_t UpKoofFire = String2Offset(OBFUSCATE("0x94")); // upKoofFire
		inline uintptr_t DownKoofFire = String2Offset(OBFUSCATE("0x98")); // downKoofFirst
		inline uintptr_t DownKoof = String2Offset(OBFUSCATE("0x9C")); // downKoof
		inline uintptr_t TekKoofTimer = String2Offset(OBFUSCATE("0xA4")); // timerForTekKoofVisual
		inline uintptr_t TekKoofRateTimer = String2Offset(OBFUSCATE("0xA8")); // timerForTekKoofVisualByFireRate
		inline uintptr_t TekKoofTime = String2Offset(OBFUSCATE("0xAC")); // timeForTekKoofVisual
		inline uintptr_t StartZone = String2Offset(OBFUSCATE("0x84")); // startZone

		inline uintptr_t FrostSword = String2Offset(OBFUSCATE("0x369")); // isFrostSword
		inline uintptr_t FrostRadius = String2Offset(OBFUSCATE("0x370")); // frostRadius
		inline uintptr_t UseFrostAngle = String2Offset(OBFUSCATE("0x374")); // isFrostSwordUseAngle
		inline uintptr_t FrostAngle = String2Offset(OBFUSCATE("0x378")); // frostSwordAngle
		inline uintptr_t FrostTime = String2Offset(OBFUSCATE("0x37C")); // frostSwordnTime
		inline uintptr_t FrostMultiplier = String2Offset(OBFUSCATE("0x36C")); // frostDamageMultiplier

		inline uintptr_t Poisoning = String2Offset(OBFUSCATE("0x1F8")); // isPoisoning
		inline uintptr_t PoisonCount = String2Offset(OBFUSCATE("0x1FC")); // poisonCount
		inline uintptr_t PoisonTime = String2Offset(OBFUSCATE("0x204")); // poisonTime
		inline uintptr_t PoisonDamage = String2Offset(OBFUSCATE("0x200")); // poisonDamageMultiplier

		inline uintptr_t Polymorpher = String2Offset(OBFUSCATE("0x2EC")); // polymorpher
		inline uintptr_t PolymorpherTime = String2Offset(OBFUSCATE("0x2F0")); // polymorphDuarationTime
		inline uintptr_t PolymorpherHealth = String2Offset(OBFUSCATE("0x2F8")); // polymorphMaxHealth
		inline uintptr_t PolymorpherType = String2Offset(OBFUSCATE("0x2F4")); // polymorphType
		inline uintptr_t PolymorpherSpeed = String2Offset(OBFUSCATE("0x2FC")); // polymorphSpeed

		inline uintptr_t Stun = String2Offset(OBFUSCATE("0x238")); // isStun
		inline uintptr_t StunTime = String2Offset(OBFUSCATE("0x240")); // stunTime
		inline uintptr_t StunCeoff = String2Offset(OBFUSCATE("0x23C")); // stunCeoff
		inline uintptr_t StunRadius = String2Offset(OBFUSCATE("0x244")); // stunRadius
		inline uintptr_t Blind = String2Offset(OBFUSCATE("0x268")); // isBlindEffect
		inline uintptr_t BlindTime = String2Offset(OBFUSCATE("0x270")); // isBlindEffectTime
		inline uintptr_t Lightning = String2Offset(OBFUSCATE("0x155")); // isLightning
		inline uintptr_t Weakness = String2Offset(OBFUSCATE("0x27C")); // isWeaknessEffect
		inline uintptr_t WeaknessTime = String2Offset(OBFUSCATE("0x280")); // weaknessEffectTime
		inline uintptr_t Charm = String2Offset(OBFUSCATE("0x274")); // isCharm
		inline uintptr_t CharmTime = String2Offset(OBFUSCATE("0x278")); // charmTime
		inline uintptr_t Shocker = String2Offset(OBFUSCATE("0x484")); // shocker
		inline uintptr_t ShockerRange = String2Offset(OBFUSCATE("0x48C")); // shockerRange
		inline uintptr_t ShockerMultiplier = String2Offset(OBFUSCATE("0x488")); // shockerDamageMultiplier
		inline uintptr_t Cursing = String2Offset(OBFUSCATE("0x214")); // isCursing
		inline uintptr_t CursingTime = String2Offset(OBFUSCATE("0x218")); // curseTime
		inline uintptr_t CursingMultiplier = String2Offset(OBFUSCATE("0x21C")); // curseDamageMultiplier

		inline uintptr_t HeadMagnifier = String2Offset(OBFUSCATE("0x260")); // isHeadMagnifier
		inline uintptr_t MagnifierTime = String2Offset(OBFUSCATE("0x264")); // headMagnifierTime

		inline uintptr_t JumpDisabler = String2Offset(OBFUSCATE("0x20E")); // jumpDisabler
		inline uintptr_t DisableTime = String2Offset(OBFUSCATE("0x210")); // jumpDisableTime

		inline uintptr_t RespawnInvisibility = String2Offset(OBFUSCATE("0x389")); // isInvisibleAfterRespawn
		inline uintptr_t RespawnInvisibilityTime = String2Offset(OBFUSCATE("0x38C")); // invisibleAfterRespawnTime
		inline uintptr_t ReloadInvisibility = String2Offset(OBFUSCATE("0x380")); // isInvisibleReload
		inline uintptr_t KillInvisibility = String2Offset(OBFUSCATE("0x381")); // isInvisibleAfterKill
		inline uintptr_t KillInvisibilityTime = String2Offset(OBFUSCATE("0x384")); // invisibleAfterKillTime

		inline uintptr_t FireImmunity = String2Offset(OBFUSCATE("0x248")); // fireImmunity
		inline uintptr_t ToxicImmunity = String2Offset(OBFUSCATE("0x24A")); // toxicImmunity
		inline uintptr_t BleedingImmunity = String2Offset(OBFUSCATE("0x249")); // bleedingImmunity

		inline uintptr_t SnowStorm = String2Offset(OBFUSCATE("0x2FC")); // snowStorm
		inline uintptr_t SnowStormMultplier = String2Offset(OBFUSCATE("0x300")); // snowStormBonusMultiplier
		inline uintptr_t SnowStormRange = String2Offset(OBFUSCATE("0x304")); // snowStormBonusRange

		inline uintptr_t ReflectionRays = String2Offset(OBFUSCATE("0x1B8")); // countReflectionRay

		inline uintptr_t EnemyMarker = String2Offset(OBFUSCATE("0x24B")); // enemyMarker
		inline uintptr_t MarkerAiming = String2Offset(OBFUSCATE("0x24C")); // enemyMarkerWhenAiming
		inline uintptr_t MarkerRadius = String2Offset(OBFUSCATE("0x24D")); // enemyMarkerWhenShot
		inline uintptr_t MarkerChargeTime = String2Offset(OBFUSCATE("0x250")); // enemyMarketChargeTime

		inline uintptr_t Flamethrower = String2Offset(OBFUSCATE("0x34C")); // flamethrower
		inline uintptr_t ExplosiveBullets = String2Offset(OBFUSCATE("0x1A5")); // bulletExplode
		inline uintptr_t Shotgun = String2Offset(OBFUSCATE("0x1A6")); // isShotGun
		inline uintptr_t Railgun = String2Offset(OBFUSCATE("0x1BC")); // railgun
		inline uintptr_t RailgunClipping = String2Offset(OBFUSCATE("0x1C8")); // railgunStopAtWall
		inline uintptr_t Bazooka = String2Offset(OBFUSCATE("0x12B")); // bazooka
		inline uintptr_t Harpoon = String2Offset(OBFUSCATE("0x2B8")); // harpoon
		inline uintptr_t HarpoonDistance = String2Offset(OBFUSCATE("0x2E0")); // harpoonMaxDistance

		inline uintptr_t DoubleJump = String2Offset(OBFUSCATE("0x477")); // isDoubleJump

		inline uintptr_t ReducedHeadshotDamage = String2Offset(OBFUSCATE("0x28C")); // isReducedHeadshotDamage
		inline uintptr_t ReducedHeadshotDamageMultiplier = String2Offset(OBFUSCATE("0x290")); // reducedHeadshotDamageMultiplier

		inline uintptr_t IgnoreBarrier = String2Offset(OBFUSCATE("0x128")); // ignoreBarrier
		inline uintptr_t IgnoreSly = String2Offset(OBFUSCATE("0x129")); // ignoreSlyWolf
		inline uintptr_t IgnoreReflector = String2Offset(OBFUSCATE("0x12A")); // ignoreReflector
	}
}