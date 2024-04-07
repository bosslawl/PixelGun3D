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

	inline float AddHealthFromWeaponOnline(void* obj, float a1, std::string a2) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float, std::string)) (getAbsolute(Offsets::AddHealthFromWeaponOnline));
		return fn(obj, a1, a2);
	}

	inline float AddAmmoFromWeaponOnline(void* obj, float a1) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::AddAmmoFromWeaponOnline));
		return fn(obj, a1);
	}

	inline float Invisibility(void* obj, float a1) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::Invisibility));
		return fn(obj, a1);
	}

	inline float InvisibilityRPC(void* obj, float a1) {
		if (!obj) return 0;
		static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::InvisibilityRPC));
		return fn(obj, a1);
	}

	inline void JetpackFly (void* obj, bool a1) {
		if (!obj) return;
		static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::JetpackFly));
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

	inline void* MyPlayer;
	inline void* enemyPlayer;

	inline void(__stdcall* OWeaponSounds)(void* obj);
	inline void __stdcall WeaponSounds(void* obj)
	{
		if (Variables::NoRecoil)
		{
			*(float*)((uint64_t)obj + 0xC0) = 0.0f; // recoilCeoff
			*(float*)((uint64_t)obj + 0x124) = 0.0f; // recoilCeoffZoom
			*(float*)((uint64_t)obj + 0xB8) = 0.0f; // moveScatterCoeff
			*(float*)((uint64_t)obj + 0x11C) = 0.0f; // moveScatterCoeffZoom
		}

		if (Variables::InfiniteRange)
		{
			*(float*)((uint64_t)obj + 0x658) = 999999.0f; // range
			*(float*)((uint64_t)obj + 0x5E8) = 999999.0f; // damageRange
		}

		if (Variables::FullAuto)
		{
			*(float*)((uint64_t)obj + 0x1AC) = 0.000001f; // shootDelay
			*(float*)((uint64_t)obj + 0x1B0) = 0.000001f; // bulletDelay
			*(float*)((uint64_t)obj + 0x5D8) = 0.000001f; // delayInBurstShooting
			*(float*)((uint64_t)obj + 0x1E4) = 0.000001f; // chargeTime
		}

		if (Variables::ZoomXRay)
			*(bool*)((uint64_t)obj + 0xC6) = true; // zoomXray

		if (&Variables::InstantADS)
			*(float*)((uint64_t)obj + 0xF8) = 999999.0f; // scopeSpeed

		if (Variables::ForceCriticals)
		{
			*(bool*)((uint64_t)obj + 0x388) = true; // firstKillCritical
			Internal::NextHitCritical(obj, true); // SetNextHitCritical
		}

		if (Variables::ForceEffects)
		{
			if (Variables::PoisonEffect)
			{
				*(bool*)((uint64_t)obj + 0x1F8) = true; // isPoisoning
				*(int*)((uint64_t)obj + 0x1FC) = 999999; // poisonCount
				*(float*)((uint64_t)obj + 0x200) = 5.0f; // poisonDamageMultiplier
				*(float*)((uint64_t)obj + 0x204) = 999999.0f; // poisonTime
			}
			if (Variables::StunEffect)
			{
				*(bool*)((uint64_t)obj + 0x238) = true; // isStun
				*(float*)((uint64_t)obj + 0x23C) = 5.0f; // stunCeoff
				*(float*)((uint64_t)obj + 0x240) = 999999.0f; // stunTime
				*(float*)((uint64_t)obj + 0x244) = 999999.0f; // stunRadius
			}
			if (Variables::CurseEffect)
			{
				*(bool*)((uint64_t)obj + 0x214) = true; // isCursing
				*(float*)((uint64_t)obj + 0x218) = 999999.0f; // curseTime
				*(float*)((uint64_t)obj + 0x21C) = 5.0f; // curseDamageMultiplier
			}
			if (Variables::CharmEffect)
			{
				*(bool*)((uint64_t)obj + 0x274) = true; // isCharm
				*(float*)((uint64_t)obj + 0x278) = 999999.0f; // charmTime
			}
			if (Variables::WeaknessEffect)
			{
				*(bool*)((uint64_t)obj + 0x27C) = true; // isWeaknessEffect
				*(float*)((uint64_t)obj + 0x280) = 999999.0f; // weaknessEffectTime
			}
			if (Variables::BlindEffect)
			{
				*(bool*)((uint64_t)obj + 0x268) = true; // isBlindEffect
				*(float*)((uint64_t)obj + 0x270) = 999999.0f; // isBlindEffectTime
			}
			if (Variables::LightningEffect)
				*(bool*)((uint64_t)obj + 0x155) = true; // isLightning
		}

		if (Variables::InfiniteAmmo)
			*(bool*)((uint64_t)obj + 0x469) = true; // isUnlimitedAmmo

		if (Variables::InstantCharge)
		{
			*(bool*)((uint64_t)obj + 0x1D8) = true; // chargeLoop
			*(int*)((uint64_t)obj + 0x1E0) = 999999; // chargeMax
			*(float*)((uint64_t)obj + 0x1E4) = 999999.0f; // chargeTime
			*(bool*)((uint64_t)obj + 0x1CA) = false; // isCharging
		}

		if (Variables::ScoreModifier)
		{
			*(bool*)((uint64_t)obj + 0x390) = true; // isBuffPoints
			*(bool*)((uint64_t)obj + 0x3A0) = true; // buffPointsKIllDesigner
			*(bool*)((uint64_t)obj + 0x3A8) = true; // buffPointsAssistDesigner
			*(bool*)((uint64_t)obj + 0x398) = true; // buffPointsRevengerDesigner
			*(float*)((uint64_t)obj + 0x39C) = 999999.0f; // buffBonusPointsForKill 
			*(float*)((uint64_t)obj + 0x3A4) = 999999.0f; // buffBonusPointsForAssist 
			*(float*)((uint64_t)obj + 0x394) = 999999.0f; // buffPointsRevenge 
		}

		if (Variables::AOEBullets)
		{
			*(bool*)((uint64_t)obj + 0x3C0) = true; // isSectorsAOE 
			*(bool*)((uint64_t)obj + 0x34C) = false; // flamethrower 
			*(bool*)((uint64_t)obj + 0x1BC) = false; // railgun 
			*(bool*)((uint64_t)obj + 0x12B) = false; // bazooka 
			*(bool*)((uint64_t)obj + 0x2B8) = false; // harpoon 
			*(float*)((uint64_t)obj + 0x3C4) = 360.0f; // sectorsAOEAngleFront 
			*(float*)((uint64_t)obj + 0x3C8) = 360.0f; // sectorsAOEAngleBack
			*(float*)((uint64_t)obj + 0x3CC) = 5.0f; // sectorsAOEDamageMultiplierFront 
			*(float*)((uint64_t)obj + 0x3D4) = 5.0f; // sectorsAOEDamageMultiplierBack 
			*(float*)((uint64_t)obj + 0x3D0) = 5.0f; // sectorsAOEDamageMultiplierSide 
			*(float*)((uint64_t)obj + 0x3D8) = 999999.0f; // sectorsAOERadiusSectorsAoE 
		}

		if (Variables::NoSpread) 
		{
			*(float*)((uint64_t)obj + 0x104) = 0; // maxKoofZoom
			*(float*)((uint64_t)obj + 0x108) = 0; // upKoofFireZoom
			*(float*)((uint64_t)obj + 0x10C) = 0; // downKoofFirstZoom
			*(float*)((uint64_t)obj + 0x110) = 0; // downKoofZoom
			*(float*)((uint64_t)obj + 0x8C) = 0; // maxKoof
			*(float*)((uint64_t)obj + 0x90) = 0; // tekKoof
			*(float*)((uint64_t)obj + 0x94) = 0; // upKoofFire
			*(float*)((uint64_t)obj + 0x98) = 0; // downKoofFirst
			*(float*)((uint64_t)obj + 0x9C) = 0; // downKoof
			*(float*)((uint64_t)obj + 0xA4) = 0; // timerForTekKoofVisual
			*(float*)((uint64_t)obj + 0xA8) = 0; // timerForTekKoofVisualByFireRate
			*(float*)((uint64_t)obj + 0xA8) = 0; // timerForTekKoofVisualByFireRate
			*(float*)((uint64_t)obj + 0xAC) = 0; // timeForTekKoofVisual
			*(Vector2*)((uint64_t)obj + 0x84) = Vector2(0, 0); // startZone
		}

		if (Variables::FrostAura)
		{
			*(bool*)((uint64_t)obj + 0x369) = true; // isFrostSword 
			*(bool*)((uint64_t)obj + 0x374) = true; // isFrostSwordUseAngle 
			*(float*)((uint64_t)obj + 0x3EC) = 999999.0f; // frostRadius 
			*(float*)((uint64_t)obj + 0x378) = 5.0f; // frostDamageMultiplier
			*(float*)((uint64_t)obj + 0x37C) = 0.33f; // frostSwordnTime
		}

		return OWeaponSounds(obj);
	}

	inline void(__stdcall* OPlayerMoveC)(void* obj);
	inline void __stdcall PlayerMoveC(void* obj)
	{
		if (Variables::XRay)
			Internal::ShowXray(obj, true, 0, 0); // method_205

		if (Variables::Invisibility)
		{
			Variables::Invisibility = !Variables::Invisibility;
			Internal::Invisibility(obj, 999999.0f); // MakeInvisibleForSeconds
			Internal::InvisibilityRPC(obj, 999999.0f); // MakeInvisibleForSecondsRPC
		}

		if (Variables::JetpackFly)
		{
			Internal::JetpackFly(obj, true); // Jetpack?
			Variables::JetpackFly = false;
		}

		void* playerDamageable = *(void**)((uintptr_t)obj + 0x650);

		if (Variables::HealOnline)
			Internal::AddHealthFromWeaponOnline(playerDamageable, 999999.0f, ""); // AddHealthFromWeaponOnline

		if (Variables::AmmoOnline)
			Internal::AddAmmoFromWeaponOnline(playerDamageable, 999999.0f); // AddAmmoFromWeaponOnline

		return OPlayerMoveC(obj);
	}		

	inline float(__stdcall* OSpeedModifier)(void* obj);
	inline float __stdcall SpeedModifier(void* obj)
	{
		if (Variables::PlayerSpeed)
			return 999999.0f; // SpeedModifier

		return OSpeedModifier(obj);
	}

	inline int(__stdcall* OMovePlayer)(void* obj, Vector3 motion);
	inline int __stdcall MovePlayer(void* obj, Vector3 motion)
	{
		if (Variables::InfiniteJump)
		{
			if (Utils::KeyPressed(VK_SPACE))
				motion = Vector3(0, 0.5f, 0); // UnityEngine.CharacterController->Move
		}



		return OMovePlayer(obj, motion);
	}

	inline void(__stdcall* O)(void* obj);
}