#pragma once
#include "../Utils/Offsets.h"
#include "../Utils/Variables.h"

typedef struct _monoString {
	void* klass;
	void* monitor;
	int length;
	char chars[1];

	int getLength() {
		return length;
	}

	std::string getChars() {
		return std::string(chars, length * 2);
	}
} MonoString;

struct AnalyticsParams {
	int enum1;
	int enum2;
	int enum3;
	int enum4;
	int enum5;
	int enum6;
	int enum7;
	bool bool1;
	void* klass1;
	int enum8;
	bool bool2;
	int enum9;
	void* klass2;
	bool bool3;
	int enum10;
	int int1;
};

inline AnalyticsParams URLParams = { 0x0, 0x82, 0x18, 0x0, 0x0, 0x0, 0x0, false, nullptr, 0x0, false, 0x0, nullptr, false, 0x1, 0 };
inline const char* CurrencyList[] = { OBFUSCATE("GemsCurrency"), OBFUSCATE("Coins"), OBFUSCATE("ClanSilver"), OBFUSCATE("ClanLootBoxPoints"),  OBFUSCATE("Coupons"), OBFUSCATE("PixelPassCurrency"), OBFUSCATE("RouletteAdsCurrency"), OBFUSCATE("RouletteAdsSpin"), OBFUSCATE("PixelBucks"), OBFUSCATE("BattlePassCurrency"), OBFUSCATE("CurrencyCompetitionTier1"), OBFUSCATE("CurrencyCompetitionTier2"), OBFUSCATE("KeySmallChest"), OBFUSCATE("KeyEventChest"), OBFUSCATE("KeyBigChest"), OBFUSCATE("EventChestsSuperSpin"), OBFUSCATE("EventRouletteSuperSpin"), OBFUSCATE("EventRouletteSuperSpin"), OBFUSCATE("Exp"), OBFUSCATE("TankKeys"), OBFUSCATE("PixelPassExp"), OBFUSCATE("clan_building_black_market_point"), OBFUSCATE("MainModeSlotTokens"), OBFUSCATE("SmallChest"), OBFUSCATE("BigChest"), OBFUSCATE("EventChest"), OBFUSCATE("MegaChest") };
inline void (*SetSomething) (void* instance, int value, int number, MonoString* type);
namespace Internal {
	inline uintptr_t getAbsolute(uintptr_t addr) {
		if (addr != 0) {
			return UnitySDK::UnityGameAssembly + addr;
		}
		return 0;
	}

	inline MonoString* CreateIL2CPPString(const char* str)
	{
		static MonoString* (*CreateIl2cppString)(const char* str, int* startIndex, int* length) =
			(MonoString * (*)(const char* str, int* startIndex, int* length))(getAbsolute(Offsets::UnityEngine::StringOffset));
		int* startIndex = 0;
		int* length = (int*)strlen(str);
		return CreateIl2cppString(str, startIndex, length);
	}

	// UnityEngine
	namespace UnityEngine {
		inline void SetTimeScale(float TimeScale)
		{
			void (UNITY_CALLING_CONVENTION set_time_scale)(float TimeScale);
			reinterpret_cast<decltype(set_time_scale)>(Offsets::UnityEngine::TimeOffset)(TimeScale);
		}

		inline Unity::CCamera* MainCamera()
		{
			Unity::CCamera* camera = Unity::Camera::GetMain();
			return camera;
		}

		inline void* TextMeshGetText(void* obj)
		{
			if (!obj) return nullptr;
			static const auto fn = (void* (*)(void*)) (Offsets::UnityEngine::TextMesh);
			return fn(obj);
		}
	}

	// Player_move_c
	namespace PlayerMoveC {
		inline std::string GetPlayerName(void* player_move_c)
		{
			void* nick_label = (void*)*(uint64_t*)((uint64_t)player_move_c + FieldOffsets::PlayerMoveC::NickLabel);
			void* name_ptr = Internal::UnityEngine::TextMeshGetText(nick_label);
			if (name_ptr == nullptr) return "";
			std::string name = ((Unity::System_String*)name_ptr)->ToString();
			return Utils::CleanString(name);
		}

		inline bool IsMyPlayer(void* player_move_c)
		{
			return GetPlayerName(player_move_c) == "1111";
		}

		inline void ShowXray(void* obj, bool a1, int a2, int a3) {
			if (!obj) return;
			static const auto fn = (void(*)(void*, bool, int, int)) (getAbsolute(Offsets::PlayerMoveC::XRay));
			return fn(obj, a1, a2, a3);
		}

