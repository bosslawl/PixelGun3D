#include "Signatures.h"

bool Signatures::SearchSignatures(bool NeedDebug)
{
    // UnityEngine
    Offsets::UnityEngine::TimeOffset = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("UnityEngine.Time")), OBFUSCATE("set_timeScale"));
    Offsets::UnityEngine::IsDebugBuild = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("UnityEngine.Debug")), OBFUSCATE("get_isDebugBuild"));
    Offsets::UnityEngine::TextMesh = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("UnityEngine.TextMesh")), OBFUSCATE("get_text"));
    Offsets::UnityEngine::

    // Player_move_c
    Offsets::PlayerMoveC::PlayerMoveCUpdate = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("Player_move_c")), OBFUSCATE("Update")) - UnitySDK::UnityGameAssembly;
    Offsets::PlayerMoveC::MatchInvisibility = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("Player_move_c")), OBFUSCATE("MakeInvisibleForSeconds")) - UnitySDK::UnityGameAssembly;

    // WeaponSounds
    Offsets::WeaponSounds::WeaponSoundsUpdate = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("WeaponSounds")), OBFUSCATE("Update")) - UnitySDK::UnityGameAssembly;
    Offsets::WeaponSounds::NextHitCritical = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(IL2CPP::Class::Find(OBFUSCATE("WeaponSounds")), OBFUSCATE("SetNextHitCritical")) - UnitySDK::UnityGameAssembly;

    if (NeedDebug)
    {
        // UnityEngine
        Utils::AddressLog(Offsets::UnityEngine::IsDebugBuild - UnitySDK::UnityGameAssembly, OBFUSCATE("IsDebugBuild"));
        Utils::AddressLog(Offsets::UnityEngine::TimeOffset - UnitySDK::UnityGameAssembly, OBFUSCATE("TimeOffset"));
        Utils::AddressLog(Offsets::UnityEngine::TextMesh - UnitySDK::UnityGameAssembly, OBFUSCATE("TextMesh"));

        // AntiCheat bypass

        Utils::AddressLog(Offsets::ACBypass::ACOne, OBFUSCATE("AntiCheatOne"));
        Utils::AddressLog(Offsets::ACBypass::ACTwo, OBFUSCATE("AntiCheatTwo"));
        Utils::AddressLog(Offsets::ACBypass::ACThree, OBFUSCATE("AntiCheatThree"));
        Utils::AddressLog(Offsets::ACBypass::ACFour, OBFUSCATE("AntiCheatFour"));
        Utils::AddressLog(Offsets::ACBypass::ACFive, OBFUSCATE("AntiCheatFive"));
        Utils::AddressLog(Offsets::ACBypass::ACSix, OBFUSCATE("AntiCheatSix"));
        Utils::AddressLog(Offsets::ACBypass::ACSeven, OBFUSCATE("AntiCheatSeven"));
        Utils::AddressLog(Offsets::ACBypass::ACEight, OBFUSCATE("AntiCheatEight"));
        Utils::AddressLog(Offsets::ACBypass::ACNine, OBFUSCATE("AntiCheatNine"));
        Utils::AddressLog(Offsets::ACBypass::ACTen, OBFUSCATE("AntiCheatTen"));
        Utils::AddressLog(Offsets::ACBypass::ACEleven, OBFUSCATE("AntiCheatEleven"));
        Utils::AddressLog(Offsets::ACBypass::ACTwelve, OBFUSCATE("AntiCheatTwelve"));
        Utils::AddressLog(Offsets::ACBypass::ACThirteen, OBFUSCATE("AntiCheatThirteen"));
        Utils::AddressLog(Offsets::ACBypass::ACFourteen, OBFUSCATE("AntiCheatFourteen"));
        Utils::AddressLog(Offsets::ACBypass::ACFifteen, OBFUSCATE("AntiCheatFifteen"));
        Utils::AddressLog(Offsets::ACBypass::ACSixteen, OBFUSCATE("AntiCheatSixteen"));
        Utils::AddressLog(Offsets::ACBypass::ACSeventeen, OBFUSCATE("AntiCheatSeventeen"));
        Utils::AddressLog(Offsets::ACBypass::ACEighteen, OBFUSCATE("AntiCheatEighteen"));
        Utils::AddressLog(Offsets::ACBypass::ACNineteen, OBFUSCATE("AntiCheatNineteen"));
        Utils::AddressLog(Offsets::ACBypass::ACTwenty, OBFUSCATE("AntiCheatTwenty"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyOne, OBFUSCATE("AntiCheatTwentyOne"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyTwo, OBFUSCATE("AntiCheatTwentyTwo"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyThree, OBFUSCATE("AntiCheatTwentyThree"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyFour, OBFUSCATE("AntiCheatTwentyFour"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyFive, OBFUSCATE("AntiCheatTwentyFive"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentySix, OBFUSCATE("AntiCheatTwentySix"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentySeven, OBFUSCATE("AntiCheatTwentySeven"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyEight, OBFUSCATE("AntiCheatTwentyEight"));
        Utils::AddressLog(Offsets::ACBypass::ACTwentyNine, OBFUSCATE("AntiCheatTwentyNine"));
        Utils::AddressLog(Offsets::ACBypass::ACThirty, OBFUSCATE("AntiCheatThirty"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyOne, OBFUSCATE("AntiCheatThirtyOne"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyTwo, OBFUSCATE("AntiCheatThirtyTwo"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyThree, OBFUSCATE("AntiCheatThirtyThree"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyFour, OBFUSCATE("AntiCheatThirtyFour"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyFive, OBFUSCATE("AntiCheatThirtyFive"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtySix, OBFUSCATE("AntiCheatThirtySix"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtySeven, OBFUSCATE("AntiCheatThirtySeven"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyEight, OBFUSCATE("AntiCheatThirtyEight"));
        Utils::AddressLog(Offsets::ACBypass::ACThirtyNine, OBFUSCATE("AntiCheatThirtyNine"));
        Utils::AddressLog(Offsets::ACBypass::ACFourty, OBFUSCATE("AntiCheatFourty"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyOne, OBFUSCATE("AntiCheatFourtyOne"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyTwo, OBFUSCATE("AntiCheatFourtyTwo"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyThree, OBFUSCATE("AntiCheatFourtyThree"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyFour, OBFUSCATE("AntiCheatFourtyFour"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyFive, OBFUSCATE("AntiCheatFourtyFive"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtySix, OBFUSCATE("AntiCheatFourtySix"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtySeven, OBFUSCATE("AntiCheatFourtySeven"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyEight, OBFUSCATE("AntiCheatFourtyEight"));
        Utils::AddressLog(Offsets::ACBypass::ACFourtyNine, OBFUSCATE("AntiCheatFourtyNine"));
        Utils::AddressLog(Offsets::ACBypass::ACFifty, OBFUSCATE("AntiCheatFifty"));
        Utils::AddressLog(Offsets::ACBypass::ACFiftyOne, OBFUSCATE("AntiCheatFiftyOne"));
        Utils::AddressLog(Offsets::ACBypass::ACFiftyTwo, OBFUSCATE("AntiCheatFiftyTwo"));
        Utils::AddressLog(Offsets::ACBypass::ACFiftyThree, OBFUSCATE("AntiCheatFiftyThree"));

        // Player_move_c

        Utils::AddressLog(Offsets::PlayerMoveC::PlayerMoveCUpdate, OBFUSCATE("PlayerMoveCUpdate"));
        Utils::AddressLog(Offsets::PlayerMoveC::XRay, OBFUSCATE("XRay"));
        Utils::AddressLog(Offsets::WeaponSounds::NextHitCritical, OBFUSCATE("NextHitCritical"));
        Utils::AddressLog(Offsets::PlayerMoveC::MatchInvisibility, OBFUSCATE("MatchInvisibility"));
        Utils::AddressLog(Offsets::Miscellaneous::SpeedModifier, OBFUSCATE("SpeedModifier"));
        Utils::AddressLog(Offsets::PlayerMoveC::JetpackFly, OBFUSCATE("JetpackFly"));
        Utils::AddressLog(Offsets::PlayerMoveC::GodmodeOne, OBFUSCATE("GodmodeOne"));

        // WeaponSounds

        Utils::AddressLog(Offsets::WeaponSounds::WeaponSoundsUpdate, OBFUSCATE("WeaponSoundsUpdate"));

        // PetEngine

        Utils::AddressLog(Offsets::PetEngine::PetEngineUpdate, OBFUSCATE("PetEngineUpdate"));
        Utils::AddressLog(Offsets::PetEngine::PetHealth, OBFUSCATE("PetHealth"));
        Utils::AddressLog(Offsets::PetEngine::PetDamage, OBFUSCATE("PetDamage"));
        Utils::AddressLog(Offsets::PetEngine::PetSpeed, OBFUSCATE("PetSpeed"));
        
        // Misc

        Utils::AddressLog(Offsets::Miscellaneous::GodmodeTwo, OBFUSCATE("GodmodeTwo"));
        Utils::AddressLog(Offsets::Miscellaneous::InfiniteGems, OBFUSCATE("InfiniteGems"));
        Utils::AddressLog(Offsets::Miscellaneous::ReloadModifier, OBFUSCATE("NoReload"));
        Utils::AddressLog(Offsets::Miscellaneous::GadgetCooldown, OBFUSCATE("GadgetCooldown"));

    }
    return true;
}