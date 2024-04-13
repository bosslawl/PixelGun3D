#pragma once
#include "../Utils/Offsets.h"
#include "../Utils/Variables.h"

typedef struct _monoString
{
	void* klass;
	void* monitor;
	int length;
	char chars[1];

	int getLength()
	{
		return length;
	}

	const char* getChars()
	{
		return chars;
	}
}MonoString;

struct AnalyticsParams {
	int enum1;
	int enum2;
	int enum3;
	int enum4;
	int enum5;
	int enum6;
	int enum7;
	bool boolean1;
	void* klass1;
	int enum8;
	bool boolean2;
	int enum9;
	void* klass2;
	bool boolean3;
	int enum10;
	int integer1;
};

inline AnalyticsParams URLParams = { 0x0, 0x82, 0x18, 0x0, 0x0, 0x0, 0x0, false, nullptr, 0x0, false, 0x0, nullptr, false, 0x1, 0 };
inline const char* CurrencyList[] = { OBFUSCATE("GemsCurrency"), OBFUSCATE("Coins"), OBFUSCATE("ClanSilver"), OBFUSCATE("ClanLootBoxPoints"),  OBFUSCATE("Coupons"), OBFUSCATE("PixelPassCurrency"), OBFUSCATE("RouletteAdsCurrency"), OBFUSCATE("RouletteAdsSpin"), OBFUSCATE("PixelBucks"), OBFUSCATE("BattlePassCurrency"), OBFUSCATE("CurrencyCompetitionTier1"), OBFUSCATE("CurrencyCompetitionTier2"), OBFUSCATE("KeySmallChest"), OBFUSCATE("KeyEventChest"), OBFUSCATE("KeyBigChest"), OBFUSCATE("EventChestsSuperSpin"), OBFUSCATE("EventRouletteSuperSpin"), OBFUSCATE("EventRouletteSuperSpin"), OBFUSCATE("Exp"), OBFUSCATE("TankKeys"), OBFUSCATE("PixelPassExp"), OBFUSCATE("clan_building_black_market_point"), OBFUSCATE("MainModeSlotTokens"), OBFUSCATE("SmallChest"), OBFUSCATE("BigChest"), OBFUSCATE("EventChest"), OBFUSCATE("MegaChest") };
inline void (*SetSomething) (void* instance, int value, int number, MonoString* type);
// inline

namespace Internal {
	inline uintptr_t getAbsolute(uintptr_t addr) {
		if (addr != 0) {
			return UnitySDK::UnityGameAssembly + addr;
		}
		return 0;
	}

