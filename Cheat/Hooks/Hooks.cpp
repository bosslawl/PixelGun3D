#include "Hooks.h"
#include "../Functions/Functions.h"

Hooks RunHooks;
Signatures RunSignatures;

void Hooks::Load(FILE* f)
{
	Hooks::LoadConsole(f); // need to put this first in case of melonloader junking your console
	Hooks::LoadModules();
	// this function calls when ur injecting ur dll
	RunSignatures.SearchSignatures(true); // true, so you getting also the addresses to your console
	Hooks::LoadMinHookHooks();
}

void Hooks::LoadModules()
{
	if (IL2CPP::Initialize(true))
	{	
		UnitySDK::UnityGameBase = (uintptr_t)GetModuleHandleA(NULL);
		printf("[ @bosslawl ] Base Address: 0x%llX\n", UnitySDK::UnityGameBase);
		UnitySDK::UnityGameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
		printf("[ @bosslawl ] GameAssembly Base Address: 0x%llX\n", UnitySDK::UnityGameAssembly);
		UnitySDK::UnityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
		printf("[ @bosslawl ] UnityPlayer Base Address: 0x%llX\n", UnitySDK::UnityPlayer);
	}

	IL2CPP::Callback::Initialize();
}

void Hooks::LoadConsole(FILE* f)
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	SetConsoleTitle(L"@bosslawl");
	freopen_s(&f, "CONOUT$", "w", stdout);
	system("cls");
}

void Hooks::LoadMinHookHooks()
{
	if (MH_CreateHook(reinterpret_cast<LPVOID*>(Offsets::IsDebugBuild), &GameFunctions::isdebug_h, (LPVOID*)&GameFunctions::isdebug) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*>(Offsets::IsDebugBuild));

	MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate), &GameFunctions::PlayerMoveC, (LPVOID*)&GameFunctions::OPlayerMoveC);
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate));

	MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate), &GameFunctions::WeaponSounds, (LPVOID*)&GameFunctions::OWeaponSounds);
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate));

	MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::SpeedModifier), &GameFunctions::SpeedModifier, (LPVOID*)&GameFunctions::OSpeedModifier);
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::SpeedModifier));

	MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MovePlayer), &GameFunctions::MovePlayer, (LPVOID*)&GameFunctions::OMovePlayer);
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MovePlayer));
}

void Hooks::UnloadMinHookHooks()
{
	MH_DisableHook(MH_ALL_HOOKS);
}

void Hooks::UnloadConsole(FILE* f)
{
	FreeConsole();
	if (f) fclose(f);
}

void Hooks::Unload(FILE* f)
{
	Hooks::UnloadMinHookHooks();
	IL2CPP::Callback::Uninitialize();
	Hooks::UnloadConsole(f);
	// don't uninitaliaze, backend going to do that!!!
}