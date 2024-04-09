#include "Signatures.h"

bool Signatures::SearchSignatures(bool NeedDebug)
{
    Unity::il2cppClass* UnityTimeClass = IL2CPP::Class::Find("UnityEngine.Time");
    Offsets::TimeOffset = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityTimeClass, "set_timeScale");

    Unity::il2cppClass* UnityDebugClass = IL2CPP::Class::Find("UnityEngine.Debug");
    Offsets::IsDebugBuild = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityDebugClass, "get_isDebugBuild");

    if (NeedDebug)
    {
        Utils::AddressLog(Offsets::IsDebugBuild - UnitySDK::UnityGameAssembly, "IsDebugBuild");
        Utils::AddressLog(Offsets::ACOne, "AntiCheatOne");
        Utils::AddressLog(Offsets::ACTwo, "AntiCheatTwo");
        Utils::AddressLog(Offsets::ACThree, "AntiCheatThree");
        Utils::AddressLog(Offsets::PlayerMoveCUpdate, "PlayerMoveCUpdate");
        Utils::AddressLog(Offsets::WeaponSoundsUpdate, "WeaponSoundsUpdate");
        Utils::AddressLog(Offsets::PetEngineUpdate, "PetEngineUpdate");
        Utils::AddressLog(Offsets::XRay, "XRay");
        Utils::AddressLog(Offsets::NextHitCritical, "NextHitCritical");
        Utils::AddressLog(Offsets::Invisibility, "Invisibility");
        Utils::AddressLog(Offsets::SpeedModifier, "SpeedModifier");
        Utils::AddressLog(Offsets::MovePlayer, "MovePlayer");
        Utils::AddressLog(Offsets::JetpackFly, "JetpackFly");
        Utils::AddressLog(Offsets::TimeOffset - UnitySDK::UnityGameAssembly, "TimeOffset");
        Utils::AddressLog(Offsets::GodmodeOne, "Godmode");
        Utils::AddressLog(Offsets::GodmodeTwo, "GodmodeTwo");
        Utils::AddressLog(Offsets::InfiniteGems, "InfiniteGems");
        Utils::AddressLog(Offsets::NoReload, "NoReload");
        Utils::AddressLog(Offsets::GadgetCooldown, "GadgetCooldown");
        Utils::AddressLog(Offsets::PetHealth, "PetHealth");
        Utils::AddressLog(Offsets::PetDamage, "PetDamage");
        Utils::AddressLog(Offsets::PetSpeed, "PetSpeed");
    }
    return true;
}