	inline MonoString* CreateIL2CPPString(const char* ptr)
	{
		static MonoString* (*CreateIL2CPPString)(const char* ptr, int* s, int* len) = 
			(MonoString * (*)(const char* ptr, int* s, int* len))(getAbsolute(Offsets::StringOffset));
		int* s = 0;
		int* len = (int*)strlen(ptr);
		return CreateIL2CPPString(ptr, s, len);
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

	inline void* TextMeshGetText(void* obj)
	{
		if (!obj) return nullptr;
		static const auto fn = (void*(*)(void*)) (getAbsolute(Offsets::TextMesh));
		return fn(obj);
	}

	inline std::string GetPlayerName(void* player_move_c)
	{
		void* nick_label = (void*)*(uint64_t*)((uint64_t)player_move_c + 0x3B8);
		void* name_ptr = Internal::TextMeshGetText(nick_label);
		if (name_ptr == nullptr) return "";
		std::string name = ((Unity::System_String*)name_ptr)->ToString();
		return Utils::CleanString(name);
	}

	inline bool IsMyPlayer(void* player_move_c)
	{
		return GetPlayerName(player_move_c) == "1111";
	}

	inline bool IsMyWeaponSounds(void* weapon_sounds)
	{
		void* player_move_c = (void*)*(uint64_t*)((uint64_t)weapon_sounds + 0x500);
		if (player_move_c == nullptr) return false;
		return IsMyPlayer(player_move_c);
	}

	// Misc

	inline void* WebInstance()
	{
		static void* (*WebInstance)() = (void* (*)())(getAbsolute(Offsets::WebInstance));
		return WebInstance();
	}

	inline void* AddCurrency(void* obj, MonoString* type, int value, int reason, AnalyticsParams params)
	{
		if (!obj) return nullptr;
		static const auto fn = (void* (*)(void*, MonoString*, int, int, bool, bool, AnalyticsParams)) (getAbsolute(Offsets::AddCurrency));
		return fn(obj, type, value, reason, false, false, params);
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

	inline void(__stdcall* OACFourtyFour)();
	inline void __stdcall ACFourtyFour()
	{
		return; 
	}

	inline void(__stdcall* OACFourtyFive)();
	inline void __stdcall ACFourtyFive()
	{
		return; 
	}

	inline void(__stdcall* OACFourtySix)();
	inline void __stdcall ACFourtySix()
	{
		return; 
	}

	inline void(__stdcall* OACFourtySeven)();
	inline void __stdcall ACFourtySeven()
	{
		return; 
	}

	inline void(__stdcall* OACFourtyEight)();
	inline void __stdcall ACFourtyEight()
	{
		return; 
	}

	inline void(__stdcall* OACFourtyNine)();
	inline void __stdcall ACFourtyNine()
	{
		return; 
	}

	inline void(__stdcall* OACFifty)();
	inline void __stdcall ACFifty()
	{
		return; 
	}

	inline void(__stdcall* OACFiftyOne)();
	inline void __stdcall ACFiftyOne()
	{
		return; 
	}

	inline void(__stdcall* OACFiftyTwo)();
	inline void __stdcall ACFiftyTwo()
	{
		return; 
	}

	inline void(__stdcall* OACFiftyThree)();
	inline void __stdcall ACFiftyThree()
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

		//void* playerDamageable = *(void**)((uintptr_t)obj + String2Offset(OBFUSCATE("0x650")));

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
		if (Variables::IsAddCurrency)
		{
			Internal::AddCurrency(Internal::WebInstance(), Internal::CreateIL2CPPString(CurrencyList[Variables::SelectedCurrency]), Variables::CurrencyAmount, 0, URLParams);
			Variables::IsAddCurrency = false;
		}

		if (Variables::RecoilModifier)
		{
			*(float*)((uint64_t)obj + FieldOffsets::RecoilCeoff) = Variables::RecoilValue;
			*(float*)((uint64_t)obj + FieldOffsets::RecoilCeoffZoom) = Variables::RecoilValue;
			*(float*)((uint64_t)obj + FieldOffsets::ScatterCeoff) = Variables::RecoilValue;
			*(float*)((uint64_t)obj + FieldOffsets::ScatterCeoffZoom) = Variables::RecoilValue;
		}

		if (Variables::RangeModifier)
		{
			*(float*)((uint64_t)obj + FieldOffsets::Range) = Variables::RangeValue;
			*(float*)((uint64_t)obj + FieldOffsets::DamageRange) = Variables::DamageRange;
			*(float*)((uint64_t)obj + FieldOffsets::ShootDistance) = Variables::ShootDistance;
		}

		if (Variables::FullAuto)
		{
			*(float*)((uint64_t)obj + FieldOffsets::ShootDelay) = Variables::ShootDelay;
			*(float*)((uint64_t)obj + FieldOffsets::BulletDelay) = Variables::BulletDelay;
			*(float*)((uint64_t)obj + FieldOffsets::BurstDelay) = Variables::DelayInBurstShooting;
			*(float*)((uint64_t)obj + FieldOffsets::ChargeTime) = Variables::ChargeTime;
		}

		if (Variables::ZoomXRay)
			*(bool*)((uint64_t)obj + FieldOffsets::ZoomXRay) = true;

		if (Variables::ScopeModifier)
		{
			*(float*)((uint64_t)obj + FieldOffsets::ScopeSpeed) = Variables::ScopeValue;
			if (Variables::ForceScope)
				*(bool*)((uint64_t)obj + FieldOffsets::Zooming) = true;
		}

		if (Variables::ForceCriticals)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::FirstCritical) = true;
			Internal::NextHitCritical(obj, true);
		}

		if (Variables::InfiniteAmmo)
			*(bool*)((uint64_t)obj + FieldOffsets::UnlimitedAmmo) = true;

