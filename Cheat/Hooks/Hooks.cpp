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
	if (MH_CreateHook(reinterpret_cast<LPVOID*>(Offsets::UnityEngine::IsDebugBuild), &GameFunctions::UnityEngine::IsDebug, (LPVOID*)&GameFunctions::UnityEngine::OIsDebug) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*>(Offsets::UnityEngine::IsDebugBuild));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::UnityEngine::PreRender), &GameFunctions::UnityEngine::PreRenderHook, (LPVOID*)&GameFunctions::UnityEngine::OPreRenderHook) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::UnityEngine::PreRender));

	// AntiCheat bypass

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACOne), &GameFunctions::ACBypass::ACOne, (LPVOID*)&GameFunctions::ACBypass::OACOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwo), &GameFunctions::ACBypass::ACTwo, (LPVOID*)&GameFunctions::ACBypass::OACTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThree), &GameFunctions::ACBypass::ACThree, (LPVOID*)&GameFunctions::ACBypass::OACThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFour), &GameFunctions::ACBypass::ACFour, (LPVOID*)&GameFunctions::ACBypass::OACFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFive), &GameFunctions::ACBypass::ACFive, (LPVOID*)&GameFunctions::ACBypass::OACFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSix), &GameFunctions::ACBypass::ACSix, (LPVOID*)&GameFunctions::ACBypass::OACSix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSeven), &GameFunctions::ACBypass::ACSeven, (LPVOID*)&GameFunctions::ACBypass::OACSeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACEight), &GameFunctions::ACBypass::ACEight, (LPVOID*)&GameFunctions::ACBypass::OACEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACNine), &GameFunctions::ACBypass::ACNine, (LPVOID*)&GameFunctions::ACBypass::OACNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTen), &GameFunctions::ACBypass::ACTen, (LPVOID*)&GameFunctions::ACBypass::OACTen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACEleven), &GameFunctions::ACBypass::ACEleven, (LPVOID*)&GameFunctions::ACBypass::OACEleven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACEleven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwelve), &GameFunctions::ACBypass::ACTwelve, (LPVOID*)&GameFunctions::ACBypass::OACTwelve) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwelve));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirteen), &GameFunctions::ACBypass::ACThirteen, (LPVOID*)&GameFunctions::ACBypass::OACThirteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourteen), &GameFunctions::ACBypass::ACFourteen, (LPVOID*)&GameFunctions::ACBypass::OACFourteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFifteen), &GameFunctions::ACBypass::ACFifteen, (LPVOID*)&GameFunctions::ACBypass::OACFifteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFifteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSixteen), &GameFunctions::ACBypass::ACSixteen, (LPVOID*)&GameFunctions::ACBypass::OACSixteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSixteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSeventeen), &GameFunctions::ACBypass::ACSeventeen, (LPVOID*)&GameFunctions::ACBypass::OACSeventeen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACSeventeen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACEighteen), &GameFunctions::ACBypass::ACEighteen, (LPVOID*)&GameFunctions::ACBypass::OACEighteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACEighteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACNineteen), &GameFunctions::ACBypass::ACNineteen, (LPVOID*)&GameFunctions::ACBypass::OACNineteen) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACNineteen));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwenty), &GameFunctions::ACBypass::ACTwenty, (LPVOID*)&GameFunctions::ACBypass::OACTwenty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwenty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyOne), &GameFunctions::ACBypass::ACTwentyOne, (LPVOID*)&GameFunctions::ACBypass::OACTwentyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyTwo), &GameFunctions::ACBypass::ACTwentyTwo, (LPVOID*)&GameFunctions::ACBypass::OACTwentyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyThree), &GameFunctions::ACBypass::ACTwentyThree, (LPVOID*)&GameFunctions::ACBypass::OACTwentyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyFour), &GameFunctions::ACBypass::ACTwentyFour, (LPVOID*)&GameFunctions::ACBypass::OACTwentyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyFive), &GameFunctions::ACBypass::ACTwentyFive, (LPVOID*)&GameFunctions::ACBypass::OACTwentyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentySix), &GameFunctions::ACBypass::ACTwentySix, (LPVOID*)&GameFunctions::ACBypass::OACTwentySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentySeven), &GameFunctions::ACBypass::ACTwentySeven, (LPVOID*)&GameFunctions::ACBypass::OACTwentySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyEight), &GameFunctions::ACBypass::ACTwentyEight, (LPVOID*)&GameFunctions::ACBypass::OACTwentyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyNine), &GameFunctions::ACBypass::ACTwentyNine, (LPVOID*)&GameFunctions::ACBypass::OACTwentyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACTwentyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirty), &GameFunctions::ACBypass::ACThirty, (LPVOID*)&GameFunctions::ACBypass::OACThirty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyOne), &GameFunctions::ACBypass::ACThirtyOne, (LPVOID*)&GameFunctions::ACBypass::OACThirtyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyTwo), &GameFunctions::ACBypass::ACThirtyTwo, (LPVOID*)&GameFunctions::ACBypass::OACThirtyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyThree), &GameFunctions::ACBypass::ACThirtyThree, (LPVOID*)&GameFunctions::ACBypass::OACThirtyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyFour), &GameFunctions::ACBypass::ACThirtyFour, (LPVOID*)&GameFunctions::ACBypass::OACThirtyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyFive), &GameFunctions::ACBypass::ACThirtyFive, (LPVOID*)&GameFunctions::ACBypass::OACThirtyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtySix), &GameFunctions::ACBypass::ACThirtySix, (LPVOID*)&GameFunctions::ACBypass::OACThirtySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtySeven), &GameFunctions::ACBypass::ACThirtySeven, (LPVOID*)&GameFunctions::ACBypass::OACThirtySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyEight), &GameFunctions::ACBypass::ACThirtyEight, (LPVOID*)&GameFunctions::ACBypass::OACThirtyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyNine), &GameFunctions::ACBypass::ACThirtyNine, (LPVOID*)&GameFunctions::ACBypass::OACThirtyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACThirtyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourty), &GameFunctions::ACBypass::ACFourty, (LPVOID*)&GameFunctions::ACBypass::OACFourty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyOne), &GameFunctions::ACBypass::ACFourtyOne, (LPVOID*)&GameFunctions::ACBypass::OACFourtyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyTwo), &GameFunctions::ACBypass::ACFourtyTwo, (LPVOID*)&GameFunctions::ACBypass::OACFourtyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyThree), &GameFunctions::ACBypass::ACFourtyThree, (LPVOID*)&GameFunctions::ACBypass::OACFourtyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyThree));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyFour), &GameFunctions::ACBypass::ACFourtyFour, (LPVOID*)&GameFunctions::ACBypass::OACFourtyFour) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyFour));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyFive), &GameFunctions::ACBypass::ACFourtyFive, (LPVOID*)&GameFunctions::ACBypass::OACFourtyFive) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyFive));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtySix), &GameFunctions::ACBypass::ACFourtySix, (LPVOID*)&GameFunctions::ACBypass::OACFourtySix) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtySix));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtySeven), &GameFunctions::ACBypass::ACFourtySeven, (LPVOID*)&GameFunctions::ACBypass::OACFourtySeven) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtySeven));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyEight), &GameFunctions::ACBypass::ACFourtyEight, (LPVOID*)&GameFunctions::ACBypass::OACFourtyEight) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyEight));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyNine), &GameFunctions::ACBypass::ACFourtyNine, (LPVOID*)&GameFunctions::ACBypass::OACFourtyNine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFourtyNine));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFifty), &GameFunctions::ACBypass::ACFifty, (LPVOID*)&GameFunctions::ACBypass::OACFifty) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFifty));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFiftyOne), &GameFunctions::ACBypass::ACFiftyOne, (LPVOID*)&GameFunctions::ACBypass::OACFiftyOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFiftyOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFiftyTwo), &GameFunctions::ACBypass::ACFiftyTwo, (LPVOID*)&GameFunctions::ACBypass::OACFiftyTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFiftyTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFiftyThree), &GameFunctions::ACBypass::ACFiftyThree, (LPVOID*)&GameFunctions::ACBypass::OACFiftyThree) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::ACBypass::ACFiftyThree));

	// Player_move_c

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PlayerMoveC::PlayerMoveCUpdate), &GameFunctions::PlayerMoveC::PlayerMoveC, (LPVOID*)&GameFunctions::PlayerMoveC::OPlayerMoveC) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PlayerMoveC::PlayerMoveCUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::SpeedModifier), &GameFunctions::PlayerMoveC::SpeedModifier, (LPVOID*)&GameFunctions::PlayerMoveC::OSpeedModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::SpeedModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PlayerMoveC::GodmodeOne), &GameFunctions::PlayerMoveC::GodmodeOne, (LPVOID*)&GameFunctions::PlayerMoveC::OGodmodeOne) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PlayerMoveC::GodmodeOne));

	// WeaponSounds

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::WeaponSounds::WeaponSoundsUpdate), &GameFunctions::WeaponSounds::WeaponSounds, (LPVOID*)&GameFunctions::WeaponSounds::OWeaponSounds) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::WeaponSounds::WeaponSoundsUpdate));

	// PetEngine

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetEngine::PetEngineUpdate), &GameFunctions::PetEngine::PetEngine, (LPVOID*)&GameFunctions::PetEngine::OPetEngine) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetEngine::PetEngineUpdate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetEngine::PetDamage), &GameFunctions::PetEngine::PetDamage, (LPVOID*)&GameFunctions::PetEngine::OPetDamage) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetEngine::PetDamage));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::PetEngine::PetSpeed), &GameFunctions::PetEngine::PetSpeed, (LPVOID*)&GameFunctions::PetEngine::OPetSpeed) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::PetEngine::PetSpeed));

	// Misc

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::GodmodeTwo), &GameFunctions::Miscellaneous::GodmodeTwo, (LPVOID*)&GameFunctions::Miscellaneous::OGodmodeTwo) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::GodmodeTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::InfiniteGems), &GameFunctions::Miscellaneous::InfiniteGems, (LPVOID*)&GameFunctions::Miscellaneous::OInfiniteGems) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::InfiniteGems));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::ReloadModifier), &GameFunctions::Miscellaneous::ReloadModifier, (LPVOID*)&GameFunctions::Miscellaneous::OReloadModifier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::ReloadModifier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::GadgetCooldown), &GameFunctions::Miscellaneous::GadgetCooldown, (LPVOID*)&GameFunctions::Miscellaneous::OGadgetCooldown) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::GadgetCooldown));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::Lottery), &GameFunctions::Miscellaneous::Lottery, (LPVOID*)&GameFunctions::Miscellaneous::OLottery) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::Lottery));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::FireRate), &GameFunctions::Miscellaneous::FireRate, (LPVOID*)&GameFunctions::Miscellaneous::OFireRate) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::FireRate));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::MaxLevelOne), &GameFunctions::Miscellaneous::Level, (LPVOID*)&GameFunctions::Miscellaneous::OLevel) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::MaxLevelOne));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::MaxLevelTwo), &GameFunctions::Miscellaneous::Experience, (LPVOID*)&GameFunctions::Miscellaneous::OExperience) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::MaxLevelTwo));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::PixelPass), &GameFunctions::Miscellaneous::PremiumPass, (LPVOID*)&GameFunctions::Miscellaneous::OPremiumPass) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::PixelPass));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::RewardMultiplier), &GameFunctions::Miscellaneous::RewardMultiplier, (LPVOID*)&GameFunctions::Miscellaneous::ORewardMultiplier) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::RewardMultiplier));

	if (MH_CreateHook(reinterpret_cast<LPVOID*>(UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::DoubleRewards), &GameFunctions::Miscellaneous::DoubleRewards, (LPVOID*)&GameFunctions::Miscellaneous::ODoubleRewards) == MH_OK)
		MH_EnableHook(reinterpret_cast<LPVOID*> (UnitySDK::UnityGameAssembly + Offsets::Miscellaneous::DoubleRewards));
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