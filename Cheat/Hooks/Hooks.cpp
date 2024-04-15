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
		 
		UnitySDK::UnityGameBase = (uintptr_t)GetModuleHandleA(NULL);
		#ifdef _DEBUG
		printf(OBFUSCATE("\x1b[0m[ @\x1b[38;5;105mbosslawl \x1b[0m] Base Address: 0x%llX\n"), UnitySDK::UnityGameBase);
		#endif
		UnitySDK::UnityGameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
		#ifdef _DEBUG
		printf(OBFUSCATE("\x1b[0m[ @\x1b[38;5;105mbosslawl \x1b[0m] GameAssembly Base Address: 0x%llX\n"), UnitySDK::UnityGameAssembly);
		#endif
		UnitySDK::UnityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
		#ifdef _DEBUG
		printf(OBFUSCATE("\x1b[0m[ @\x1b[38;5;105mbosslawl \x1b[0m] UnityPlayer Base Address: 0x%llX\n"), UnitySDK::UnityPlayer);
		#endif
		std::cout << "\x1b[0m[ @\x1b[38;5;105mbosslawl \x1b[0m] \x1b[38;5;83mSuccessfully injected\x1b[0m" << std::endl;
	}

	IL2CPP::Callback::Initialize();
}

void Hooks::LoadConsole(FILE* f)
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	SetLayeredWindowAttributes(GetConsoleWindow(), 0, 230, LWA_ALPHA);
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
	if (MH_CreateHook(reinterpret_cast<LPVOID*>(Offsets::IsDebugBuild), &GameFunctions::isdebug_h, (LPVOID*)&GameFunctions::isdebug) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*>(Offsets::IsDebugBuild));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PreRender), &GameFunctions::PreRenderHook, (LPVOID*)&GameFunctions::OPreRenderHook) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PreRender));

	// AntiCheat bypass

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACOne), &GameFunctions::ACOne, (LPVOID*)&GameFunctions::OACOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwo), &GameFunctions::ACTwo, (LPVOID*)&GameFunctions::OACTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThree), &GameFunctions::ACThree, (LPVOID*)&GameFunctions::OACThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFour), &GameFunctions::ACFour, (LPVOID*)&GameFunctions::OACFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFive), &GameFunctions::ACFive, (LPVOID*)&GameFunctions::OACFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSix), &GameFunctions::ACSix, (LPVOID*)&GameFunctions::OACSix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSeven), &GameFunctions::ACSeven, (LPVOID*)&GameFunctions::OACSeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACEight), &GameFunctions::ACEight, (LPVOID*)&GameFunctions::OACEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACNine), &GameFunctions::ACNine, (LPVOID*)&GameFunctions::OACNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTen), &GameFunctions::ACTen, (LPVOID*)&GameFunctions::OACTen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACEleven), &GameFunctions::ACEleven, (LPVOID*)&GameFunctions::OACEleven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACEleven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwelve), &GameFunctions::ACTwelve, (LPVOID*)&GameFunctions::OACTwelve) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwelve));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirteen), &GameFunctions::ACThirteen, (LPVOID*)&GameFunctions::OACThirteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourteen), &GameFunctions::ACFourteen, (LPVOID*)&GameFunctions::OACFourteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFifteen), &GameFunctions::ACFifteen, (LPVOID*)&GameFunctions::OACFifteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFifteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSixteen), &GameFunctions::ACSixteen, (LPVOID*)&GameFunctions::OACSixteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSixteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSeventeen), &GameFunctions::ACSeventeen, (LPVOID*)&GameFunctions::OACSeventeen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSeventeen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACEighteen), &GameFunctions::ACEighteen, (LPVOID*)&GameFunctions::OACEighteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACEighteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACNineteen), &GameFunctions::ACNineteen, (LPVOID*)&GameFunctions::OACNineteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACNineteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwenty), &GameFunctions::ACTwenty, (LPVOID*)&GameFunctions::OACTwenty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwenty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyOne), &GameFunctions::ACTwentyOne, (LPVOID*)&GameFunctions::OACTwentyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyTwo), &GameFunctions::ACTwentyTwo, (LPVOID*)&GameFunctions::OACTwentyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyThree), &GameFunctions::ACTwentyThree, (LPVOID*)&GameFunctions::OACTwentyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyFour), &GameFunctions::ACTwentyFour, (LPVOID*)&GameFunctions::OACTwentyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyFive), &GameFunctions::ACTwentyFive, (LPVOID*)&GameFunctions::OACTwentyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentySix), &GameFunctions::ACTwentySix, (LPVOID*)&GameFunctions::OACTwentySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentySeven), &GameFunctions::ACTwentySeven, (LPVOID*)&GameFunctions::OACTwentySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyEight), &GameFunctions::ACTwentyEight, (LPVOID*)&GameFunctions::OACTwentyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyNine), &GameFunctions::ACTwentyNine, (LPVOID*)&GameFunctions::OACTwentyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirty), &GameFunctions::ACThirty, (LPVOID*)&GameFunctions::OACThirty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyOne), &GameFunctions::ACThirtyOne, (LPVOID*)&GameFunctions::OACThirtyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyTwo), &GameFunctions::ACThirtyTwo, (LPVOID*)&GameFunctions::OACThirtyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyThree), &GameFunctions::ACThirtyThree, (LPVOID*)&GameFunctions::OACThirtyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyFour), &GameFunctions::ACThirtyFour, (LPVOID*)&GameFunctions::OACThirtyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyFive), &GameFunctions::ACThirtyFive, (LPVOID*)&GameFunctions::OACThirtyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtySix), &GameFunctions::ACThirtySix, (LPVOID*)&GameFunctions::OACThirtySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtySeven), &GameFunctions::ACThirtySeven, (LPVOID*)&GameFunctions::OACThirtySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyEight), &GameFunctions::ACThirtyEight, (LPVOID*)&GameFunctions::OACThirtyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyNine), &GameFunctions::ACThirtyNine, (LPVOID*)&GameFunctions::OACThirtyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourty), &GameFunctions::ACFourty, (LPVOID*)&GameFunctions::OACFourty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyOne), &GameFunctions::ACFourtyOne, (LPVOID*)&GameFunctions::OACFourtyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyTwo), &GameFunctions::ACFourtyTwo, (LPVOID*)&GameFunctions::OACFourtyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyThree), &GameFunctions::ACFourtyThree, (LPVOID*)&GameFunctions::OACFourtyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyFour), &GameFunctions::ACFourtyFour, (LPVOID*)&GameFunctions::OACFourtyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyFive), &GameFunctions::ACFourtyFive, (LPVOID*)&GameFunctions::OACFourtyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtySix), &GameFunctions::ACFourtySix, (LPVOID*)&GameFunctions::OACFourtySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtySeven), &GameFunctions::ACFourtySeven, (LPVOID*)&GameFunctions::OACFourtySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyEight), &GameFunctions::ACFourtyEight, (LPVOID*)&GameFunctions::OACFourtyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyNine), &GameFunctions::ACFourtyNine, (LPVOID*)&GameFunctions::OACFourtyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFifty), &GameFunctions::ACFifty, (LPVOID*)&GameFunctions::OACFifty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFifty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFiftyOne), &GameFunctions::ACFiftyOne, (LPVOID*)&GameFunctions::OACFiftyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFiftyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFiftyTwo), &GameFunctions::ACFiftyTwo, (LPVOID*)&GameFunctions::OACFiftyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFiftyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFiftyThree), &GameFunctions::ACFiftyThree, (LPVOID*)&GameFunctions::OACFiftyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFiftyThree));

	// Player_move_c

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate), &GameFunctions::PlayerMoveC, (LPVOID*)&GameFunctions::OPlayerMoveC) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::SpeedModifier), &GameFunctions::SpeedModifier, (LPVOID*)&GameFunctions::OSpeedModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::SpeedModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GodmodeOne), &GameFunctions::GodmodeOne, (LPVOID*)&GameFunctions::OGodmodeOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GodmodeOne));

	// WeaponSounds

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate), &GameFunctions::WeaponSounds, (LPVOID*)&GameFunctions::OWeaponSounds) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate));

	// PetEngine

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetEngineUpdate), &GameFunctions::PetEngine, (LPVOID*)&GameFunctions::OPetEngine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetEngineUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetDamage), &GameFunctions::PetDamage, (LPVOID*)&GameFunctions::OPetDamage) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetDamage));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetSpeed), &GameFunctions::PetSpeed, (LPVOID*)&GameFunctions::OPetSpeed) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetSpeed));

	// Misc

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GodmodeTwo), &GameFunctions::GodmodeTwo, (LPVOID*)&GameFunctions::OGodmodeTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GodmodeTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::InfiniteGems), &GameFunctions::InfiniteGems, (LPVOID*)&GameFunctions::OInfiniteGems) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::InfiniteGems));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ReloadModifier), &GameFunctions::ReloadModifier, (LPVOID*)&GameFunctions::OReloadModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ReloadModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GadgetCooldown), &GameFunctions::GadgetCooldown, (LPVOID*)&GameFunctions::OGadgetCooldown) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GadgetCooldown));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Lottery), &GameFunctions::Lottery, (LPVOID*)&GameFunctions::OLottery) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Lottery));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::FireRate), &GameFunctions::FireRate, (LPVOID*)&GameFunctions::OFireRate) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::FireRate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MaxLevelOne), &GameFunctions::Level, (LPVOID*)&GameFunctions::OLevel) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MaxLevelOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MaxLevelTwo), &GameFunctions::Experience, (LPVOID*)&GameFunctions::OExperience) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MaxLevelTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PixelPass), &GameFunctions::PremiumPass, (LPVOID*)&GameFunctions::OPremiumPass) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PixelPass));
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