		if (Variables::ChargeModifier)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::ChargeLoop) = true;
			*(int*)((uint64_t)obj + FieldOffsets::ChargeMax) = Variables::ChargeMax;
			*(float*)((uint64_t)obj + FieldOffsets::ChargeTime) = Variables::ChargeDuration;
			*(bool*)((uint64_t)obj + FieldOffsets::Charging) = false;
		}

		if (Variables::ScoreModifier)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::BuffPoints) = true;
			*(bool*)((uint64_t)obj + FieldOffsets::BuffPointsKill) = true;
			*(bool*)((uint64_t)obj + FieldOffsets::BuffPointsAssist) = true;
			*(bool*)((uint64_t)obj + FieldOffsets::BuffPointsRevenge) = true;
			*(float*)((uint64_t)obj + FieldOffsets::BonusPointsKill) = Variables::KillModifier;
			*(float*)((uint64_t)obj + FieldOffsets::BonusPointsAssist) = Variables::AssistModifier;
			*(float*)((uint64_t)obj + FieldOffsets::BonusPointsRevenge) = Variables::RevengeModifier;
		}

		if (Variables::AOEBullets)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::SectorsAOE) = true; // isSectorsAOE 
			*(bool*)((uint64_t)obj + FieldOffsets::Flamethrower) = false; // flamethrower 
			*(bool*)((uint64_t)obj + FieldOffsets::Railgun) = false; // railgun 
			*(bool*)((uint64_t)obj + FieldOffsets::Bazooka) = false; // bazooka 
			*(bool*)((uint64_t)obj + FieldOffsets::Harpoon) = false; // harpoon 
			*(float*)((uint64_t)obj + FieldOffsets::FrontAngle) = Variables::FrontAngle; // sectorsAOEAngleFront 
			*(float*)((uint64_t)obj + FieldOffsets::BackAngle) = Variables::BackAngle; // sectorsAOEAngleBack
			*(float*)((uint64_t)obj + FieldOffsets::FrontMultiplier) = Variables::FrontMultiplier; // sectorsAOEDamageMultiplierFront 
			*(float*)((uint64_t)obj + FieldOffsets::BackMultiplier) = Variables::BackMultiplier; // sectorsAOEDamageMultiplierBack 
			*(float*)((uint64_t)obj + FieldOffsets::SideMultiplier) = Variables::SideMultiplier; // sectorsAOEDamageMultiplierSide 
			*(float*)((uint64_t)obj + FieldOffsets::SectorsRadiusAOE) = Variables::AOERadius; // sectorsAOERadiusSectorsAoE 
		}

		if (Variables::NoSpread)
		{
			*(float*)((uint64_t)obj + FieldOffsets::KoofZoom) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::UpKoof) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::DownKoofFirst) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::DownKoofZoom) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::MaxKoof) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::TekKoof) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::UpKoofFire) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::DownKoofFire) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::DownKoof) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::TekKoofTimer) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::TekKoofRateTimer) = 0;
			*(float*)((uint64_t)obj + FieldOffsets::TekKoofTime) = 0;
			*(Vector2*)((uint64_t)obj + FieldOffsets::StartZone) = Vector2(0, 0);
		}

		if (Variables::FrostAura)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::FrostSword) = true;
			*(float*)((uint64_t)obj + FieldOffsets::FrostRadius) = Variables::AuraRadius;
			*(bool*)((uint64_t)obj + FieldOffsets::UseFrostAngle) = true;
			*(float*)((uint64_t)obj + FieldOffsets::FrostAngle) = Variables::AuraAngle;
			*(float*)((uint64_t)obj + FieldOffsets::FrostTime) = 0.33f;
			*(float*)((uint64_t)obj + FieldOffsets::FrostMultiplier) = Variables::AuraMultiplier;
		}

		if (Variables::ForcePolymorpher)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Polymorpher) = true;
			*(float*)((uint64_t)obj + FieldOffsets::PolymorpherTime) = Variables::PolymorpherDuration;
			*(float*)((uint64_t)obj + FieldOffsets::PolymorpherHealth) = Variables::PolymorpherHealth;
			*(int*)((uint64_t)obj + FieldOffsets::PolymorpherType) = Variables::PolymorpherType;
		}

		if (Variables::PoisonEffect)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Poisoning) = true;
			*(int*)((uint64_t)obj + FieldOffsets::PoisonCount) = Variables::PoisonCount;
			*(float*)((uint64_t)obj + FieldOffsets::PoisonTime) = Variables::PoisonMultiplier;
			*(float*)((uint64_t)obj + FieldOffsets::PoisonDamage) = Variables::PoisonDuration;
		}

		if (Variables::StunEffect)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Stun) = true;
			*(float*)((uint64_t)obj + FieldOffsets::StunCeoff) = Variables::StunMultiplier;
			*(float*)((uint64_t)obj + FieldOffsets::StunTime) = Variables::StunDuration;
			*(float*)((uint64_t)obj + FieldOffsets::StunRadius) = Variables::StunRadius;
		}

		if (Variables::CurseEffect)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Cursing) = true;
			*(float*)((uint64_t)obj + FieldOffsets::CursingTime) = Variables::CurseDuration;
			*(float*)((uint64_t)obj + FieldOffsets::CursingMultiplier) = Variables::CurseMultiplier;
		}

		if (Variables::CharmEffect)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Charm) = true;
			*(float*)((uint64_t)obj + FieldOffsets::CharmTime) = Variables::CharmDuration;
		}

		if (Variables::WeaknessEffect)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Weakness) = true;
			*(float*)((uint64_t)obj + FieldOffsets::WeaknessTime) = Variables::WeaknessDuration;
		}

		if (Variables::BlindEffect)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Blind) = true;
			*(float*)((uint64_t)obj + FieldOffsets::BlindTime) = Variables::BlindDuration;
		}

		if (Variables::LightningEffect)
			*(bool*)((uint64_t)obj + FieldOffsets::Lightning) = true;

		if (Variables::Shocker)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Shocker) = true;
			*(float*)((uint64_t)obj + FieldOffsets::ShockerRange) = Variables::ShockerRange;
			*(float*)((uint64_t)obj + FieldOffsets::ShockerMultiplier) = Variables::ShockerMultiplier;
		}

		if (Variables::IgnoreReflection)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::ReflectionDamage) = false;
			*(bool*)((uint64_t)obj + FieldOffsets::AbsorptionDamage) = false;
		}

		if (Variables::HeadMagnifier) {
			*(bool*)((uint64_t)obj + FieldOffsets::HeadMagnifier) = true;
			*(float*)((uint64_t)obj + FieldOffsets::MagnifierTime) = Variables::MagnifierDuration;
		}

		if (Variables::ReflectionRays)
			*(int*)((uint64_t)obj + FieldOffsets::ReflectionRays) = Variables::ReflectionCount;

		if (Variables::JumpDisabler)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::JumpDisabler) = true;
			*(float*)((uint64_t)obj + FieldOffsets::DisableTime) = Variables::JDisabledDuration;
		}

		if (Variables::Invisibility)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::RespawnInvisibility) = true;
			*(float*)((uint64_t)obj + FieldOffsets::RespawnInvisibilityTime) = Variables::SInvisibilityDuration;
			*(bool*)((uint64_t)obj + FieldOffsets::ReloadInvisibility) = true;
			*(bool*)((uint64_t)obj + FieldOffsets::KillInvisibility) = true;
			*(float*)((uint64_t)obj + FieldOffsets::KillInvisibilityTime) = Variables::SInvisibilityDuration;
		}

		if (Variables::FireImmunity)
			*(bool*)((uint64_t)obj + FieldOffsets::FireImmunity) = true;

		if (Variables::ToxicImmunity)
			*(bool*)((uint64_t)obj + FieldOffsets::ToxicImmunity) = true;

		if (Variables::BleedImmunity)
			*(bool*)((uint64_t)obj + FieldOffsets::BleedingImmunity) = true;

		if (Variables::SilentAim)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::SnowStorm) = true;
			*(float*)((uint64_t)obj + FieldOffsets::SnowStormMultplier) = Variables::SilentMultiplier;
			*(float*)((uint64_t)obj + FieldOffsets::SnowStormRange) = Variables::SilentRange;
			*(float*)((uint64_t)obj + FieldOffsets::Range) = Variables::SilentRange;
			*(float*)((uint64_t)obj + FieldOffsets::DamageRange) = Variables::SilentRange;
			*(float*)((uint64_t)obj + FieldOffsets::ShootDistance) = Variables::SilentRange;
		}

		if (Variables::EnemyMarker)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::EnemyMarker) = true;
			*(bool*)((uint64_t)obj + FieldOffsets::MarkerAiming) = true;
			*(bool*)((uint64_t)obj + FieldOffsets::MarkerRadius) = true;
			*(float*)((uint64_t)obj + FieldOffsets::MarkerChargeTime) = Variables::MarkerCharge;
		}

		if (Variables::Flamethrower)
			*(bool*)((uint64_t)obj + FieldOffsets::Flamethrower) = true;

		if (Variables::ExplosiveBullets)
			*(bool*)((uint64_t)obj + FieldOffsets::ExplosiveBullets) = true;

		if (Variables::Shotgun)
			*(bool*)((uint64_t)obj + FieldOffsets::Shotgun) = true;

		if (Variables::Railgun)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Railgun) = true;
			if (Variables::RailgunClipping)
				*(bool*)((uint64_t)obj + FieldOffsets::RailgunClipping) = false;
		}

		if (Variables::Bazooka)
			*(bool*)((uint64_t)obj + FieldOffsets::Bazooka) = true;

		if (Variables::Harpoon)
		{
			*(bool*)((uint64_t)obj + FieldOffsets::Harpoon) = true;
			*(float*)((uint64_t)obj + FieldOffsets::HarpoonDistance) = Variables::HarpoonDistance;
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