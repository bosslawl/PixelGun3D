#pragma once
#include "../Utils/Offsets.h"
#include "../Utils/Variables.h"

// inline

namespace Internal {
	inline uintptr_t getAbsolute(uintptr_t addr) {
		if (addr != 0) {
			return UnitySDK::UnityGameAssembly + addr;
		}
		return 0;
	}

	// Player_move_c

	inline void ShowXray(void* obj, bool a1, int a2, int a3) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool, int, int)) (getAbsolute(Offsets::XRay));
		return fn(obj, a1, a2, a3);
	}

	inline float MatchInvisibility(void* obj, float a1) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::MatchInvisibility));
		return fn(obj, a1);
	}

	inline void JetpackFly(void* obj, bool a1) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::JetpackFly));
		return fn(obj, a1);
	}

	// WeaponSounds

	inline void NextHitCritical(void* obj, bool a1) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::NextHitCritical));
		return fn(obj, a1);
	}

	// PetEngine

	inline float PetEngineHealth(void* obj, float a1) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::PetHealth));
		return fn(obj, a1);
	}

	// UnityEngine

	inline void SetTimeScale(float TimeScale)
	{
		void (UNITY_CALLING_CONVENTION set_time_scale)(float TimeScale);
		reinterpret_cast<decltype(set_time_scale)>(Offsets::TimeOffset)(TimeScale);
	}
}

namespace GameFunctions {
	inline bool (UNITY_CALLING_CONVENTION isdebug)();
	inline bool isdebug_h() {
		return true;
	}

	// AntiCheat bypass

	inline void(__stdcall* OACOne)();
	inline void __stdcall ACOne()
	{
		return; 
	}

	inline void(__stdcall* OACTwo)();
	inline void __stdcall ACTwo()
	{
		return; 
	}

	inline void(__stdcall* OACThree)();
	inline void __stdcall ACThree()
	{
		return;
	}

	inline void(__stdcall* OACFour)();
	inline void __stdcall ACFour()
	{
		return; 
	}

	inline void(__stdcall* OACFive)();
	inline void __stdcall ACFive()
	{
		return; 
	}

	inline void(__stdcall* OACSix)();
	inline void __stdcall ACSix()
	{
		return; 
	}

	inline void(__stdcall* OACSeven)();
	inline void __stdcall ACSeven()
	{
		return; 
	}

	inline void(__stdcall* OACEight)();
	inline void __stdcall ACEight()
	{
		return;
	}

	inline void(__stdcall* OACNine)();
	inline void __stdcall ACNine()
	{
		return; 
	}

	inline void(__stdcall* OACTen)();
	inline void __stdcall ACTen()
	{
		return;
	}

	inline void(__stdcall* OACEleven)();
	inline void __stdcall ACEleven()
	{
		return;
	}

	inline void(__stdcall* OACTwelve)();
	inline void __stdcall ACTwelve()
	{
		return; 
	}

	inline void(__stdcall* OACThirteen)();
	inline void __stdcall ACThirteen()
	{
		return; 
	}

	inline void(__stdcall* OACFourteen)();
	inline void __stdcall ACFourteen()
	{
		return;
	}

	inline void(__stdcall* OACFifteen)();
	inline void __stdcall ACFifteen()
	{
		return;
	}

	inline void(__stdcall* OACSixteen)();
	inline void __stdcall ACSixteen()
	{
		return; 
	}

	inline void(__stdcall* OACSeventeen)();
	inline void __stdcall ACSeventeen()
	{
		return; 
	}

	inline void(__stdcall* OACEighteen)();
	inline void __stdcall ACEighteen()
	{
		return; 
	}

	inline void(__stdcall* OACNineteen)();
	inline void __stdcall ACNineteen()
	{
		return;
	}

	inline void(__stdcall* OACTwenty)();
	inline void __stdcall ACTwenty()
	{
		return; 
	}

	inline void(__stdcall* OACTwentyOne)();
	inline void __stdcall ACTwentyOne()
	{
		return; 
	}

	inline void(__stdcall* OACTwentyTwo)();
	inline void __stdcall ACTwentyTwo()
	{
		return; 
	}

	inline void(__stdcall* OACTwentyThree)();
	inline void __stdcall ACTwentyThree()
	{
		return; 
	}

	inline void(__stdcall* OACTwentyFour)();
	inline void __stdcall ACTwentyFour()
	{
		return;
	}

	inline void(__stdcall* OACTwentyFive)();
	inline void __stdcall ACTwentyFive()
	{
		return; 
	}

