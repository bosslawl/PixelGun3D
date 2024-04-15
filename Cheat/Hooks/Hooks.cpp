#include "Hooks.h"
#include "../Functions/Functions.h"

Hooks RunHooks;
Signatures RunSignatures;

void Hooks::Load(FILE* f)
{
	Hooks::LoadConsole(f); 
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

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PreRender), &GameFunctions::Miscellaneous::PreRenderHook, (LPVOID*)&GameFunctions::Miscellaneous::OPreRenderHook) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PreRender));

	// AntiCheat bypass

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACOne), &GameFunctions::ACBypass::ACOne, (LPVOID*)&GameFunctions::ACBypass::OACOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwo), &GameFunctions::ACBypass::ACTwo, (LPVOID*)&GameFunctions::ACBypass::OACTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThree), &GameFunctions::ACBypass::ACThree, (LPVOID*)&GameFunctions::ACBypass::OACThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFour), &GameFunctions::ACBypass::ACFour, (LPVOID*)&GameFunctions::ACBypass::OACFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFive), &GameFunctions::ACBypass::ACFive, (LPVOID*)&GameFunctions::ACBypass::OACFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSix), &GameFunctions::ACBypass::ACSix, (LPVOID*)&GameFunctions::ACBypass::OACSix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSeven), &GameFunctions::ACBypass::ACSeven, (LPVOID*)&GameFunctions::ACBypass::OACSeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACEight), &GameFunctions::ACBypass::ACEight, (LPVOID*)&GameFunctions::ACBypass::OACEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACNine), &GameFunctions::ACBypass::ACNine, (LPVOID*)&GameFunctions::ACBypass::OACNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTen), &GameFunctions::ACBypass::ACTen, (LPVOID*)&GameFunctions::ACBypass::OACTen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACEleven), &GameFunctions::ACBypass::ACEleven, (LPVOID*)&GameFunctions::ACBypass::OACEleven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACEleven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwelve), &GameFunctions::ACBypass::ACTwelve, (LPVOID*)&GameFunctions::ACBypass::OACTwelve) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwelve));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirteen), &GameFunctions::ACBypass::ACThirteen, (LPVOID*)&GameFunctions::ACBypass::OACThirteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourteen), &GameFunctions::ACBypass::ACFourteen, (LPVOID*)&GameFunctions::ACBypass::OACFourteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFifteen), &GameFunctions::ACBypass::ACFifteen, (LPVOID*)&GameFunctions::ACBypass::OACFifteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFifteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSixteen), &GameFunctions::ACBypass::ACSixteen, (LPVOID*)&GameFunctions::ACBypass::OACSixteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSixteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACSeventeen), &GameFunctions::ACBypass::ACSeventeen, (LPVOID*)&GameFunctions::ACBypass::OACSeventeen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACSeventeen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACEighteen), &GameFunctions::ACBypass::ACEighteen, (LPVOID*)&GameFunctions::ACBypass::OACEighteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACEighteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACNineteen), &GameFunctions::ACBypass::ACNineteen, (LPVOID*)&GameFunctions::ACBypass::OACNineteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACNineteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwenty), &GameFunctions::ACBypass::ACTwenty, (LPVOID*)&GameFunctions::ACBypass::OACTwenty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwenty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyOne), &GameFunctions::ACBypass::ACTwentyOne, (LPVOID*)&GameFunctions::ACBypass::OACTwentyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyTwo), &GameFunctions::ACBypass::ACTwentyTwo, (LPVOID*)&GameFunctions::ACBypass::OACTwentyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyThree), &GameFunctions::ACBypass::ACTwentyThree, (LPVOID*)&GameFunctions::ACBypass::OACTwentyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyFour), &GameFunctions::ACBypass::ACTwentyFour, (LPVOID*)&GameFunctions::ACBypass::OACTwentyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyFive), &GameFunctions::ACBypass::ACTwentyFive, (LPVOID*)&GameFunctions::ACBypass::OACTwentyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentySix), &GameFunctions::ACBypass::ACTwentySix, (LPVOID*)&GameFunctions::ACBypass::OACTwentySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentySeven), &GameFunctions::ACBypass::ACTwentySeven, (LPVOID*)&GameFunctions::ACBypass::OACTwentySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyEight), &GameFunctions::ACBypass::ACTwentyEight, (LPVOID*)&GameFunctions::ACBypass::OACTwentyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACTwentyNine), &GameFunctions::ACBypass::ACTwentyNine, (LPVOID*)&GameFunctions::ACBypass::OACTwentyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACTwentyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirty), &GameFunctions::ACBypass::ACThirty, (LPVOID*)&GameFunctions::ACBypass::OACThirty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyOne), &GameFunctions::ACBypass::ACThirtyOne, (LPVOID*)&GameFunctions::ACBypass::OACThirtyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyTwo), &GameFunctions::ACBypass::ACThirtyTwo, (LPVOID*)&GameFunctions::ACBypass::OACThirtyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyThree), &GameFunctions::ACBypass::ACThirtyThree, (LPVOID*)&GameFunctions::ACBypass::OACThirtyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyFour), &GameFunctions::ACBypass::ACThirtyFour, (LPVOID*)&GameFunctions::ACBypass::OACThirtyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyFive), &GameFunctions::ACBypass::ACThirtyFive, (LPVOID*)&GameFunctions::ACBypass::OACThirtyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtySix), &GameFunctions::ACBypass::ACThirtySix, (LPVOID*)&GameFunctions::ACBypass::OACThirtySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtySeven), &GameFunctions::ACBypass::ACThirtySeven, (LPVOID*)&GameFunctions::ACBypass::OACThirtySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyEight), &GameFunctions::ACBypass::ACThirtyEight, (LPVOID*)&GameFunctions::ACBypass::OACThirtyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACThirtyNine), &GameFunctions::ACBypass::ACThirtyNine, (LPVOID*)&GameFunctions::ACBypass::OACThirtyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACThirtyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourty), &GameFunctions::ACBypass::ACFourty, (LPVOID*)&GameFunctions::ACBypass::OACFourty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyOne), &GameFunctions::ACBypass::ACFourtyOne, (LPVOID*)&GameFunctions::ACBypass::OACFourtyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyTwo), &GameFunctions::ACBypass::ACFourtyTwo, (LPVOID*)&GameFunctions::ACBypass::OACFourtyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyThree), &GameFunctions::ACBypass::ACFourtyThree, (LPVOID*)&GameFunctions::ACBypass::OACFourtyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyFour), &GameFunctions::ACBypass::ACFourtyFour, (LPVOID*)&GameFunctions::ACBypass::OACFourtyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyFive), &GameFunctions::ACBypass::ACFourtyFive, (LPVOID*)&GameFunctions::ACBypass::OACFourtyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtySix), &GameFunctions::ACBypass::ACFourtySix, (LPVOID*)&GameFunctions::ACBypass::OACFourtySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtySeven), &GameFunctions::ACBypass::ACFourtySeven, (LPVOID*)&GameFunctions::ACBypass::OACFourtySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyEight), &GameFunctions::ACBypass::ACFourtyEight, (LPVOID*)&GameFunctions::ACBypass::OACFourtyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFourtyNine), &GameFunctions::ACBypass::ACFourtyNine, (LPVOID*)&GameFunctions::ACBypass::OACFourtyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFourtyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFifty), &GameFunctions::ACBypass::ACFifty, (LPVOID*)&GameFunctions::ACBypass::OACFifty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFifty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFiftyOne), &GameFunctions::ACBypass::ACFiftyOne, (LPVOID*)&GameFunctions::ACBypass::OACFiftyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFiftyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFiftyTwo), &GameFunctions::ACBypass::ACFiftyTwo, (LPVOID*)&GameFunctions::ACBypass::OACFiftyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFiftyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACFiftyThree), &GameFunctions::ACBypass::ACFiftyThree, (LPVOID*)&GameFunctions::ACBypass::OACFiftyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACFiftyThree));

	// Player_move_c

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate), &GameFunctions::PlayerMoveC::PlayerMoveC, (LPVOID*)&GameFunctions::PlayerMoveC::OPlayerMoveC) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PlayerMoveCUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::SpeedModifier), &GameFunctions::PlayerMoveC::SpeedModifier, (LPVOID*)&GameFunctions::PlayerMoveC::OSpeedModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::SpeedModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GodmodeOne), &GameFunctions::PlayerMoveC::GodmodeOne, (LPVOID*)&GameFunctions::PlayerMoveC::OGodmodeOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GodmodeOne));

	// WeaponSounds

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate), &GameFunctions::WeaponSounds::WeaponSounds, (LPVOID*)&GameFunctions::WeaponSounds::OWeaponSounds) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::WeaponSoundsUpdate));

	// PetEngine

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetEngineUpdate), &GameFunctions::PetEngine::PetEngine, (LPVOID*)&GameFunctions::PetEngine::OPetEngine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetEngineUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetDamage), &GameFunctions::PetEngine::PetDamage, (LPVOID*)&GameFunctions::PetEngine::OPetDamage) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetDamage));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetSpeed), &GameFunctions::PetEngine::PetSpeed, (LPVOID*)&GameFunctions::PetEngine::OPetSpeed) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetSpeed));

	// Misc

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GodmodeTwo), &GameFunctions::Miscellaneous::GodmodeTwo, (LPVOID*)&GameFunctions::Miscellaneous::OGodmodeTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GodmodeTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::InfiniteGems), &GameFunctions::Miscellaneous::InfiniteGems, (LPVOID*)&GameFunctions::Miscellaneous::OInfiniteGems) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::InfiniteGems));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ReloadModifier), &GameFunctions::Miscellaneous::ReloadModifier, (LPVOID*)&GameFunctions::Miscellaneous::OReloadModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ReloadModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::GadgetCooldown), &GameFunctions::Miscellaneous::GadgetCooldown, (LPVOID*)&GameFunctions::Miscellaneous::OGadgetCooldown) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::GadgetCooldown));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Lottery), &GameFunctions::Miscellaneous::Lottery, (LPVOID*)&GameFunctions::Miscellaneous::OLottery) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Lottery));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::FireRate), &GameFunctions::Miscellaneous::FireRate, (LPVOID*)&GameFunctions::Miscellaneous::OFireRate) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::FireRate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MaxLevelOne), &GameFunctions::Miscellaneous::Level, (LPVOID*)&GameFunctions::Miscellaneous::OLevel) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MaxLevelOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::MaxLevelTwo), &GameFunctions::Miscellaneous::Experience, (LPVOID*)&GameFunctions::Miscellaneous::OExperience) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::MaxLevelTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PixelPass), &GameFunctions::Miscellaneous::PremiumPass, (LPVOID*)&GameFunctions::Miscellaneous::OPremiumPass) == MH_OK)
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