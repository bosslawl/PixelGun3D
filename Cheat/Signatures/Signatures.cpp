#include "Signatures.h"

bool Signatures::SearchSignatures(bool NeedDebug)
{
    Unity::il2cppClass* UnityTimeClass = IL2CPP::Class::Find(OBFUSCATE("UnityEngine.Time"));
    Offsets::TimeOffset = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityTimeClass, OBFUSCATE("set_timeScale"));

    Unity::il2cppClass* UnityDebugClass = IL2CPP::Class::Find(OBFUSCATE("UnityEngine.Debug"));
    Offsets::IsDebugBuild = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityDebugClass, OBFUSCATE("get_isDebugBuild"));

    if (NeedDebug)
    {
        Utils::AddressLog(Offsets::IsDebugBuild - UnitySDK::UnityGameAssembly, OBFUSCATE("IsDebugBuild"));
        Utils::AddressLog(Offsets::ACOne, OBFUSCATE("AntiCheatOne"));
        Utils::AddressLog(Offsets::ACTwo, OBFUSCATE("AntiCheatTwo"));
        Utils::AddressLog(Offsets::ACThree, OBFUSCATE("AntiCheatThree"));
        Utils::AddressLog(Offsets::PlayerMoveCUpdate, OBFUSCATE("PlayerMoveCUpdate"));
        Utils::AddressLog(Offsets::WeaponSoundsUpdate, OBFUSCATE("WeaponSoundsUpdate"));
        Utils::AddressLog(Offsets::PetEngineUpdate, OBFUSCATE("PetEngineUpdate"));
        Utils::AddressLog(Offsets::XRay, OBFUSCATE("XRay"));
        Utils::AddressLog(Offsets::NextHitCritical, OBFUSCATE("NextHitCritical"));
        Utils::AddressLog(Offsets::Invisibility, OBFUSCATE("Invisibility"));
        Utils::AddressLog(Offsets::SpeedModifier, OBFUSCATE("SpeedModifier"));
        Utils::AddressLog(Offsets::MovePlayer, OBFUSCATE("MovePlayer"));
        Utils::AddressLog(Offsets::JetpackFly, OBFUSCATE("JetpackFly"));
        Utils::AddressLog(Offsets::TimeOffset - UnitySDK::UnityGameAssembly, OBFUSCATE("TimeOffset"));
        Utils::AddressLog(Offsets::GodmodeOne, OBFUSCATE("Godmode"));
        Utils::AddressLog(Offsets::GodmodeTwo, OBFUSCATE("GodmodeTwo"));
        Utils::AddressLog(Offsets::InfiniteGems, OBFUSCATE("InfiniteGems"));
        Utils::AddressLog(Offsets::NoReload, OBFUSCATE("NoReload"));
        Utils::AddressLog(Offsets::GadgetCooldown, OBFUSCATE("GadgetCooldown"));
        Utils::AddressLog(Offsets::PetHealth, OBFUSCATE("PetHealth"));
        Utils::AddressLog(Offsets::PetDamage, OBFUSCATE("PetDamage"));
        Utils::AddressLog(Offsets::PetSpeed, OBFUSCATE("PetSpeed"));
    }
    return true;
}