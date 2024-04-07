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

	// UnityEngine
	inline bool GameSpeed = false;	
	inline float SpeedMultipler = 2.0f;
	inline int GameSpeedKey = VK_F1;

	// WeaponSounds
	inline bool NoRecoil = false;
	inline bool InfiniteRange = false;
	inline bool FullAuto = false;
	inline bool ZoomXRay = false;
	inline bool InstantADS = false;
	inline bool ForceCriticals = false;
	inline bool ForceEffects = false;
	inline bool InfiniteAmmo = false;
	inline bool InstantCharge = false;
	inline bool ScoreModifier = false;
	inline bool AOEBullets = false;
	inline bool NoSpread = false;
	inline bool FrostAura = false;

	// WeaponSounds->ForceEffects
	inline bool PoisonEffect = false;
	inline bool CharmEffect = false;
	inline bool BlindEffect = false;
	inline bool WeaknessEffect = false;
	inline bool LightningEffect = false;
	inline bool CurseEffect = false;
	inline bool StunEffect = false;

	// PlayerMoveC
	inline bool XRay = false;
	inline bool HealOnline = false;
	inline bool AmmoOnline = false;
	inline bool Invisibility = false;
	inline bool JetpackFly = true;

	// Misc
	inline bool PlayerSpeed = false;
	inline float InfiniteJump = false;
	inline int AirStuck = true;
}