		inline float MatchInvisibility(void* obj, float a1) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::PlayerMoveC::MatchInvisibility));
			return fn(obj, a1);
		}

		inline void JetpackFly(void* obj, bool a1) {
			if (!obj) return;
			static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::PlayerMoveC::JetpackFly));
			return fn(obj, a1);
		}

		inline float AddHealthFromWeaponOnline(void* obj, float a1, std::string a2) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float, std::string)) (getAbsolute(Offsets::Miscellaneous::HealthOnline));
			return fn(obj, a1, a2);
		}

		inline float AddAmmoFromWeaponOnline(void* obj, float a1) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::Miscellaneous::AmmoOnline));
			return fn(obj, a1);
		}
	}

	// WeaponSounds
	namespace WeaponSounds {
		inline bool IsMyWeaponSounds(void* weapon_sounds)
		{
			void* player_move_c = (void*)*(uint64_t*)((uint64_t)weapon_sounds + FieldOffsets::WeaponSounds::WeaponSoundsPlayer);
			if (player_move_c == nullptr) return false;
			return Internal::PlayerMoveC::IsMyPlayer(player_move_c);
		}

		inline void NextHitCritical(void* obj, bool a1) {
			if (!obj) return;
			static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::WeaponSounds::NextHitCritical));
			return fn(obj, a1);
		}
	}

	// PetEngine
	namespace PetEngine {
		inline float PetEngineHealth(void* obj, float a1) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::PetEngine::PetHealth));
			return fn(obj, a1);
		}
	}

	// Misc
	namespace Miscellaneous {
		inline void* WebInstance()
		{
			static void* (*WebInstance)() = (void* (*)())(getAbsolute(Offsets::Miscellaneous::WebInstance));
			return WebInstance();
		}

		inline void* AddCurrency(void* obj, MonoString* type, int value, int reason, AnalyticsParams params)
		{
			if (!obj) return nullptr;
			static const auto fn = (void* (*)(void*, MonoString*, int, int, bool, bool, AnalyticsParams)) (getAbsolute(Offsets::Miscellaneous::AddCurrency));
			return fn(obj, type, value, reason, false, false, params);
		}
	}
}

namespace GameFunctions {
	inline bool (UNITY_CALLING_CONVENTION isdebug)();
	inline bool isdebug_h() {
		return true;
	}

	// AntiCheat bypass
	namespace ACBypass {
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
	}

	// Player_move_c
	namespace PlayerMoveC {
		inline void(__stdcall* OPlayerMoveC)(void* obj);
		inline void __stdcall PlayerMoveC(void* obj)
		{
			if (Internal::PlayerMoveC::IsMyPlayer(obj))
			{
				if (Variables::Gameplay::XRay)
					Internal::PlayerMoveC::ShowXray(obj, true, 0, 0);

				if (Variables::Gameplay::Invisibility)
					Internal::PlayerMoveC::MatchInvisibility(obj, Variables::Gameplay::SelfInvisibilityDuration);

				if (Variables::Gameplay::JetpackFly)
					Internal::PlayerMoveC::JetpackFly(obj, true);
				else
					Internal::PlayerMoveC::JetpackFly(obj, false);

				void* playerDamageable = *(void**)((uintptr_t)obj + 0x650);

				if (Variables::Miscellaneous::HealthOnline)
					Internal::PlayerMoveC::AddHealthFromWeaponOnline(playerDamageable, 999999.0f, "");

				if (Variables::Miscellaneous::AmmoOnline)
					Internal::PlayerMoveC::AddAmmoFromWeaponOnline(playerDamageable, 999999.0f);
			}

			if (Variables::Gameplay::MatchInvisibility)
				Internal::PlayerMoveC::MatchInvisibility(obj, Variables::Gameplay::MatchInvisibilityDuration);
			return OPlayerMoveC(obj);
		}

		inline float(__stdcall* OSpeedModifier)(void* obj);
		inline float __stdcall SpeedModifier(void* obj)
		{
			if (Variables::Gameplay::PlayerSpeed)
				return Variables::Gameplay::PlayerSpeedMultiplier;

			return OSpeedModifier(obj);
		}

