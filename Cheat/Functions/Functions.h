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
			(MonoString * (*)(const char* str, int* startIndex, int* length))(getAbsolute(Offsets::StringOffset));
		int* startIndex = 0;
		int* length = (int*)strlen(str);
		return CreateIl2cppString(str, startIndex, length);
	}

	// UnityEngine
	namespace UnityEngine {
		inline void SetTimeScale(float TimeScale)
		{
			void (UNITY_CALLING_CONVENTION set_time_scale)(float TimeScale);
			reinterpret_cast<decltype(set_time_scale)>(Offsets::TimeOffset)(TimeScale);
		}

		inline Unity::CCamera* MainCamera()
		{
			Unity::CCamera* camera = Unity::Camera::GetMain();
			return camera;
		}

		inline void* TextMeshGetText(void* obj)
		{
			if (!obj) return nullptr;
			static const auto fn = (void* (*)(void*)) (Offsets::TextMesh);
			return fn(obj);
		}
	}

	// Player_move_c
	namespace PlayerMoveC {
		inline std::string GetPlayerName(void* player_move_c)
		{
			void* nick_label = (void*)*(uint64_t*)((uint64_t)player_move_c + FieldOffsets::NickLabel);
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

		inline float AddHealthFromWeaponOnline(void* obj, float a1, std::string a2) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float, std::string)) (getAbsolute(Offsets::HealthOnline));
			return fn(obj, a1, a2);
		}

		inline float AddAmmoFromWeaponOnline(void* obj, float a1) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::AmmoOnline));
			return fn(obj, a1);
		}
	}

	// WeaponSounds
	namespace WeaponSounds {
		inline bool IsMyWeaponSounds(void* weapon_sounds)
		{
			void* player_move_c = (void*)*(uint64_t*)((uint64_t)weapon_sounds + FieldOffsets::WeaponSoundsPlayer);
			if (player_move_c == nullptr) return false;
			return Internal::PlayerMoveC::IsMyPlayer(player_move_c);
		}

		inline void NextHitCritical(void* obj, bool a1) {
			if (!obj) return;
			static const auto fn = (void(*)(void*, bool)) (getAbsolute(Offsets::NextHitCritical));
			return fn(obj, a1);
		}
	}

	// PetEngine
	namespace PetEngine {
		inline float PetEngineHealth(void* obj, float a1) {
			if (!obj) return 0;
			static const auto fn = (float(*)(void*, float)) (getAbsolute(Offsets::PetHealth));
			return fn(obj, a1);
		}
	}

	// Misc
	namespace Miscellaneous {
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
					*(float*)((uint64_t)obj + FieldOffsets::RecoilCeoff) = Variables::Weapon::RecoilValue;
					*(float*)((uint64_t)obj + FieldOffsets::RecoilCeoffZoom) = Variables::Weapon::RecoilValue;
					*(float*)((uint64_t)obj + FieldOffsets::ScatterCeoff) = Variables::Weapon::RecoilValue;
					*(float*)((uint64_t)obj + FieldOffsets::ScatterCeoffZoom) = Variables::Weapon::RecoilValue;
				}

				if (Variables::Weapon::RangeModifier)
				{
					*(float*)((uint64_t)obj + FieldOffsets::Range) = Variables::Weapon::RangeValue;
					*(float*)((uint64_t)obj + FieldOffsets::DamageRange) = Variables::Weapon::DamageRange;
					*(float*)((uint64_t)obj + FieldOffsets::ShootDistance) = Variables::Weapon::ShootDistance;
				}

				if (Variables::Weapon::FullAuto)
				{
					*(float*)((uint64_t)obj + FieldOffsets::ShootDelay) = Variables::Weapon::ShootDelay;
					*(float*)((uint64_t)obj + FieldOffsets::BulletDelay) = Variables::Weapon::BulletDelay;
					*(float*)((uint64_t)obj + FieldOffsets::BurstDelay) = Variables::Weapon::DelayInBurstShooting;
					*(float*)((uint64_t)obj + FieldOffsets::ChargeTime) = Variables::Weapon::ChargeTime;
				}

				if (Variables::Weapon::ZoomXRay)
					*(bool*)((uint64_t)obj + FieldOffsets::ZoomXRay) = true;

				if (Variables::Weapon::ScopeModifier)
				{
					*(float*)((uint64_t)obj + FieldOffsets::ScopeSpeed) = Variables::Weapon::ScopeZoomValue;
					if (Variables::Weapon::ForceScope)
						*(bool*)((uint64_t)obj + FieldOffsets::Zooming) = true;
				}

				if (Variables::Weapon::ForceCriticals)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::FirstCritical) = true;
					Internal::WeaponSounds::NextHitCritical(obj, true);
				}

				if (Variables::Weapon::InfiniteAmmo)
					*(bool*)((uint64_t)obj + FieldOffsets::UnlimitedAmmo) = true;

				if (Variables::Weapon::ChargeModifier)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::ChargeLoop) = true;
					*(int*)((uint64_t)obj + FieldOffsets::ChargeMax) = Variables::Weapon::ChargeMax;
					*(float*)((uint64_t)obj + FieldOffsets::ChargeTime) = Variables::Weapon::ChargeDuration;
					*(bool*)((uint64_t)obj + FieldOffsets::Charging) = false;
				}

				if (Variables::Weapon::ScoreModifier)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::BuffPoints) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::BuffPointsKill) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::BuffPointsAssist) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::BuffPointsRevenge) = true;
					*(float*)((uint64_t)obj + FieldOffsets::BonusPointsKill) = Variables::Weapon::KillModifier;
					*(float*)((uint64_t)obj + FieldOffsets::BonusPointsAssist) = Variables::Weapon::AssistModifier;
					*(float*)((uint64_t)obj + FieldOffsets::BonusPointsRevenge) = Variables::Weapon::RevengeModifier;
				}

				if (Variables::Weapon::AOEBullets)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::SectorsAOE) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::Flamethrower) = false;
					*(bool*)((uint64_t)obj + FieldOffsets::Railgun) = false;
					*(bool*)((uint64_t)obj + FieldOffsets::Bazooka) = false;
					*(bool*)((uint64_t)obj + FieldOffsets::Harpoon) = false;
					*(float*)((uint64_t)obj + FieldOffsets::FrontAngle) = Variables::Weapon::FrontAngle;
					*(float*)((uint64_t)obj + FieldOffsets::BackAngle) = Variables::Weapon::BackAngle;
					*(float*)((uint64_t)obj + FieldOffsets::FrontMultiplier) = Variables::Weapon::FrontMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::BackMultiplier) = Variables::Weapon::BackMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::SideMultiplier) = Variables::Weapon::SideMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::SectorsRadiusAOE) = Variables::Weapon::AOERadius;
				}

				if (Variables::Weapon::NoSpread)
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

				if (Variables::Gameplay::FrostAura)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::FrostSword) = true;
					*(float*)((uint64_t)obj + FieldOffsets::FrostRadius) = Variables::Gameplay::AuraRadius;
					*(bool*)((uint64_t)obj + FieldOffsets::UseFrostAngle) = true;
					*(float*)((uint64_t)obj + FieldOffsets::FrostAngle) = Variables::Gameplay::AuraAngle;
					*(float*)((uint64_t)obj + FieldOffsets::FrostTime) = 0.33f;
					*(float*)((uint64_t)obj + FieldOffsets::FrostMultiplier) = Variables::Gameplay::AuraMultiplier;
				}

				if (Variables::Weapon::ForcePolymorpher)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Polymorpher) = true;
					*(float*)((uint64_t)obj + FieldOffsets::PolymorpherTime) = Variables::Weapon::PolymorpherDuration;
					*(float*)((uint64_t)obj + FieldOffsets::PolymorpherHealth) = Variables::Weapon::PolymorpherHealth;
					*(int*)((uint64_t)obj + FieldOffsets::PolymorpherType) = Variables::Weapon::PolymorpherType;
				}

				if (Variables::Weapon::PoisonEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Poisoning) = true;
					*(int*)((uint64_t)obj + FieldOffsets::PoisonCount) = Variables::Weapon::PoisonCount;
					*(float*)((uint64_t)obj + FieldOffsets::PoisonTime) = Variables::Weapon::PoisonMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::PoisonDamage) = Variables::Weapon::PoisonDuration;
				}

				if (Variables::Weapon::StunEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Stun) = true;
					*(float*)((uint64_t)obj + FieldOffsets::StunCeoff) = Variables::Weapon::StunMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::StunTime) = Variables::Weapon::StunDuration;
					*(float*)((uint64_t)obj + FieldOffsets::StunRadius) = Variables::Weapon::StunRadius;
				}

				if (Variables::Weapon::CurseEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Cursing) = true;
					*(float*)((uint64_t)obj + FieldOffsets::CursingTime) = Variables::Weapon::CurseDuration;
					*(float*)((uint64_t)obj + FieldOffsets::CursingMultiplier) = Variables::Weapon::CurseMultiplier;
				}

				if (Variables::Weapon::CharmEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Charm) = true;
					*(float*)((uint64_t)obj + FieldOffsets::CharmTime) = Variables::Weapon::CharmDuration;
				}

				if (Variables::Weapon::WeaknessEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Weakness) = true;
					*(float*)((uint64_t)obj + FieldOffsets::WeaknessTime) = Variables::Weapon::WeaknessDuration;
				}

				if (Variables::Weapon::BlindEffect)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Blind) = true;
					*(float*)((uint64_t)obj + FieldOffsets::BlindTime) = Variables::Weapon::BlindDuration;
				}

				if (Variables::Weapon::LightningEffect)
					*(bool*)((uint64_t)obj + FieldOffsets::Lightning) = true;

				if (Variables::Weapon::Shocker)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Shocker) = true;
					*(float*)((uint64_t)obj + FieldOffsets::ShockerRange) = Variables::Weapon::ShockerRange;
					*(float*)((uint64_t)obj + FieldOffsets::ShockerMultiplier) = Variables::Weapon::ShockerMultiplier;
				}

				if (Variables::Weapon::HeadMagnifier) {
					*(bool*)((uint64_t)obj + FieldOffsets::HeadMagnifier) = true;
					*(float*)((uint64_t)obj + FieldOffsets::MagnifierTime) = Variables::Weapon::MagnifierDuration;
				}

				if (Variables::Weapon::ReflectionRays)
					*(int*)((uint64_t)obj + FieldOffsets::ReflectionRays) = Variables::Weapon::ReflectionCount;

				if (Variables::Weapon::JumpDisabler)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::JumpDisabler) = true;
					*(float*)((uint64_t)obj + FieldOffsets::DisableTime) = Variables::Weapon::JumpDisabledDuration;
				}

				if (Variables::Gameplay::Invisibility)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::RespawnInvisibility) = true;
					*(float*)((uint64_t)obj + FieldOffsets::RespawnInvisibilityTime) = Variables::Gameplay::SelfInvisibilityDuration;
					*(bool*)((uint64_t)obj + FieldOffsets::ReloadInvisibility) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::KillInvisibility) = true;
					*(float*)((uint64_t)obj + FieldOffsets::KillInvisibilityTime) = Variables::Gameplay::SelfInvisibilityDuration;
				}

				if (Variables::Gameplay::FireImmunity)
					*(bool*)((uint64_t)obj + FieldOffsets::FireImmunity) = true;

				if (Variables::Gameplay::ToxicImmunity)
					*(bool*)((uint64_t)obj + FieldOffsets::ToxicImmunity) = true;

				if (Variables::Gameplay::BleedImmunity)
					*(bool*)((uint64_t)obj + FieldOffsets::BleedingImmunity) = true;

				if (Variables::Weapon::SilentAim)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::SnowStorm) = true;
					*(float*)((uint64_t)obj + FieldOffsets::SnowStormMultplier) = Variables::Weapon::SilentMultiplier;
					*(float*)((uint64_t)obj + FieldOffsets::SnowStormRange) = Variables::Weapon::SilentRange;
					*(float*)((uint64_t)obj + FieldOffsets::Range) = Variables::Weapon::SilentRange;
					*(float*)((uint64_t)obj + FieldOffsets::DamageRange) = Variables::Weapon::SilentRange;
					*(float*)((uint64_t)obj + FieldOffsets::ShootDistance) = Variables::Weapon::SilentRange;
				}

				if (Variables::Gameplay::EnemyMarker)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::EnemyMarker) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::MarkerAiming) = true;
					*(bool*)((uint64_t)obj + FieldOffsets::MarkerRadius) = true;
					*(float*)((uint64_t)obj + FieldOffsets::MarkerChargeTime) = Variables::Gameplay::MarkerCharge;
				}

				if (Variables::Weapon::Flamethrower)
					*(bool*)((uint64_t)obj + FieldOffsets::Flamethrower) = true;

				if (Variables::Weapon::ExplosiveBullets)
					*(bool*)((uint64_t)obj + FieldOffsets::ExplosiveBullets) = true;

				if (Variables::Weapon::Shotgun)
					*(bool*)((uint64_t)obj + FieldOffsets::Shotgun) = true;

				if (Variables::Weapon::Railgun)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Railgun) = true;
					if (Variables::Weapon::RailgunClipping)
						*(bool*)((uint64_t)obj + FieldOffsets::RailgunClipping) = false;
				}

				if (Variables::Weapon::Bazooka)
					*(bool*)((uint64_t)obj + FieldOffsets::Bazooka) = true;

				if (Variables::Weapon::Harpoon)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::Harpoon) = true;
					*(float*)((uint64_t)obj + FieldOffsets::HarpoonDistance) = Variables::Weapon::HarpoonDistance;
				}

				if (Variables::Gameplay::DoubleJump)
					*(bool*)((uint64_t)obj + FieldOffsets::DoubleJump) = true;

				if (Variables::Gameplay::AntiHeadshot)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::ReducedHeadshotDamage) = true;
					*(float*)((uint64_t)obj + FieldOffsets::ReducedHeadshotDamageMultiplier) = Variables::Gameplay::ReductionMultiplier;
				}

				if (Variables::Gameplay::ArmourRegeneration)
				{
					*(bool*)((uint64_t)obj + FieldOffsets::ArmourRegeneration) = true;
					*(float*)((uint64_t)obj + FieldOffsets::RegenerationPercent) = Variables::Gameplay::RegenerationPercent;
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