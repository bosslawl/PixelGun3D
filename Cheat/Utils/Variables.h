#pragma once
#include "../../Utils/Utils.h"
#include "../../Utils/Math/Vectors/Vector2.h"

// inline

namespace Variables {
	inline Vector2 ScreenSize = { 0, 0 };
	inline Vector2 ScreenCenter = { 0, 0 };

	// Misc
	inline bool EnableCircleFov = false;
	inline float CircleFov = 120.f;
	inline ImColor CircleColour = ImColor(255.0f / 255, 255.0f / 255, 255.0f / 255);

	inline bool EnableCrosshair = false;
	inline float CrosshairSize = 5.0f;
	inline ImColor CrosshairColor = ImColor(255.0f / 255, 255.0f / 255, 255.0f / 255);

	inline bool EnableWatermark = true;
	inline bool EnableFPS = true;
	inline ImColor WatermarkColor = ImColor(255.0f / 255, 255.0f / 255, 255.0f / 255);

	inline bool EnableRainbowCircle = false;
	inline bool EnableRainbowCrosshair = false;
	inline bool EnableRainbowWatermark = false;

	inline ImVec4 RainbowColor = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);

	inline bool ImGuiDemo = false;

	// UnityEngine
	inline bool GameSpeed = false;	
		inline float GSpeedMultiplier = 2.0f;
		inline int GameSpeedKey = VK_F1;
	inline float InfiniteJump = false;
		inline int JumpKey = VK_SPACE;

	// WeaponSounds
	inline bool RecoilModifier = false;
		inline float RecoilValue = 0.0f;
	inline bool RangeModifier = false;
		inline float RangeValue = 1000000.0f;
	inline bool FullAuto = false;
	inline bool ZoomXRay = false;
	inline bool ScopeModifier = false;
		inline float ScopeValue = 1000000.0f;
	inline bool ForceCriticals = false;
	inline bool InfiniteAmmo = false;
	inline bool ChargeModifier = false;
		inline float ChargeMax = 0.0f;
		inline float ChargeDuration = 0.0f;
	inline bool ScoreModifier = false;
		inline float KillModifier = 1000000.0f;
		inline float AssistModifier = 1000000.0f;
		inline float RevengeModifier = 1000000.0f;
	inline bool AOEBullets = false;
		inline float FrontAngle = 360.0f;
		inline float BackAngle = 360.0f;
		inline float AOERadius = 1000000.0f;
		inline float FrontMultiplier = 5.0f;
		inline float BackMultiplier = 5.0f;
		inline float SideMultiplier = 5.0f;
	inline bool NoSpread = false;
	inline bool FrostAura = false;
		inline float AuraAngle = 360.0f;
		inline float AuraRadius = 1000000.0f;
		inline float AuraMultiplier = 5.0f;
	inline bool ForcePolymorpher = false;
		inline float PolymorpherDuration = 1000000.0f;
		inline float PolymorpherHealth = 1000000.0f;
		inline float PolymorpherType = 0;
	inline bool ForceEffects = false;

	// WeaponSounds->ForceEffects
	inline bool PoisonEffect = false;
		inline float PoisonCount = 1000000.0f;
		inline float PoisonMultiplier = 5.0f;
		inline float PoisonDuration = 1000000.0f;
	inline bool StunEffect = false;
		inline float StunMultiplier = 5.0f;
		inline float StunDuration = 1000000.0f;
		inline float StunRadius = 1000000.0f;
	inline bool CurseEffect = false;
		inline float CurseDuration = 1000000.0f;
		inline float CurseMultiplier = 5.0f;
	inline bool CharmEffect = false;
		inline float CharmDuration = 1000000.0f;
	inline bool BlindEffect = false;
		inline float BlindDuration = 1000000.0f;
	inline bool WeaknessEffect = false;
		inline float WeaknessDuration = 1000000.0f;
	inline bool LightningEffect = false;

	// PlayerMoveC
	inline bool XRay = false;
	inline bool HealOnline = false;
		inline float HealthValue = 50.0f;
	inline bool AmmoOnline = false;
		inline float AmmoValue = 50.0f;
	inline bool Invisibility = false;
	inline bool JetpackFly = false;

	// Misc
	inline bool PlayerSpeed = false;
		inline float SpeedValue = 1.0f;
	inline bool Godmode = false;
}