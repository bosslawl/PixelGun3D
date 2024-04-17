#pragma once
#include "../../Utils/Utils.h"

namespace UnitySDK
{
    inline uintptr_t UnityGameBase;
    inline uintptr_t UnityGameAssembly;
    inline uintptr_t UnityPlayer;
}

namespace Memory
{
    template <typename T> T read(uintptr_t address)
    {
        try {
            return *(T *)address;
        } catch(...) {
            return T();
        }
    }

    template <typename T> void write(uintptr_t address, T value)
    {
        try {
            *(T *)address = value;
        } catch(...) {
            return;
        }
    }
}