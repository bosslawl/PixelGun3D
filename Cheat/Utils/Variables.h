#pragma once

#include "../../Utils/Math/Vectors/Vector2.h"
#include "../../Utils/Utils.h"

namespace Variables
{
    // Screen
    namespace Screen
    {
        inline Vector2 Size   = { 0, 0 };
        inline Vector2 Center = { 0, 0 };
    } // namespace Screen

    // Visuals
    namespace Visuals
    {
        inline bool EnableCircleFov        = false;
        inline float CircleFov             = 120.f;
        inline ImColor CircleColor         = ImColor(255.0f / 255, 255.0f / 255, 255.0f / 255);

        inline bool EnableCrosshair        = false;
        inline float CrosshairSize         = 5.0f;
        inline ImColor CrosshairColor      = ImColor(255.0f / 255, 255.0f / 255, 255.0f / 255);

        inline bool EnableWatermark        = true;
        inline bool EnableFPS              = true;
        inline ImColor WatermarkColor      = ImColor(255.0f / 255, 255.0f / 255, 255.0f / 255);

        inline bool EnableRainbowCircle    = false;
        inline bool EnableRainbowCrosshair = false;
        inline bool EnableRainbowWatermark = false;

        inline ImVec4 RainbowColor         = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

        inline bool ImGuiDemo              = false;
        inline bool EnableDumper           = false;
    } // namespace Visuals

    // Gameplay
    namespace Gameplay
    {
        inline bool GameSpeed                  = false;
        inline float GameSpeedMultiplier       = 2.0f;
        inline int GameSpeedKey                = VK_F1;

        inline bool FOVChanger                 = false;
        inline float FOVValue                  = 90.0f;

        // Player_move_c
        inline bool XRay                       = false;

        inline bool MatchInvisibility          = false;
        inline float MatchInvisibilityDuration = 1000000.0f;

        inline bool Invisibility               = false;
        inline float SelfInvisibilityDuration  = 1000000.0f;

        inline bool JetpackFly                 = false;

        inline bool PlayerSpeed                = false;
        inline float PlayerSpeedMultiplier     = 1000000.0f;

        inline bool Godmode                    = false;

        inline bool FireImmunity               = false;
        inline bool ToxicImmunity              = false;
        inline bool BleedImmunity              = false;

        inline bool EnemyMarker                = false;
        inline float MarkerCharge              = 1000000.0f;

        inline bool DoubleJump                 = false;

        inline bool AntiHeadshot               = false;
        inline float ReductionMultiplier       = 1000000.0f;

        inline bool FrostAura                  = false;
        inline float AuraAngle                 = 360.0f;
        inline float AuraRadius                = 1000000.0f;
        inline float AuraMultiplier            = 5.0f;
    } // namespace Gameplay

    // Weapon
    namespace Weapon
    {
        inline bool RecoilModifier        = false;
        inline float RecoilValue          = 0.0f;

        inline bool RangeModifier         = false;
        inline float RangeValue           = 1000000.0f;
        inline float DamageRange          = 1000000.0f;
        inline float ShootDistance        = 1000000.0f;

        inline bool FullAuto              = false;
        inline float ShootDelay           = 0.000001f;
        inline float BulletDelay          = 0.000001f;
        inline float DelayInBurstShooting = 0.000001f;
        inline float ChargeTime           = 0.000001f;

        inline bool ZoomXRay              = false;

        inline bool ScopeModifier         = false;
        inline float ScopeZoomValue       = 1000000.0f;
        inline bool ForceScope            = false;

        inline bool ForceCriticals        = false;

        inline bool InfiniteAmmo          = false;

        inline bool ChargeModifier        = false;
        inline float ChargeMax            = 0.0f;
        inline float ChargeDuration       = 0.0f;

        inline bool ScoreModifier         = false;
        inline float KillModifier         = 1000000.0f;
        inline float AssistModifier       = 1000000.0f;
        inline float RevengeModifier      = 1000000.0f;