	inline void(__stdcall* OACTwentySix)();
	inline void __stdcall ACTwentySix()
	{
		return; 
	}

	inline void(__stdcall* OACTwentySeven)();
	inline void __stdcall ACTwentySeven()
	{
		return;
	}

	inline void(__stdcall* OACTwentyEight)();
	inline void __stdcall ACTwentyEight()
	{
		return;
	}

	inline void(__stdcall* OACTwentyNine)();
	inline void __stdcall ACTwentyNine()
	{
		return; 
	}

	inline void(__stdcall* OACThirty)();
	inline void __stdcall ACThirty()
	{
		return; 
	}

	inline void(__stdcall* OACThirtyOne)();
	inline void __stdcall ACThirtyOne()
	{
		return; 
	}

	inline void(__stdcall* OACThirtyTwo)();
	inline void __stdcall ACThirtyTwo()
	{
		return; 
	}

	inline void(__stdcall* OACThirtyThree)();
	inline void __stdcall ACThirtyThree()
	{
		return; 
	}

	inline void(__stdcall* OACThirtyFour)();
	inline void __stdcall ACThirtyFour()
	{
		return; 
	}

	inline void(__stdcall* OACThirtyFive)();
	inline void __stdcall ACThirtyFive()
	{
		return; 
	}

	inline void(__stdcall* OACThirtySix)();
	inline void __stdcall ACThirtySix()
	{
		return; 
	}

	inline void(__stdcall* OACThirtySeven)();
	inline void __stdcall ACThirtySeven()
	{
		return; 
	}

	inline void(__stdcall* OACThirtyEight)();
	inline void __stdcall ACThirtyEight()
	{
		return;
	}

	inline void(__stdcall* OACThirtyNine)();
	inline void __stdcall ACThirtyNine()
	{
		return; 
	}

	inline void(__stdcall* OACFourty)();
	inline void __stdcall ACFourty()
	{
		return; 
	}

	inline void(__stdcall* OACFourtyOne)();
	inline void __stdcall ACFourtyOne()
	{
		return; 
	}

	inline void(__stdcall* OACFourtyTwo)();
	inline void __stdcall ACFourtyTwo()
	{
		return; 
	}

	inline void(__stdcall* OACFourtyThree)();
	inline void __stdcall ACFourtyThree()
	{
		return; 
	}

	// Player_move_c

	inline void(__stdcall* OPlayerMoveC)(void* obj);
	inline void __stdcall PlayerMoveC(void* obj)
	{
		if (Variables::XRay)
			Internal::ShowXray(obj, true, 0, 0); 

		if (Variables::MatchInvisibility)
			Internal::MatchInvisibility(obj, Variables::MInvisibilityDuration);

		if (Variables::JetpackFly)
			Internal::JetpackFly(obj, true); 
		else
			Internal::JetpackFly(obj, false);

		//void* playerDamageable = *(void**)((uintptr_t)obj + Offsets::String2Offset(OBFUSCATE("0x650")));

		return OPlayerMoveC(obj);
	}

	inline float(__stdcall* OSpeedModifier)(void* obj);
	inline float __stdcall SpeedModifier(void* obj)
	{
		if (Variables::PlayerSpeed)
			return Variables::SpeedValue;

		return OSpeedModifier(obj);
	}

	inline void(__stdcall* OGodmodeOne)(...);
	inline void __stdcall GodmodeOne(void* obj, float a1, void* a2, void* a3, void* a4, void* a5, Vector3 a6, void* a7, int a8)
	{
		if (Variables::Godmode)
			return;

		return OGodmodeOne(obj, a1, a2, a3, a4, a5, a6, a7, a8);
	}
	
	// WeaponSounds

	inline void(__stdcall* OWeaponSounds)(void* obj);
	inline void __stdcall WeaponSounds(void* obj)
	{
		if (Variables::RecoilModifier)
		{
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xC0"))) = Variables::RecoilValue; // recoilCeoff
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x124"))) = Variables::RecoilValue; // recoilCeoffZoom
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xB8"))) = Variables::RecoilValue; // moveScatterCoeff
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x11C"))) = Variables::RecoilValue; // moveScatterCoeffZoom
		}

		if (Variables::RangeModifier)
		{
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x658"))) = Variables::RangeValue; // range
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x5E8"))) = Variables::RangeValue; // damageRange
		}

		if (Variables::FullAuto)
		{
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1AC"))) = 0.000001f; // shootDelay
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1B0"))) = 0.000001f; // bulletDelay
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x5D8"))) = 0.000001f; // delayInBurstShooting
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1E4"))) = 0.000001f; // chargeTime
		}

		if (Variables::ZoomXRay)
			*(bool*)((uint64_t)obj + 0xC6) = true; // zoomXray

		if (Variables::ScopeModifier)
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xF8"))) = Variables::ScopeValue; // scopeSpeed

		if (Variables::ForceCriticals)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x388"))) = true; // firstKillCritical
			Internal::NextHitCritical(obj, true); // SetNextHitCritical
		}

