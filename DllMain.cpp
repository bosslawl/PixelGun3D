#include "Utils/Utils.h"
#include "Cheat/Hooks/Hooks.h"
#include "Utils/Backend/UI.h"

#define QWORD int64_t
HANDLE hCurrentUIThread = nullptr;
FILE *f;

// run it in Release | x64, already set up everything

QWORD WINAPI MainThread(LPVOID param)
{
    IL2CPP::Initialize();
    Unity::Camera::Initialize();
    MH_Initialize();

    hCurrentUIThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)UI::Render, nullptr, NULL, nullptr);
    RunHooks.Load(f);

    while(!Utils::KeyPressed(VK_END)) // uninject
        std::this_thread::sleep_for(std::chrono::milliseconds(420)); // no cpu frying in my city

    RunHooks.Unload(f);
    return 0;
}

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
    switch(dwReason) {
    case 1:
        HANDLE hMainThread = CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(MainThread), hModule, 0, nullptr);

        if(hMainThread)
            CloseHandle(hMainThread);

        break;
    }
    return TRUE;
}