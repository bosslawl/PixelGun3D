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

	inline void* MyPlayer;
	inline void* enemyPlayer;

	inline bool isMine(void* SkinName) {
		return *(bool*)((uint64_t)SkinName + 0xA8);
	}
	inline bool isDead(void* player)
	{
		bool (*IsDead)(void *player) = (bool(*)(void *))(UnitySDK::UnityGameAssembly + "0x473C00C"); // PlayerDamageable$$IsDead
		return IsDead(player);
	}
	inline bool isEnemy(void* player, void* enemy)
	{
		bool (*isEnemy)(void* player, void* enemy) = (bool(*)(void*, void*))(UnitySDK::UnityGameAssembly + "0x473BCB0"); // PlayerDamageable$$IsEnemyTo
		return isEnemy(player, enemy);
	}

	inline void(__stdcall* OPlayerMoveC)(void* obj);
	inline void __stdcall PlayerMoveC(void* obj)
	{
		void* SkinName = *(void**)((uint64_t)obj + 0x650);

		if (SkinName != nullptr) {
			if (isMine(SkinName)) {
				MyPlayer = SkinName;
				enemyPlayer = obj;
			}
		}

		return OPlayerMoveC(obj);
	}				
}