		if (Variables::InfiniteAmmo)
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x469"))) = true; // isUnlimitedAmmo

		if (Variables::ChargeModifier)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1D8"))) = true; // chargeLoop
			*(int*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1E0"))) = Variables::ChargeMax; // chargeMax
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1E4"))) = Variables::ChargeDuration; // chargeTime
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1CA"))) = false; // isCharging
		}

		if (Variables::ScoreModifier)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x390"))) = true; // isBuffPoints
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3A0"))) = true; // buffPointsKIllDesigner
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3A8"))) = true; // buffPointsAssistDesigner
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x398"))) = true; // buffPointsRevengerDesigner
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x39C"))) = Variables::KillModifier; // buffBonusPointsForKill 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3A4"))) = Variables::AssistModifier; // buffBonusPointsForAssist 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x394"))) = Variables::RevengeModifier; // buffPointsRevenge 
		}

		if (Variables::AOEBullets)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3C0"))) = true; // isSectorsAOE 
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x34C"))) = false; // flamethrower 
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1BC"))) = false; // railgun 
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x12B"))) = false; // bazooka 
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x2B8"))) = false; // harpoon 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3C4"))) = Variables::FrontAngle; // sectorsAOEAngleFront 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3C8"))) = Variables::BackAngle; // sectorsAOEAngleBack
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3CC"))) = Variables::FrontMultiplier; // sectorsAOEDamageMultiplierFront 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3D4"))) = Variables::BackMultiplier; // sectorsAOEDamageMultiplierBack 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3D0"))) = Variables::SideMultiplier; // sectorsAOEDamageMultiplierSide 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x3D8"))) = Variables::AOERadius; // sectorsAOERadiusSectorsAoE 
		}

		if (Variables::NoSpread)
		{
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x104"))) = 0; // maxKoofZoom
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x108"))) = 0; // upKoofFireZoom
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x10C"))) = 0; // downKoofFirstZoom
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x110"))) = 0; // downKoofZoom
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x8C"))) = 0; // maxKoof
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x90"))) = 0; // tekKoof
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x94"))) = 0; // upKoofFire
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x98"))) = 0; // downKoofFirst
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x9C"))) = 0; // downKoof
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xA4"))) = 0; // timerForTekKoofVisual
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xA8"))) = 0; // timerForTekKoofVisualByFireRate
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xA8"))) = 0; // timerForTekKoofVisualByFireRate
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0xAC"))) = 0; // timeForTekKoofVisual
			*(Vector2*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x84"))) = Vector2(0, 0); // startZone
		}

		if (Variables::FrostAura)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x369"))) = true; // isFrostSword 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x370"))) = Variables::AuraRadius; // frostRadius
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x374"))) = true; // isFrostSwordUseAngle 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x378"))) = Variables::AuraAngle; // frostSwordAngle
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x37C"))) = 0.33f; // frostSwordnTime
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x36C"))) = Variables::AuraMultiplier; // frostDamageMultiplier
		}

		if (Variables::ForcePolymorpher)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x2EC"))) = true; // polymorpher 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x2F0"))) = Variables::PolymorpherDuration; // polymorphDuarationTime 
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x2F8"))) = Variables::PolymorpherHealth; // polymorphMaxHealth 
			*(int*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x2F4"))) = Variables::PolymorpherType; // polymorphType
		}

		if (Variables::PoisonEffect)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1F8"))) = true; // isPoisoning
			*(int*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1FC"))) = Variables::PoisonCount; // poisonCount
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x200"))) = Variables::PoisonMultiplier; // poisonDamageMultiplier
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x204"))) = Variables::PoisonDuration; // poisonTime
		}

		if (Variables::StunEffect)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x238"))) = true; // isStun
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x23C"))) = Variables::StunMultiplier; // stunCeoff
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x240"))) = Variables::StunDuration; // stunTime
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x244"))) = Variables::StunRadius; // stunRadius
		}

		if (Variables::CurseEffect)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x214"))) = true; // isCursing
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x218"))) = Variables::CurseDuration; // curseTime
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x21C"))) = Variables::CurseMultiplier; // curseDamageMultiplier
		}

		if (Variables::CharmEffect)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x274"))) = true; // isCharm
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x278"))) = Variables::CharmDuration; // charmTime
		}

		if (Variables::WeaknessEffect)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x27C"))) = true; // isWeaknessEffect
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x280"))) = Variables::WeaknessDuration; // weaknessEffectTime
		}

		if (Variables::BlindEffect)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x268"))) = true; // isBlindEffect
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x270"))) = Variables::BlindDuration; // isBlindEffectTime
		}

		if (Variables::LightningEffect)
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x155"))) = true; // isLightning

		if (Variables::HeadMagnifier) {
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x260"))) = true; // isHeadMagnifier
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x264"))) = Variables::MagnifierDuration; // headMagnifierTime
		}

		if (Variables::ReflectionRays)
			*(int*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x1B8"))) = Variables::ReflectionCount; // countReflectionRay

		if (Variables::JumpDisabler)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x20E"))) = true; // jumpDisabler
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x210"))) = Variables::JDisabledDuration; // jumpDisableTime
		}

		if (Variables::Invisibility)
		{
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x389"))) = true; // isInvisibleAfterRespawn
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x38C"))) = Variables::SInvisibilityDuration; // invisibleAfterRespawnTime
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x380"))) = true; // isInvisibleReload
			*(bool*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x381"))) = true; // isInvisibleAfterKill
			*(float*)((uint64_t)obj + Offsets::String2Offset(OBFUSCATE("0x384"))) = Variables::SInvisibilityDuration; // invisibleAfterKillTime
		}

		return OWeaponSounds(obj);
	}

	// PetEngine

	inline void(__stdcall* OPetEngine)(void* obj);
	inline void __stdcall PetEngine(void* obj)
	{
		if (Variables::PetHealth)
			Internal::PetEngineHealth(obj, Variables::PetHealthValue); 

		return OPetEngine(obj);
	}

	inline float(__stdcall* OPetDamage)(void* obj);
	inline float __stdcall PetDamage(void* obj)
	{
		if (Variables::PetDamage)
			return Variables::PetDamageValue; 

		return OPetDamage(obj);
	}

	inline float(__stdcall* OPetSpeed)(void* obj);
	inline float __stdcall PetSpeed(void* obj)
	{
		if (Variables::PetSpeed)
			return Variables::PetSpeedValue; 

		return OPetSpeed(obj);
	}

	// Misc 

	inline void(__stdcall* OGodmodeTwo)(void* obj);
	inline void __stdcall GodmodeTwo(void* obj)
	{
		if (Variables::Godmode)
			return;

		return OGodmodeTwo(obj);
	}

	inline bool(__stdcall* OInfiniteGems)(void* obj);
	inline bool __stdcall InfiniteGems(void* obj)
	{
		if (Variables::InfiniteGems)
			return true; 

		return OInfiniteGems(obj);
	}

	inline float(__stdcall* OReloadModifier)(void* obj, void* a1, void* a2, void* a3, void* a4);
	inline float __stdcall ReloadModifier(void* obj, void* a1, void* a2, void* a3, void* a4)
	{
		if (Variables::ReloadModifier)
			return Variables::ReloadValue; 

		return OReloadModifier(obj, a1, a2, a3, a4);
	}

	inline float(__stdcall* OGadgetCooldown)(void* obj);
	inline float __stdcall GadgetCooldown(void* obj)
	{
		if (Variables::GadgetCooldown)
			return Variables::CooldownValue;

		return OGadgetCooldown(obj);
	}

	inline int(__stdcall* OLottery)(void* obj);
	inline int __stdcall Lottery(void* obj)
	{
		if (Variables::Lottery)
			return 0; 

		return OLottery(obj);
	}

	inline float(__stdcall* OFireRate)(int a1);
	inline float __stdcall FireRate(int a1)
	{
		if (Variables::FireRate)
			return Variables::RapidValue; 

		return OFireRate(a1);
	}

	inline int(__stdcall* OExperience)(...);
	inline int __stdcall Experience(void* obj) {
		if (Variables::MaxLevelOne) {
			return 32465; 
		}
		if (Variables::MaxLevelTwo) {
			return 2147451182; 
		}

		return OExperience();
	}

	inline int(__stdcall* OLevel)(...);
	inline int __stdcall Level() {
		if (Variables::MaxLevelOne || Variables::MaxLevelTwo) {
			return 65; 
		}

		return OLevel();
	}
}