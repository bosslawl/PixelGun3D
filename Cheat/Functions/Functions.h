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

	inline void ShowXray(void* obj, bool a1, int a2, int a3) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool, int, int)) (getAbsolute(Offsets::XRay));
		return fn(obj, a1, a2, a3);
	}

	inline void NextHitCritical(void* obj, bool a1) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::NextHitCritical));
		return fn(obj, a1);
	}

	inline float Invisibility(void* obj, float a1) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::Invisibility));
		return fn(obj, a1);
	}

	inline void JetpackFly (void* obj, bool a1) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::JetpackFly));
		return fn(obj, a1);
	}

	inline void PetEngineHealth(void* obj, float a1) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, float)) (getAbsolute(Offsets::PetHealth));
		return fn(obj, a1);
	}

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

	inline void(__stdcall* OACOne)();
	inline void __stdcall ACOne()
	{
		return; // GClass264
	}

	inline void(__stdcall* OACTwo)();
	inline void __stdcall ACTwo()
	{
		return; // GClass2536
	}

	inline void(__stdcall* OACThree)();
	inline void __stdcall ACThree()
	{
		return; // HandleBanUs
	}

	inline void(__stdcall* OWeaponSounds)(void* obj);
	inline void __stdcall WeaponSounds(void* obj)
	{
		if (Variables::RecoilModifier)
		{
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xC0"))) = Variables::RecoilValue; // recoilCeoff
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x124"))) = Variables::RecoilValue; // recoilCeoffZoom
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xB8"))) = Variables::RecoilValue; // moveScatterCoeff
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x11C"))) = Variables::RecoilValue; // moveScatterCoeffZoom
		}

		if (Variables::RangeModifier)
		{
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x658"))) = Variables::RangeValue; // range
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x5E8"))) = Variables::RangeValue; // damageRange
		}

		if (Variables::FullAuto)
		{
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1AC"))) = 0.000001f; // shootDelay
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1B0"))) = 0.000001f; // bulletDelay
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x5D8"))) = 0.000001f; // delayInBurstShooting
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1E4"))) = 0.000001f; // chargeTime
		}

		if (Variables::ZoomXRay)
			*(bool*)((uint64_t)obj + 0xC6) = true; // zoomXray

		if (Variables::ScopeModifier)
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xF8"))) = Variables::ScopeValue; // scopeSpeed

		if (Variables::ForceCriticals)
		{
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x388"))) = true; // firstKillCritical
			Internal::NextHitCritical(obj, true); // SetNextHitCritical
		}

		if (Variables::InfiniteAmmo)
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x469"))) = true; // isUnlimitedAmmo

		if (Variables::ChargeModifier)
		{
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1D8"))) = true; // chargeLoop
			*(int*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1E0"))) = Variables::ChargeMax; // chargeMax
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1E4"))) = Variables::ChargeDuration; // chargeTime
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1CA"))) = false; // isCharging
		}

		if (Variables::ScoreModifier)
		{
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x390"))) = true; // isBuffPoints
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3A0"))) = true; // buffPointsKIllDesigner
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3A8"))) = true; // buffPointsAssistDesigner
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x398"))) = true; // buffPointsRevengerDesigner
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x39C"))) = Variables::KillModifier; // buffBonusPointsForKill 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3A4"))) = Variables::AssistModifier; // buffBonusPointsForAssist 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x394"))) = Variables::RevengeModifier; // buffPointsRevenge 
		}

		if (Variables::AOEBullets)
		{
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3C0"))) = true; // isSectorsAOE 
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x34C"))) = false; // flamethrower 
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1BC"))) = false; // railgun 
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x12B"))) = false; // bazooka 
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x2B8"))) = false; // harpoon 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3C4"))) = Variables::FrontAngle; // sectorsAOEAngleFront 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3C8"))) = Variables::BackAngle; // sectorsAOEAngleBack
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3CC"))) = Variables::FrontMultiplier; // sectorsAOEDamageMultiplierFront 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3D4"))) = Variables::BackMultiplier; // sectorsAOEDamageMultiplierBack 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3D0"))) = Variables::SideMultiplier; // sectorsAOEDamageMultiplierSide 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x3D8"))) = Variables::AOERadius; // sectorsAOERadiusSectorsAoE 
		}

		if (Variables::NoSpread)
		{
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x104"))) = 0; // maxKoofZoom
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x108"))) = 0; // upKoofFireZoom
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x10C"))) = 0; // downKoofFirstZoom
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x110"))) = 0; // downKoofZoom
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x8C"))) = 0; // maxKoof
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x90"))) = 0; // tekKoof
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x94"))) = 0; // upKoofFire
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x98"))) = 0; // downKoofFirst
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x9C"))) = 0; // downKoof
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xA4"))) = 0; // timerForTekKoofVisual
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xA8"))) = 0; // timerForTekKoofVisualByFireRate
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xA8"))) = 0; // timerForTekKoofVisualByFireRate
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0xAC"))) = 0; // timeForTekKoofVisual
			*(Vector2*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x84"))) = Vector2(0, 0); // startZone
		}

		if (Variables::FrostAura)
		{
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x369"))) = true; // isFrostSword 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x370"))) = Variables::AuraRadius; // frostRadius
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x374"))) = true; // isFrostSwordUseAngle 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x378"))) = Variables::AuraAngle; // frostSwordAngle
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x37C"))) = 0.33f; // frostSwordnTime
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x36C"))) = Variables::AuraMultiplier; // frostDamageMultiplier
		}

		if (Variables::ForcePolymorpher)
		{
			*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x2EC"))) = true; // polymorpher 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x2F0"))) = Variables::PolymorpherDuration; // polymorphDuarationTime 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x2F8"))) = Variables::PolymorpherHealth; // polymorphMaxHealth 
			*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x2F4"))) = Variables::PolymorpherType; // polymorphType
		}

		if (Variables::ForceEffects)
		{
			if (Variables::PoisonEffect)
			{
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1F8"))) = true; // isPoisoning
				*(int*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x1FC"))) = Variables::PoisonCount; // poisonCount
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x200"))) = Variables::PoisonMultiplier; // poisonDamageMultiplier
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x204"))) = Variables::PoisonDuration; // poisonTime
			}
			if (Variables::StunEffect)
			{
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x238"))) = true; // isStun
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x23C"))) = Variables::StunMultiplier; // stunCeoff
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x240"))) = Variables::StunDuration; // stunTime
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x244"))) = Variables::StunRadius; // stunRadius
			}
			if (Variables::CurseEffect)
			{
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x214"))) = true; // isCursing
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x218"))) = Variables::CurseDuration; // curseTime
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x21C"))) = Variables::CurseMultiplier; // curseDamageMultiplier
			}
			if (Variables::CharmEffect)
			{
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x274"))) = true; // isCharm
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x278"))) = Variables::CharmDuration; // charmTime
			}
			if (Variables::WeaknessEffect)
			{
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x27C"))) = true; // isWeaknessEffect
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x280"))) = Variables::WeaknessDuration; // weaknessEffectTime
			}
			if (Variables::BlindEffect)
			{
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x268"))) = true; // isBlindEffect
				*(float*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x270"))) = Variables::BlindDuration; // isBlindEffectTime
			}
			if (Variables::LightningEffect)
				*(bool*)((uint64_t)obj + Utils::String2Offset(OBFUSCATE("0x155"))) = true; // isLightning
		}

		return OWeaponSounds(obj);
	}

	inline void(__stdcall* OPlayerMoveC)(void* obj);
	inline void __stdcall PlayerMoveC(void* obj)
	{
		if (Variables::XRay)
			Internal::ShowXray(obj, true, 0, 0); // player_move_c method_205

		if (Variables::Invisibility)
			Internal::Invisibility(obj, 999999.0f); // MakeInvisibleForSeconds

		if (Variables::JetpackFly)
			Internal::JetpackFly(obj, true); // Jetpack?
		else 
			Internal::JetpackFly(obj, false);

		//void* playerDamageable = *(void**)((uintptr_t)obj + Utils::String2Offset(OBFUSCATE("0x650")));

		return OPlayerMoveC(obj);
	}		

	inline void(__stdcall* OPetEngine)(void* obj);
	inline void __stdcall PetEngine(void* obj)
	{
		if (Variables::PetHealth)
			Internal::PetEngineHealth(obj, Variables::PetHealthValue); // method_37

		return OPetEngine(obj);
	}

	inline float(__stdcall* OPetDamage)(void* obj);
	inline float __stdcall PetDamage(void* obj)
	{
		if (Variables::PetDamage)
			return Variables::PetDamageValue; // PetInfo Attack

		return OPetDamage(obj);
	}

	inline float(__stdcall* OPetSpeed)(void* obj);
	inline float __stdcall PetSpeed(void* obj)
	{
		if (Variables::PetSpeed)
			return Variables::PetSpeedValue; // PetInfo SpeedModif

		return OPetSpeed(obj);
	}

	inline float(__stdcall* OSpeedModifier)(void* obj);
	inline float __stdcall SpeedModifier(void* obj)
	{
		if (Variables::PlayerSpeed)
			return Variables::SpeedValue; // SpeedModifier

		return OSpeedModifier(obj);
	}

	inline int(__stdcall* OMovePlayer)(void* obj, Vector3 motion);
	inline int __stdcall MovePlayer(void* obj, Vector3 motion)
	{
		if (Variables::InfiniteJump)
		{
			if (Utils::KeyPressed(Variables::JumpKey))
				motion = Vector3(0, 0.5f, 0); // UnityEngine.CharacterController->Move
		}

		return OMovePlayer(obj, motion);
	}

	inline void(__stdcall* OGodmodeOne)(...);
	inline void __stdcall GodmodeOne(void* obj, float a1, void* a2, void* a3, void* a4, void* a5, Vector3 a6, void* a7, int a8)
	{
		if (Variables::Godmode)
			return; // player_move_c method_451 

		return OGodmodeOne(obj, a1, a2, a3, a4, a5, a6, a7, a8);
	}

	inline void(__stdcall* OGodmodeTwo)(void* obj);
	inline void __stdcall GodmodeTwo(void* obj)
	{
		if (Variables::Godmode)
			return; // gclass147 method_16 

		return OGodmodeTwo(obj);
	}

	inline bool(__stdcall* OInfiniteGems)(void* obj);
	inline bool __stdcall InfiniteGems(void* obj)
	{
		if (Variables::InfiniteGems)
			return true; // class9 smethod_6 

		return OInfiniteGems(obj);
	}

	inline float(__stdcall* OReloadModifier)(void* obj, void* a1, void* a2, void* a3, void* a4);
	inline float __stdcall ReloadModifier(void* obj, void* a1, void* a2, void* a3, void* a4)
	{
		if (Variables::ReloadModifier)
			return Variables::ReloadValue; // class1837 smethod_13 

		return OReloadModifier(obj, a1, a2, a3, a4);
	}

	inline float(__stdcall* OGadgetCooldown)(void* obj);
	inline float __stdcall GadgetCooldown(void* obj)
	{
		if (Variables::GadgetCooldown)
			return 0.0f; // class1837 smethod_13 

		return OGadgetCooldown(obj); // class835 Single_2
	}

	inline int(__stdcall* OLottery)(void* obj);
	inline int __stdcall Lottery(void* obj)
	{
		if (Variables::Lottery)
			return 0; // class1877 Int32_0

		return OLottery(obj);
	}
}