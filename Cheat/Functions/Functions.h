#pragma once
#include "../Utils/Offsets.h"

// inline

namespace GameFunctions {
	inline bool (UNITY_CALLING_CONVENTION isdebug)();
	inline bool isdebug_h() {
		return true;
	}

	inline void SetTimeScale(float TimeScale)
	{
		void (UNITY_CALLING_CONVENTION set_time_scale)(float TimeScale);
		reinterpret_cast<decltype(set_time_scale)>(Offsets::TimeOffset)(TimeScale);
	}
}