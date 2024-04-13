#include "Signatures.h"

bool Signatures::SearchSignatures(bool NeedDebug)
{
    Unity::il2cppClass* UnityTimeClass = IL2CPP::Class::Find(OBFUSCATE("UnityEngine.Time"));
    Offsets::TimeOffset = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityTimeClass, OBFUSCATE("set_timeScale"));

    Unity::il2cppClass* UnityDebugClass = IL2CPP::Class::Find(OBFUSCATE("UnityEngine.Debug"));
    Offsets::IsDebugBuild = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(UnityDebugClass, OBFUSCATE("get_isDebugBuild"));

    Unity::il2cppClass* TextMeshName = IL2CPP::Class::Find(OBFUSCATE("UnityEngine.TextMesh"));
    Offsets::TextMesh = (uintptr_t)IL2CPP::Class::Utils::GetMethodPointer(TextMeshName, OBFUSCATE("get_text"));

    if (NeedDebug)
    {
        Utils::AddressLog(Offsets::IsDebugBuild - UnitySDK::UnityGameAssembly, OBFUSCATE("IsDebugBuild"));
        Utils::AddressLog(Offsets::TimeOffset - UnitySDK::UnityGameAssembly, OBFUSCATE("TimeOffset"));
        Utils::AddressLog(Offsets::TextMesh - UnitySDK::UnityGameAssembly, OBFUSCATE("TextMesh"));

        // AntiCheat bypass

        Utils::AddressLog(Offsets::ACOne, OBFUSCATE("AntiCheatOne"));
        Utils::AddressLog(Offsets::ACTwo, OBFUSCATE("AntiCheatTwo"));
        Utils::AddressLog(Offsets::ACThree, OBFUSCATE("AntiCheatThree"));
        Utils::AddressLog(Offsets::ACFour, OBFUSCATE("AntiCheatFour"));
        Utils::AddressLog(Offsets::ACFive, OBFUSCATE("AntiCheatFive"));
        Utils::AddressLog(Offsets::ACSix, OBFUSCATE("AntiCheatSix"));
        Utils::AddressLog(Offsets::ACSeven, OBFUSCATE("AntiCheatSeven"));
        Utils::AddressLog(Offsets::ACEight, OBFUSCATE("AntiCheatEight"));
        Utils::AddressLog(Offsets::ACNine, OBFUSCATE("AntiCheatNine"));
        Utils::AddressLog(Offsets::ACTen, OBFUSCATE("AntiCheatTen"));
        Utils::AddressLog(Offsets::ACEleven, OBFUSCATE("AntiCheatEleven"));
        Utils::AddressLog(Offsets::ACTwelve, OBFUSCATE("AntiCheatTwelve"));
        Utils::AddressLog(Offsets::ACThirteen, OBFUSCATE("AntiCheatThirteen"));
        Utils::AddressLog(Offsets::ACFourteen, OBFUSCATE("AntiCheatFourteen"));
        Utils::AddressLog(Offsets::ACFifteen, OBFUSCATE("AntiCheatFifteen"));
        Utils::AddressLog(Offsets::ACSixteen, OBFUSCATE("AntiCheatSixteen"));
        Utils::AddressLog(Offsets::ACSeventeen, OBFUSCATE("AntiCheatSeventeen"));
        Utils::AddressLog(Offsets::ACEighteen, OBFUSCATE("AntiCheatEighteen"));
        Utils::AddressLog(Offsets::ACNineteen, OBFUSCATE("AntiCheatNineteen"));
        Utils::AddressLog(Offsets::ACTwenty, OBFUSCATE("AntiCheatTwenty"));
        Utils::AddressLog(Offsets::ACTwentyOne, OBFUSCATE("AntiCheatTwentyOne"));
        Utils::AddressLog(Offsets::ACTwentyTwo, OBFUSCATE("AntiCheatTwentyTwo"));
        Utils::AddressLog(Offsets::ACTwentyThree, OBFUSCATE("AntiCheatTwentyThree"));
        Utils::AddressLog(Offsets::ACTwentyFour, OBFUSCATE("AntiCheatTwentyFour"));
        Utils::AddressLog(Offsets::ACTwentyFive, OBFUSCATE("AntiCheatTwentyFive"));
        Utils::AddressLog(Offsets::ACTwentySix, OBFUSCATE("AntiCheatTwentySix"));
        Utils::AddressLog(Offsets::ACTwentySeven, OBFUSCATE("AntiCheatTwentySeven"));
        Utils::AddressLog(Offsets::ACTwentyEight, OBFUSCATE("AntiCheatTwentyEight"));
        Utils::AddressLog(Offsets::ACTwentyNine, OBFUSCATE("AntiCheatTwentyNine"));
        Utils::AddressLog(Offsets::ACThirty, OBFUSCATE("AntiCheatThirty"));
        Utils::AddressLog(Offsets::ACThirtyOne, OBFUSCATE("AntiCheatThirtyOne"));
        Utils::AddressLog(Offsets::ACThirtyTwo, OBFUSCATE("AntiCheatThirtyTwo"));
        Utils::AddressLog(Offsets::ACThirtyThree, OBFUSCATE("AntiCheatThirtyThree"));
        Utils::AddressLog(Offsets::ACThirtyFour, OBFUSCATE("AntiCheatThirtyFour"));
        Utils::AddressLog(Offsets::ACThirtyFive, OBFUSCATE("AntiCheatThirtyFive"));
        Utils::AddressLog(Offsets::ACThirtySix, OBFUSCATE("AntiCheatThirtySix"));
        Utils::AddressLog(Offsets::ACThirtySeven, OBFUSCATE("AntiCheatThirtySeven"));
        Utils::AddressLog(Offsets::ACThirtyEight, OBFUSCATE("AntiCheatThirtyEight"));
        Utils::AddressLog(Offsets::ACThirtyNine, OBFUSCATE("AntiCheatThirtyNine"));
        Utils::AddressLog(Offsets::ACFourty, OBFUSCATE("AntiCheatFourty"));
        Utils::AddressLog(Offsets::ACFourtyOne, OBFUSCATE("AntiCheatFourtyOne"));
        Utils::AddressLog(Offsets::ACFourtyTwo, OBFUSCATE("AntiCheatFourtyTwo"));
        Utils::AddressLog(Offsets::ACFourtyThree, OBFUSCATE("AntiCheatFourtyThree"));
        Utils::AddressLog(Offsets::ACFourtyFour, OBFUSCATE("AntiCheatFourtyFour"));
        Utils::AddressLog(Offsets::ACFourtyFive, OBFUSCATE("AntiCheatFourtyFive"));
        Utils::AddressLog(Offsets::ACFourtySix, OBFUSCATE("AntiCheatFourtySix"));
        Utils::AddressLog(Offsets::ACFourtySeven, OBFUSCATE("AntiCheatFourtySeven"));
        Utils::AddressLog(Offsets::ACFourtyEight, OBFUSCATE("AntiCheatFourtyEight"));
        Utils::AddressLog(Offsets::ACFourtyNine, OBFUSCATE("AntiCheatFourtyNine"));
        Utils::AddressLog(Offsets::ACFifty, OBFUSCATE("AntiCheatFifty"));
        Utils::AddressLog(Offsets::ACFiftyOne, OBFUSCATE("AntiCheatFiftyOne"));
        Utils::AddressLog(Offsets::ACFiftyTwo, OBFUSCATE("AntiCheatFiftyTwo"));
        Utils::AddressLog(Offsets::ACFiftyThree, OBFUSCATE("AntiCheatFiftyThree"));

        // Player_move_c

        Utils::AddressLog(Offsets::PlayerMoveCUpdate, OBFUSCATE("PlayerMoveCUpdate"));
        Utils::AddressLog(Offsets::XRay, OBFUSCATE("XRay"));
        Utils::AddressLog(Offsets::NextHitCritical, OBFUSCATE("NextHitCritical"));
        Utils::AddressLog(Offsets::MatchInvisibility, OBFUSCATE("MatchInvisibility"));
        Utils::AddressLog(Offsets::SpeedModifier, OBFUSCATE("SpeedModifier"));
        Utils::AddressLog(Offsets::JetpackFly, OBFUSCATE("JetpackFly"));
        Utils::AddressLog(Offsets::GodmodeOne, OBFUSCATE("GodmodeOne"));

        // WeaponSounds

        Utils::AddressLog(Offsets::WeaponSoundsUpdate, OBFUSCATE("WeaponSoundsUpdate"));

        // PetEngine

        Utils::AddressLog(Offsets::PetEngineUpdate, OBFUSCATE("PetEngineUpdate"));
        Utils::AddressLog(Offsets::PetHealth, OBFUSCATE("PetHealth"));
        Utils::AddressLog(Offsets::PetDamage, OBFUSCATE("PetDamage"));
        Utils::AddressLog(Offsets::PetSpeed, OBFUSCATE("PetSpeed"));
        
        // Misc

        Utils::AddressLog(Offsets::GodmodeTwo, OBFUSCATE("GodmodeTwo"));
        Utils::AddressLog(Offsets::InfiniteGems, OBFUSCATE("InfiniteGems"));
        Utils::AddressLog(Offsets::ReloadModifier, OBFUSCATE("NoReload"));
        Utils::AddressLog(Offsets::GadgetCooldown, OBFUSCATE("GadgetCooldown"));

    }
    return true;
}