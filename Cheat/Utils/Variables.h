#pragma once
#include "../../Utils/Utils.h"
#include "../../Utils/Math/Vectors/Vector2.h"

// put 'inline' keyword to every variable or u getting errors

namespace Variables {
	inline Vector2 ScreenSize = { 0, 0 };
	inline Vector2 ScreenCenter = { 0, 0 };

	inline std::string SavedHWID;

	inline bool Test = false;

	inline bool EnableFOV = false;
	inline float FOV = 120.f;

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

	inline bool GameSpeed = false;	
	inline float SpeedMultipler = 2.0f;
	inline int GameSpeedKey = VK_F1;

	inline ImVec4 RainbowColor = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
}