#include "Signatures.h"

bool Signatures::SearchSignatures(bool NeedDebug)
{
    Unity::il2cppClass* UnityTimeClass = IL2CPP::Class::Find("UnityEngine.Time");
    Offsets::TimeOffset = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityTimeClass, "set_timeScale");

    Unity::il2cppClass* UnityDebugClass = IL2CPP::Class::Find("UnityEngine.Debug");
    Offsets::IsDebugBuild = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityDebugClass, "get_isDebugBuild");

    if (NeedDebug)
    {
        Utils::AddressLog(Offsets::TimeOffset - UnitySDK::UnityGameAssembly, "TimeOffset");
        Utils::AddressLog(Offsets::IsDebugBuild - UnitySDK::UnityGameAssembly, "IsDebugBuild");
        Utils::AddressLog(Offsets::PlayerMoveCUpdate, "PlayerMoveCUpdate");
        Utils::AddressLog(Offsets::WeaponSoundsUpdate, "WeaponSoundsUpdate");
        Utils::AddressLog(Offsets::XRay, "XRay");
        Utils::AddressLog(Offsets::NextHitCritical, "NextHitCritical");
        Utils::AddressLog(Offsets::AddHealthFromWeaponOnline, "AddHealthFromWeaponOnline");
        Utils::AddressLog(Offsets::AddAmmoFromWeaponOnline, "AddAmmoFromWeaponOnline");
        Utils::AddressLog(Offsets::Invisibility, "Invisibility");
        Utils::AddressLog(Offsets::SpeedModifier, "SpeedModifier");
    }
    return true;
}