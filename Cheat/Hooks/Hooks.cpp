#include "Hooks.h"
#include "../Functions/Functions.h"

Hooks RunHooks;
Signatures RunSignatures;

void Hooks::Load(FILE* f)
{
	Hooks::LoadConsole(f); // need to put this first in case of melonloader junking your console
	Hooks::LoadModules();
	// this function calls when ur injecting ur dll
	#ifdef _DEBUG
	RunSignatures.SearchSignatures(true); // true, so you getting also the addresses to your console
	#else
	RunSignatures.SearchSignatures(false); // false, so you getting the addresses to the console
	#endif
	Hooks::LoadMinHookHooks();
}

void Hooks::LoadModules()
{
	if (IL2CPP::Initialize(true))
	{	
		#ifdef _DEBUG
		UnitySDK::UnityGameBase = (uintptr_t)GetModuleHandleA(NULL);
		printf(OBFUSCATE("[ @bosslawl ] Base Address: 0x%llX\n"), UnitySDK::UnityGameBase);
		UnitySDK::UnityGameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
		printf(OBFUSCATE("[ @bosslawl ] GameAssembly Base Address: 0x%llX\n"), UnitySDK::UnityGameAssembly);
		UnitySDK::UnityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
		printf(OBFUSCATE("[ @bosslawl ] UnityPlayer Base Address: 0x%llX\n"), UnitySDK::UnityPlayer);
		#endif
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		printf(OBFUSCATE("[ @bosslawl ] IL2CPP Initialized\n"));
	}

	IL2CPP::Callback::Initialize();
}

void Hooks::LoadConsole(FILE* f)
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	const char* narrowTitle = OBFUSCATE("@bosslawl");
	int length = MultiByteToWideChar(CP_UTF8, 0, narrowTitle, -1, NULL, 0);
	wchar_t* wideTitle = new wchar_t[length];
	MultiByteToWideChar(CP_UTF8, 0, narrowTitle, -1, wideTitle, length);
	SetConsoleTitle(wideTitle);
	delete[] wideTitle;
	freopen_s(&f, "CONOUT$", "w", stdout);
	system(OBFUSCATE("cls"));
	ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
}

void Hooks::LoadMinHookHooks()
{
	MH_Initialize();

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(Offsets::IsDebugBuild), &GameFunctions::isdebug_h, (LPVOID*)&GameFunctions::isdebug) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*>(Offsets::IsDebugBuild));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACOne), &GameFunctions::ACOne, (LPVOID*)&GameFunctions::OACOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwo), &GameFunctions::ACTwo, (LPVOID*)&GameFunctions::OACTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThree), &GameFunctions::ACThree, (LPVOID*)&GameFunctions::OACThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate), &GameFunctions::PlayerMoveC, (LPVOID*)&GameFunctions::OPlayerMoveC) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate), &GameFunctions::WeaponSounds, (LPVOID*)&GameFunctions::OWeaponSounds) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::SpeedModifier), &GameFunctions::SpeedModifier, (LPVOID*)&GameFunctions::OSpeedModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::SpeedModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MovePlayer), &GameFunctions::MovePlayer, (LPVOID*)&GameFunctions::OMovePlayer) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MovePlayer));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GodmodeOne), &GameFunctions::GodmodeOne, (LPVOID*)&GameFunctions::OGodmodeOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GodmodeOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GodmodeTwo), &GameFunctions::GodmodeTwo, (LPVOID*)&GameFunctions::OGodmodeTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GodmodeTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::InfiniteGems), &GameFunctions::InfiniteGems, (LPVOID*)&GameFunctions::OInfiniteGems) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::InfiniteGems));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::NoReload), &GameFunctions::ReloadModifier, (LPVOID*)&GameFunctions::OReloadModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::NoReload));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GadgetCooldown), &GameFunctions::GadgetCooldown, (LPVOID*)&GameFunctions::OGadgetCooldown) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GadgetCooldown));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetEngineUpdate), &GameFunctions::PetEngine, (LPVOID*)&GameFunctions::OPetEngine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetEngineUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetDamage), &GameFunctions::PetDamage, (LPVOID*)&GameFunctions::OPetDamage) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetDamage));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetSpeed), &GameFunctions::PetSpeed, (LPVOID*)&GameFunctions::OPetSpeed) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetSpeed));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Lottery), &GameFunctions::Lottery, (LPVOID*)&GameFunctions::OLottery) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Lottery));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::FireRate), &GameFunctions::FireRate, (LPVOID*)&GameFunctions::OFireRate) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::FireRate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MaxLevelOne), &GameFunctions::Level, (LPVOID*)&GameFunctions::OLevel) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MaxLevelOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MaxLevelTwo), &GameFunctions::Experience, (LPVOID*)&GameFunctions::OExperience) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MaxLevelTwo));
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