        inline bool AOEBullets            = false;
        inline float FrontAngle           = 360.0f;
        inline float BackAngle            = 360.0f;
        inline float AOERadius            = 1000000.0f;
        inline float FrontMultiplier      = 5.0f;
        inline float BackMultiplier       = 5.0f;
        inline float SideMultiplier       = 5.0f;

        inline bool NoSpread              = false;

        inline bool ForcePolymorpher      = false;
        inline float PolymorpherDuration  = 1000000.0f;
        inline float PolymorpherHealth    = 1000000.0f;
        inline int PolymorpherType        = 0;

        inline bool PoisonEffect          = false;
        inline float PoisonCount          = 1000000.0f;
        inline float PoisonMultiplier     = 5.0f;
        inline float PoisonDuration       = 1000000.0f;
        inline bool StunEffect            = false;
        inline float StunMultiplier       = 5.0f;
        inline float StunDuration         = 1000000.0f;
        inline float StunRadius           = 1000000.0f;
        inline bool CurseEffect           = false;
        inline float CurseDuration        = 1000000.0f;
        inline float CurseMultiplier      = 5.0f;
        inline bool CharmEffect           = false;
        inline float CharmDuration        = 1000000.0f;
        inline bool BlindEffect           = false;
        inline float BlindDuration        = 1000000.0f;
        inline bool WeaknessEffect        = false;
        inline float WeaknessDuration     = 1000000.0f;
        inline bool LightningEffect       = false;
        inline bool Shocker               = false;
        inline float ShockerRange         = 1000000.0f;
        inline float ShockerMultiplier    = 5.0f;

        inline bool HeadMagnifier         = false;
        inline float MagnifierDuration    = 1000000.0f;

        inline bool ReflectionRays        = false;
        inline float ReflectionCount      = 50.0f;

        inline bool JumpDisabler          = false;
        inline float JumpDisabledDuration = 1000000.0f;

        inline bool SilentAim             = false;
        inline float SilentMultiplier     = 5.0f;
        inline float SilentRange          = 1000000.0f;

        inline bool Flamethrower          = false;
        inline bool ExplosiveBullets      = false;
        inline bool Shotgun               = false;
        inline bool Railgun               = false;
        inline bool RailgunClipping       = false;
        inline bool Bazooka               = false;
        inline bool Harpoon               = false;
        inline float HarpoonDistance      = 1000000.0f;

        inline bool FireRate              = false;
        inline float RapidValue           = 1000000.0f;

        inline bool ReloadModifier        = false;
        inline float ReloadValue          = 99999.0f;

        inline bool AntiBarrier           = false;
    } // namespace Weapon

    // Pet
    namespace Pet
    {
        inline bool PetHealth       = false;
        inline float PetHealthValue = 1000000.0f;
        inline bool PetDamage       = false;
        inline float PetDamageValue = 1000000.0f;
        inline bool PetSpeed        = false;
        inline float PetSpeedValue  = 1000000.0f;
    } // namespace Pet

    // Miscellaneous
    namespace Miscellaneous
    {
        inline bool InfiniteGems            = false;

        inline bool Lottery                 = false;
        inline float LotteryPrice           = 0.0f;

        inline bool AddCurrency             = false;
        inline float CurrencyAmount         = 1000.0f;
        inline int SelectedCurrency         = 0;
        inline bool IsAddCurrency           = false;

        inline bool HealthOnline            = false;

        inline bool PremiumPass             = false;

        inline bool MaxLevel                = false;
        inline bool MaxLevelOne             = false;
        inline bool MaxLevelTwo             = false;

        inline bool GadgetCooldown          = false;
        inline float CooldownValue          = 0.0f;

        inline bool RewardMultiplier        = false;
        inline float RewardMultiplierAmount = 10.0f;

        inline bool AddWeapons              = false;
        inline bool AddAllWeapons           = false;
        inline bool AddWeaponsDev           = false;
        inline std::string WeaponName       = "";
    } // namespace Miscellaneous
} // namespace Variables