		inline void(__stdcall* OGodmodeOne)(...);
		inline void __stdcall GodmodeOne(void* obj, float a1, void* a2, void* a3, void* a4, void* a5, Vector3 a6, void* a7, int a8)
		{
			if (Variables::Gameplay::Godmode)
				return;

			return OGodmodeOne(obj, a1, a2, a3, a4, a5, a6, a7, a8);
		}
	}
	
	// WeaponSounds
	namespace WeaponSounds {
		inline void(__stdcall* OWeaponSounds)(void* obj);
		inline void __stdcall WeaponSounds(void* obj)
		{
			if (Internal::WeaponSounds::IsMyWeaponSounds(obj))
			{
				if (Variables::Miscellaneous::IsAddCurrency)
				{
					Internal::Miscellaneous::AddCurrency(Internal::Miscellaneous::WebInstance(), Internal::CreateIL2CPPString(CurrencyList[Variables::Miscellaneous::SelectedCurrency]), Variables::Miscellaneous::CurrencyAmount, 0, URLParams);
					Variables::Miscellaneous::IsAddCurrency = false;
				}

				if (Variables::Weapon::RecoilModifier)
				{
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::RecoilCeoff) = Variables::Weapon::RecoilValue;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::RecoilCeoffZoom) = Variables::Weapon::RecoilValue;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ScatterCeoff) = Variables::Weapon::RecoilValue;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ScatterCeoffZoom) = Variables::Weapon::RecoilValue;
				}

				if (Variables::Weapon::RangeModifier)
				{
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::Range) = Variables::Weapon::RangeValue;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DamageRange) = Variables::Weapon::DamageRange;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ShootDistance) = Variables::Weapon::ShootDistance;
				}

				if (Variables::Weapon::FullAuto)
				{
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ShootDelay) = Variables::Weapon::ShootDelay;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BulletDelay) = Variables::Weapon::BulletDelay;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BurstDelay) = Variables::Weapon::DelayInBurstShooting;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ChargeTime) = Variables::Weapon::ChargeTime;
				}

				if (Variables::Weapon::ZoomXRay)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ZoomXRay) = true;

				if (Variables::Weapon::ScopeModifier)
				{
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ScopeSpeed) = Variables::Weapon::ScopeZoomValue;
					if (Variables::Weapon::ForceScope)
						*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Zooming) = true;
				}

				if (Variables::Weapon::ForceCriticals)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::FirstCritical) = true;
					Internal::WeaponSounds::NextHitCritical(obj, true);
				}

				if (Variables::Weapon::InfiniteAmmo)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::UnlimitedAmmo) = true;

				if (Variables::Weapon::ChargeModifier)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ChargeLoop) = true;
					*(int*)((uint64_t)obj + FieldOffsets::WeaponSounds::ChargeMax) = Variables::Weapon::ChargeMax;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ChargeTime) = Variables::Weapon::ChargeDuration;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Charging) = false;
				}

				if (Variables::Weapon::ScoreModifier)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::BuffPoints) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::BuffPointsKill) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::BuffPointsAssist) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::BuffPointsRevenge) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BonusPointsKill) = Variables::Weapon::KillModifier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BonusPointsAssist) = Variables::Weapon::AssistModifier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BonusPointsRevenge) = Variables::Weapon::RevengeModifier;
				}

				if (Variables::Weapon::AOEBullets)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::SectorsAOE) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Flamethrower) = false;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Railgun) = false;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Bazooka) = false;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Harpoon) = false;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrontAngle) = Variables::Weapon::FrontAngle;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BackAngle) = Variables::Weapon::BackAngle;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrontMultiplier) = Variables::Weapon::FrontMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BackMultiplier) = Variables::Weapon::BackMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::SideMultiplier) = Variables::Weapon::SideMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::SectorsRadiusAOE) = Variables::Weapon::AOERadius;
				}

				if (Variables::Weapon::NoSpread)
				{
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::KoofZoom) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::UpKoof) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DownKoofFirst) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DownKoofZoom) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::MaxKoof) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::TekKoof) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::UpKoofFire) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DownKoofFire) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DownKoof) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::TekKoofTimer) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::TekKoofRateTimer) = 0;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::TekKoofTime) = 0;
					*(Vector2*)((uint64_t)obj + FieldOffsets::WeaponSounds::StartZone) = Vector2(0, 0);
				}

				if (Variables::Gameplay::FrostAura)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrostSword) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrostRadius) = Variables::Gameplay::AuraRadius;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::UseFrostAngle) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrostAngle) = Variables::Gameplay::AuraAngle;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrostTime) = 0.33f;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::FrostMultiplier) = Variables::Gameplay::AuraMultiplier;
				}

				if (Variables::Weapon::ForcePolymorpher)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Polymorpher) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::PolymorpherTime) = Variables::Weapon::PolymorpherDuration;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::PolymorpherHealth) = Variables::Weapon::PolymorpherHealth;
					*(int*)((uint64_t)obj + FieldOffsets::WeaponSounds::PolymorpherType) = Variables::Weapon::PolymorpherType;
				}

				if (Variables::Weapon::PoisonEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Poisoning) = true;
					*(int*)((uint64_t)obj + FieldOffsets::WeaponSounds::PoisonCount) = Variables::Weapon::PoisonCount;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::PoisonTime) = Variables::Weapon::PoisonMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::PoisonDamage) = Variables::Weapon::PoisonDuration;
				}

				if (Variables::Weapon::StunEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Stun) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::StunCeoff) = Variables::Weapon::StunMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::StunTime) = Variables::Weapon::StunDuration;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::StunRadius) = Variables::Weapon::StunRadius;
				}

				if (Variables::Weapon::CurseEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Cursing) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::CursingTime) = Variables::Weapon::CurseDuration;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::CursingMultiplier) = Variables::Weapon::CurseMultiplier;
				}

				if (Variables::Weapon::CharmEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Charm) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::CharmTime) = Variables::Weapon::CharmDuration;
				}

				if (Variables::Weapon::WeaknessEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Weakness) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::WeaknessTime) = Variables::Weapon::WeaknessDuration;
				}

				if (Variables::Weapon::BlindEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Blind) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::BlindTime) = Variables::Weapon::BlindDuration;
				}

				if (Variables::Weapon::LightningEffect)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Lightning) = true;

				if (Variables::Weapon::Shocker)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Shocker) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ShockerRange) = Variables::Weapon::ShockerRange;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ShockerMultiplier) = Variables::Weapon::ShockerMultiplier;
				}

				if (Variables::Weapon::HeadMagnifier) {
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::HeadMagnifier) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::MagnifierTime) = Variables::Weapon::MagnifierDuration;
				}

				if (Variables::Weapon::ReflectionRays)
					*(int*)((uint64_t)obj + FieldOffsets::WeaponSounds::ReflectionRays) = Variables::Weapon::ReflectionCount;

				if (Variables::Weapon::JumpDisabler)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::JumpDisabler) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DisableTime) = Variables::Weapon::JumpDisabledDuration;
				}

				if (Variables::Gameplay::Invisibility)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::RespawnInvisibility) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::RespawnInvisibilityTime) = Variables::Gameplay::SelfInvisibilityDuration;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ReloadInvisibility) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::KillInvisibility) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::KillInvisibilityTime) = Variables::Gameplay::SelfInvisibilityDuration;
				}

				if (Variables::Gameplay::FireImmunity)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::FireImmunity) = true;

				if (Variables::Gameplay::ToxicImmunity)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ToxicImmunity) = true;

				if (Variables::Gameplay::BleedImmunity)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::BleedingImmunity) = true;

				if (Variables::Weapon::SilentAim)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::SnowStorm) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::SnowStormMultplier) = Variables::Weapon::SilentMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::SnowStormRange) = Variables::Weapon::SilentRange;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::Range) = Variables::Weapon::SilentRange;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::DamageRange) = Variables::Weapon::SilentRange;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ShootDistance) = Variables::Weapon::SilentRange;
				}

				if (Variables::Gameplay::EnemyMarker)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::EnemyMarker) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::MarkerAiming) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::MarkerRadius) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::MarkerChargeTime) = Variables::Gameplay::MarkerCharge;
				}

				if (Variables::Weapon::Flamethrower)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Flamethrower) = true;

				if (Variables::Weapon::ExplosiveBullets)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ExplosiveBullets) = true;

				if (Variables::Weapon::Shotgun)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Shotgun) = true;

				if (Variables::Weapon::Railgun)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Railgun) = true;
					if (Variables::Weapon::RailgunClipping)
						*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::RailgunClipping) = false;
				}

				if (Variables::Weapon::Bazooka)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Bazooka) = true;

				if (Variables::Weapon::Harpoon)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::Harpoon) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::HarpoonDistance) = Variables::Weapon::HarpoonDistance;
				}

				if (Variables::Gameplay::DoubleJump)
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::DoubleJump) = true;

				if (Variables::Gameplay::AntiHeadshot)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ReducedHeadshotDamage) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::ReducedHeadshotDamageMultiplier) = Variables::Gameplay::ReductionMultiplier;
				}

				if (Variables::Gameplay::ArmourRegeneration)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::WeaponSounds::ArmourRegeneration) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaponSounds::RegenerationPercent) = Variables::Gameplay::RegenerationPercent;
				}
			}
			return OWeaponSounds(obj);
		}
	}

	// PetEngine
	namespace PetEngine {
		inline void(__stdcall* OPetEngine)(void* obj);
		inline void __stdcall PetEngine(void* obj)
		{
			if (Variables::Pet::PetHealth)
				Internal::PetEngine::PetEngineHealth(obj, Variables::Pet::PetHealthValue);

			return OPetEngine(obj);
		}

		inline float(__stdcall* OPetDamage)(void* obj);
		inline float __stdcall PetDamage(void* obj)
		{
			if (Variables::Pet::PetDamage)
				return Variables::Pet::PetDamageValue;

			return OPetDamage(obj);
		}

		inline float(__stdcall* OPetSpeed)(void* obj);
		inline float __stdcall PetSpeed(void* obj)
		{
			if (Variables::Pet::PetSpeed)
				return Variables::Pet::PetSpeedValue;

			return OPetSpeed(obj);
		}
	}

	// Misc 
	namespace Miscellaneous {
		inline void(__stdcall* OGodmodeTwo)(void* obj);
		inline void __stdcall GodmodeTwo(void* obj)
		{
			if (Variables::Gameplay::Godmode)
				return;

			return OGodmodeTwo(obj);
		}

		inline bool(__stdcall* OInfiniteGems)(void* obj);
		inline bool __stdcall InfiniteGems(void* obj)
		{
			if (Variables::Miscellaneous::InfiniteGems)
				return true;

			return OInfiniteGems(obj);
		}

		inline float(__stdcall* OReloadModifier)(void* obj, void* a1, void* a2, void* a3, void* a4);
		inline float __stdcall ReloadModifier(void* obj, void* a1, void* a2, void* a3, void* a4)
		{
			if (Variables::Weapon::ReloadModifier)
				return Variables::Weapon::ReloadValue;

			return OReloadModifier(obj, a1, a2, a3, a4);
		}

		inline float(__stdcall* OGadgetCooldown)(void* obj);
		inline float __stdcall GadgetCooldown(void* obj)
		{
			if (Variables::Miscellaneous::GadgetCooldown)
				return Variables::Miscellaneous::CooldownValue;

			return OGadgetCooldown(obj);
		}

		inline int(__stdcall* OLottery)(void* obj);
		inline int __stdcall Lottery(void* obj)
		{
			if (Variables::Miscellaneous::Lottery)
				return Variables::Miscellaneous::LotteryPrice;

			return OLottery(obj);
		}

		inline float(__stdcall* OFireRate)(int a1);
		inline float __stdcall FireRate(int a1)
		{
			if (Variables::Weapon::FireRate)
				return Variables::Weapon::RapidValue;

			return OFireRate(a1);
		}

		inline int(__stdcall* OExperience)(...);
		inline int __stdcall Experience(void* obj) {
			if (Variables::Miscellaneous::MaxLevelOne) {
				return 32465;
			}
			if (Variables::Miscellaneous::MaxLevelTwo) {
				return 2147451182;
			}

			return OExperience();
		}

		inline int(__stdcall* OLevel)(...);
		inline int __stdcall Level() {
			if (Variables::Miscellaneous::MaxLevelOne || Variables::Miscellaneous::MaxLevelTwo) {
				return 65;
			}

			return OLevel();
		}

		inline float(__stdcall* OPreRenderHook)(void* obj);
		inline float __stdcall PreRenderHook(void* obj)
		{
			if (Variables::Gameplay::FOVChanger)
				((Unity::CCamera*)Internal::UnityEngine::MainCamera)->SetFieldOfView(Variables::Gameplay::FOVValue);

			return OPreRenderHook(obj);
		}

		inline bool(__stdcall* OPremiumPass)(void* obj);
		inline bool __stdcall PremiumPass(void* obj)
		{
			if (Variables::Miscellaneous::PremiumPass)
				return true;

			return OPremiumPass(obj);
		}
	}
}