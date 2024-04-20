#include "Drawing.h"
#include "../../Cheat/Functions/Functions.h"
#include "../../Cheat/Utils/Variables.h"
#include "../Dumper/Dumper.hpp"
#include "../../Cheat/Functions/Data.h"

ImGuiWindowFlags Drawing::WindowFlags    = 0;
bool Drawing::bDraw                      = true;
UI::WindowItem Drawing::lpSelectedWindow = { nullptr, "", "" };

bool Drawing::isActive() { return bDraw == true; }

void DrawInspector()
{
    ImGui::SetNextWindowSize(ImVec2(600.000f, 1000.000f), ImGuiCond_Once);
    if(!ImGui::Begin("Inspector", nullptr, 2)) {
        ImGui::End();
        return;
    }

    static std::vector<std::string> components;
    static std::vector<std::string> classes;
    static std::vector<std::string> methods;
    static std::string current_comp = "";

    ImGui::Text("Components");
    if(ImGui::Button("Update##comp")) {
        components = Dumper::DumpComponentsString();
    }
    ImGui::SetNextItemWidth(150.000f);
    static int component_current_idx = 0; // Here we store our selection data as an index.
    static ImGuiTextFilter c_filter;
    c_filter.Draw("Search##compfilter");
    if(ImGui::BeginListBox("##Components", ImVec2(-FLT_MIN, 200))) {
        for(size_t n = 0; n < components.size(); n++) {
            if(!c_filter.PassFilter(components[n].c_str())) {
                continue;
            }
            const bool comp_is_selected = (component_current_idx == (int)n);
            if(ImGui::Selectable(components[n].c_str(), comp_is_selected))
                component_current_idx = (int)n;

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if(comp_is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndListBox();
    }
    ImGui::Spacing();
    ImGui::Text("Classes");
    if(ImGui::Button("Update##class")) {
        classes      = Dumper::DumpClassesString(components[component_current_idx]);
        current_comp = components[component_current_idx];
    }

    ImGui::SetNextItemWidth(150.000f);
    static int class_current_idx = 0; // Here we store our selection data as an index.
    static ImGuiTextFilter cl_filter;
    cl_filter.Draw("Search##classfilter");
    if(ImGui::BeginListBox("##Class", ImVec2(-FLT_MIN, 200))) {
        for(size_t n = 0; n < classes.size(); n++) {
            if(!cl_filter.PassFilter(classes[n].c_str())) {
                continue;
            }
            const bool class_is_selected = (class_current_idx == (int)n);
            if(ImGui::Selectable(classes[n].c_str(), class_is_selected)) {
                class_current_idx = (int)n;
            }

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if(class_is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndListBox();
    }

    ImGui::Spacing();
    ImGui::Text("Methods");
    if(ImGui::Button("Update##Methods")) {
        methods = Dumper::DumpMethodsString(current_comp, classes[class_current_idx]);
    }

    ImGui::SetNextItemWidth(150.000f);
    static int method_current_idx = 0; // Here we store our selection data as an index.
    static ImGuiTextFilter me_filter;
    me_filter.Draw("Search##methodfilter");
    if(ImGui::BeginListBox("##Methods", ImVec2(-FLT_MIN, 200))) {
        for(size_t n = 0; n < methods.size(); n++) {
            if(!me_filter.PassFilter(methods[n].c_str())) {
                continue;
            }
            const bool meth_is_selected = (method_current_idx == (int)n);
            if(ImGui::Selectable(methods[n].c_str(), meth_is_selected))
                method_current_idx = (int)n;

            // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if(meth_is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndListBox();
    }

    ImGui::End();
}

namespace Tabs
{
    void Main()
    {
        ImGui::Text(OBFUSCATE("Press INSERT to toggle the menu"));
        ImGui::Text(OBFUSCATE("Press END to close the cheat"));
        ImGui::Separator();
        ImGui::Text(OBFUSCATE("To use the menu your game must be windowed, you can fullscreen after."));
        ImGui::Text(OBFUSCATE("Leave all values default if you don't know what they do."));
        ImGui::Separator();
        ImGui::Text(OBFUSCATE("You can press Control and Click on a slider to edit it by typing."));
    }

    void Visuals()
    {
        if(ImGui::CollapsingHeader(OBFUSCATE("Visual"))) {
            ImGui::Checkbox(OBFUSCATE("FOV Circle"), &Variables::Visuals::EnableCircleFov);
            HelpMarker(OBFUSCATE("Displays a FOV Circle in the middle of the screen."));
            if(Variables::Visuals::EnableCircleFov) {
                Utils::FSlider(OBFUSCATE("##CircleFOV"), &Variables::Visuals::CircleFov, 0, 360, OBFUSCATE("Circle FOV: %.0f"));
                HelpMarker(OBFUSCATE("Changes the Circle size."));
                ImGui::ColorEdit3(OBFUSCATE("Circle Colour"), (float *)&Variables::Visuals::CircleColor);
                HelpMarker(OBFUSCATE("Changes the Circle colour."));
                ImGui::Checkbox(OBFUSCATE("Rainbow?"), &Variables::Visuals::EnableRainbowCircle);
                HelpMarker(OBFUSCATE("Makes the Circle rainbow, ignores the set Circle colour."));
                ImGui::Separator();
            }

            ImGui::Checkbox(OBFUSCATE("Crosshair"), &Variables::Visuals::EnableCrosshair);
            HelpMarker(OBFUSCATE("Displays a Crosshair in the middle of the screen."));
            if(Variables::Visuals::EnableCrosshair) {
                Utils::FSlider(OBFUSCATE("##CrosshairSize"), &Variables::Visuals::CrosshairSize, 1, 20, "Crosshair Size: %.0f");
                HelpMarker(OBFUSCATE("Changes the Crosshair size."));
                ImGui::ColorEdit3(OBFUSCATE("Crosshair Colour"), (float *)&Variables::Visuals::CrosshairColor);
                HelpMarker(OBFUSCATE("Changes the Crosshair colour."));
                ImGui::Checkbox(OBFUSCATE("Rainbow?"), &Variables::Visuals::EnableRainbowCrosshair);
                HelpMarker(OBFUSCATE("Makes the Crosshair rainbow, ignores the set Crosshair colour."));
                ImGui::Separator();
            }

            ImGui::Checkbox(OBFUSCATE("Watermark"), &Variables::Visuals::EnableWatermark);
            HelpMarker(OBFUSCATE("Draws a Watermark in the top left of the screen."));
            if(Variables::Visuals::EnableWatermark) {
                ImGui::Checkbox(OBFUSCATE("Show FPS"), &Variables::Visuals::EnableFPS);
                HelpMarker(OBFUSCATE("Displays FPS along side the watermark."));
                ImGui::Separator();
            }
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Game"))) {
            ImGui::Checkbox(OBFUSCATE("Chams"), &Variables::Gameplay::XRay);
            HelpMarker(OBFUSCATE("Makes all players visible through walls."));

            ImGui::Checkbox(OBFUSCATE("FOV Changer"), &Variables::Gameplay::FOVChanger);
            HelpMarker(OBFUSCATE("Changes your FOV."));
            if(Variables::Gameplay::FOVChanger) {
                Utils::FSlider(OBFUSCATE("##FOVValue"), &Variables::Gameplay::FOVValue, 0.0f, 360.0f, OBFUSCATE("FOV Value: %.0f"));
                HelpMarker(OBFUSCATE("I recommend setting it set at 140 for highest FOV while keeping camera functionality."));
            }

            ImGui::Checkbox(OBFUSCATE("Enemy Marker"), &Variables::Gameplay::EnemyMarker);
            HelpMarker(OBFUSCATE("Marks enemies when they are shot."));
            if(Variables::Gameplay::EnemyMarker) {
                Utils::FSlider(OBFUSCATE("##ChargeTime"), &Variables::Gameplay::MarkerCharge, 0.0f, 1000000.0f, OBFUSCATE("Charge Time: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for quickest charge."));
            }
        }
    }

    void Player()
    {
        if(ImGui::CollapsingHeader(OBFUSCATE("Movement"))) {
            ImGui::Checkbox(OBFUSCATE("Speed Hack"), &Variables::Gameplay::PlayerSpeed);
            HelpMarker(OBFUSCATE("Speeds up your player."));
            if(Variables::Gameplay::PlayerSpeed) {
                Utils::FSlider(OBFUSCATE("##SpeedMultiplier"), &Variables::Gameplay::PlayerSpeedMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Speed Hack: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it at 1000. The Speed Multiplier caps out at some point around 1000."));
            }

            ImGui::Checkbox(OBFUSCATE("Jetpack Fly"), &Variables::Gameplay::JetpackFly);
            HelpMarker(OBFUSCATE("Hold space to fly. Only press it once, it will toggle itself off, to deactivate press it once again."));

            ImGui::Checkbox(OBFUSCATE("Double Jump"), &Variables::Gameplay::DoubleJump);
            HelpMarker(OBFUSCATE("Allows you to jump twice."));
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Immunities"))) {
            ImGui::Checkbox(OBFUSCATE("Fire Immunity"), &Variables::Gameplay::FireImmunity);
            HelpMarker(OBFUSCATE("Makes you immune to the fire effect."));
            ImGui::Checkbox(OBFUSCATE("Toxic Immunity"), &Variables::Gameplay::ToxicImmunity);
            HelpMarker(OBFUSCATE("Makes you immune to the toxic effect."));
            ImGui::Checkbox(OBFUSCATE("Bleed Immunity"), &Variables::Gameplay::BleedImmunity);
            HelpMarker(OBFUSCATE("Makes you immune to the bleed effect."));
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Miscellaneous"))) {
            ImGui::Checkbox(OBFUSCATE("Kill Aura"), &Variables::Gameplay::FrostAura);
            HelpMarker(OBFUSCATE("Gives you a damage aura."));
            if(Variables::Gameplay::FrostAura) {
                Utils::FSlider(OBFUSCATE("##AuraRadius"), &Variables::Gameplay::AuraRadius, 0.0f, 1000000.0f, OBFUSCATE("Aura Radius: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for biggest area of effect."));
                Utils::FSlider(OBFUSCATE("##AuraAngle)"), &Variables::Gameplay::AuraAngle, 0.0f, 360.0f, OBFUSCATE("Aura Angle: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for biggest area of effect."));
                Utils::FSlider(OBFUSCATE("##AuraMultiplier"), &Variables::Gameplay::AuraMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Aura Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }

            ImGui::Checkbox(OBFUSCATE("Invisibility"), &Variables::Gameplay::Invisibility);
            HelpMarker(OBFUSCATE("Makes you invisible after a kill or respawning."));
            if(Variables::Gameplay::Invisibility) {
                Utils::FSlider(OBFUSCATE("##InvisibilityDuration"), &Variables::Gameplay::SelfInvisibilityDuration, 0.0f, 1000000.0f, OBFUSCATE("Invisibility Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
            }

            ImGui::Checkbox(OBFUSCATE("Gadget Cooldown Modifier"), &Variables::Miscellaneous::GadgetCooldown);
            HelpMarker(OBFUSCATE("Makes your gadgets come back instantly."));
            if(Variables::Miscellaneous::GadgetCooldown) {
                Utils::FSlider(OBFUSCATE("##GadgetCooldown"), &Variables::Miscellaneous::CooldownValue, 0.0f, 1000000.0f, OBFUSCATE("Gadget Cooldown: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant cooldown."));
            }

            ImGui::Checkbox(OBFUSCATE("Anti Headshot"), &Variables::Gameplay::AntiHeadshot);
            HelpMarker(OBFUSCATE("Reduces the damage you take from headshots."));
            if(Variables::Gameplay::AntiHeadshot) {
                Utils::FSlider(OBFUSCATE("##ReductionMultiplier"), &Variables::Gameplay::ReductionMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Reduction Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest reduction."));
            }

            ImGui::Checkbox(OBFUSCATE("Heal"), &Variables::Miscellaneous::HealthOnline);
            HelpMarker(OBFUSCATE("Heals you as you shoot."));

            ImGui::Checkbox(OBFUSCATE("Godmode"), &Variables::Gameplay::Godmode);
            HelpMarker(OBFUSCATE("Stops you taking any damage."));
        }
    }

    void Weapons()
    {
        if(ImGui::CollapsingHeader(OBFUSCATE("Aim"))) {
            ImGui::Checkbox(OBFUSCATE("AOE Bullets"), &Variables::Weapon::AOEBullets);
            HelpMarker(OBFUSCATE("Allows you to kill people from anywhere on the map without aiming at them."));
            if(Variables::Weapon::AOEBullets) {
                Utils::FSlider(OBFUSCATE("##FrontAngle"), &Variables::Weapon::FrontAngle, 0.0f, 360.0f, OBFUSCATE("Front Angle: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for highest range."));
                Utils::FSlider(OBFUSCATE("##BackAngle"), &Variables::Weapon::BackAngle, 0.0f, 360.0f, OBFUSCATE("Back Angle: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for highest range."));
                Utils::FSlider(OBFUSCATE("##AOERadius"), &Variables::Weapon::AOERadius, 0.0f, 1000000.0f, OBFUSCATE("AOE Radius: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for biggest area of effect."));
                Utils::FSlider(OBFUSCATE("##FrontMultiplier"), &Variables::Weapon::FrontMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Front Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
                Utils::FSlider(OBFUSCATE("##BackMultiplier"), &Variables::Weapon::BackMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Back Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
                Utils::FSlider(OBFUSCATE("##SideMultiplier"), &Variables::Weapon::SideMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Side Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }

            ImGui::Checkbox(OBFUSCATE("Silent Aim"), &Variables::Weapon::SilentAim);
            HelpMarker(OBFUSCATE("Makes your bullets hit no matter where you look."));
            if(Variables::Weapon::SilentAim) {
                Utils::FSlider(OBFUSCATE("##SilentMultiplier"), &Variables::Weapon::SilentMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Silent Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
                Utils::FSlider(OBFUSCATE("##SilentRange"), &Variables::Weapon::SilentRange, 0.0f, 1000000.0f, OBFUSCATE("Silent Range: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest range."));
            }
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Modifiers"))) {
            ImGui::Checkbox(OBFUSCATE("Fire Rate Modifier"), &Variables::Weapon::FireRate);
            HelpMarker(OBFUSCATE("Allows you to modify your shoot speed. Might kick you."));
            if(Variables::Weapon::FireRate) {
                Utils::FSlider(OBFUSCATE("##FireRateValue"), &Variables::Weapon::RapidValue, 0.0f, 1000000.0f, OBFUSCATE("Fire Rate: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for fastest fire rate."));
            }

            ImGui::Checkbox(OBFUSCATE("Reload Modifier"), &Variables::Weapon::ReloadModifier);
            HelpMarker(OBFUSCATE("Allows you to modify your reload."));
            if(Variables::Weapon::ReloadModifier) {
                Utils::FSlider(OBFUSCATE("##ReloadValue"), &Variables::Weapon::ReloadValue, 0.0f, 99999.0f, OBFUSCATE("Reload Value: %.1f"));

                HelpMarker(OBFUSCATE("I recommend keeping it set at 99999 for no reload."));
            }

            ImGui::Checkbox(OBFUSCATE("Recoil Modifier"), &Variables::Weapon::RecoilModifier);
            HelpMarker(OBFUSCATE("Modifys your weapon recoil."));
            if(Variables::Weapon::RecoilModifier) {
                Utils::FSlider(OBFUSCATE("##RecoilValue"), &Variables::Weapon::RecoilValue, 0.0f, 1000000.0f, OBFUSCATE("Recoil Value: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for no recoil."));
            }

            ImGui::Checkbox(OBFUSCATE("Infinite Ammo"), &Variables::Weapon::InfiniteAmmo);
            HelpMarker(OBFUSCATE("Gives you unlimited ammo, still have to reload."));

            ImGui::Checkbox(OBFUSCATE("Range Modifier"), &Variables::Weapon::RangeModifier);
            HelpMarker(OBFUSCATE("Modifys your weapon range."));
            if(Variables::Weapon::RangeModifier) {
                Utils::FSlider(OBFUSCATE("##RangeValue"), &Variables::Weapon::RangeValue, 0.0f, 1000000.0f, OBFUSCATE("Range Value: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for infinite range."));
                Utils::FSlider(OBFUSCATE("##DamageRange"), &Variables::Weapon::DamageRange, 0.0f, 1000000.0f, OBFUSCATE("Damage Range: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 to damage at any range."));
                Utils::FSlider(OBFUSCATE("##RangeValue"), &Variables::Weapon::ShootDistance, 0.0f, 1000000.0f, OBFUSCATE("Shoot Distance: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for infinite range."));
            }

            ImGui::Checkbox(OBFUSCATE("Scope Modifier"), &Variables::Weapon::ScopeModifier);
            HelpMarker(OBFUSCATE("Modifys your weapons scope."));
            if(Variables::Weapon::ScopeModifier) {
                Utils::FSlider(OBFUSCATE("##ScopeValue"), &Variables::Weapon::ScopeZoomValue, 0.0f, 1000000.0f, OBFUSCATE("Scope Value: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for instant ADS."));
                ImGui::Checkbox(OBFUSCATE("Force Scope"), &Variables::Weapon::ForceScope);
                HelpMarker(OBFUSCATE("Allows you to scope in with weapons that don't have a scope."));
                ImGui::Separator();
            }

            ImGui::Checkbox(OBFUSCATE("Charge Modifier"), &Variables::Weapon::ChargeModifier);
            HelpMarker(OBFUSCATE("Modifys your weapons charge time."));
            if(Variables::Weapon::ChargeModifier) {
                Utils::FSlider(OBFUSCATE("##ChargeMax"), &Variables::Weapon::ChargeMax, 0.0f, 1000000.0f, OBFUSCATE("Charge Max: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant max charge."));
                Utils::FSlider(OBFUSCATE("##ChargeDuration"), &Variables::Weapon::ChargeDuration, 0.0f, 1000000.0f, OBFUSCATE("Charge Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant charge."));
            }

            ImGui::Checkbox(OBFUSCATE("Full Auto"), &Variables::Weapon::FullAuto);
            HelpMarker(OBFUSCATE("Makes any gun fully automatic."));
            if(Variables::Weapon::FullAuto) {
                Utils::FSlider(OBFUSCATE("##ShootDelay"), &Variables::Weapon::ShootDelay, 0.000001f, 1000000.0f, OBFUSCATE("Shoot Delay: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0.000001 for instant fire."));
                Utils::FSlider(OBFUSCATE("##BulletDelay"), &Variables::Weapon::BulletDelay, 0.000001f, 1000000.0f, OBFUSCATE("Bullet Delay: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0.000001 for instant fire."));
                Utils::FSlider(OBFUSCATE("##DelayInBurstShooting"), &Variables::Weapon::DelayInBurstShooting, 0.0f, 1000000.0f, OBFUSCATE("Burst Delay: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant fire."));
                Utils::FSlider(OBFUSCATE("##ChargeTime"), &Variables::Weapon::ChargeTime, 0.0f, 1000000.0f, OBFUSCATE("Charge Time: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant charge."));
            }

            ImGui::Checkbox(OBFUSCATE("No Spread"), &Variables::Weapon::NoSpread);
            HelpMarker(OBFUSCATE("Stops bullets spreading on guns like shotguns."));

            ImGui::Checkbox(OBFUSCATE("Zoom XRay"), &Variables::Weapon::ZoomXRay);
            HelpMarker(OBFUSCATE("Gives you XRay vision when aiming down a scope."));

            ImGui::Checkbox(OBFUSCATE("Force Criticals"), &Variables::Weapon::ForceCriticals);
            HelpMarker(OBFUSCATE("Forces critical hits. Only visual?"));

            ImGui::Checkbox(OBFUSCATE("Damage Multiplier"), &Variables::Weapon::DamageMultiplier);
            HelpMarker(OBFUSCATE("Modifys your weapons damage."));
            if(Variables::Weapon::DamageMultiplier) {
                Utils::FSlider(OBFUSCATE("##DamageValue"), &Variables::Weapon::DamageMultiplierValue, 0.0f, 100.0f, OBFUSCATE("Damage Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Effects"))) {
            ImGui::Checkbox(OBFUSCATE("Poison Effect"), &Variables::Weapon::PoisonEffect);
            HelpMarker(OBFUSCATE("Gives your damage the poison effect."));
            if(Variables::Weapon::PoisonEffect) {
                Utils::FSlider(OBFUSCATE("##PoisonDuration"), &Variables::Weapon::PoisonDuration, 0.0f, 1000000.0f, OBFUSCATE("Poison Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
                Utils::FSlider(OBFUSCATE("##PoisonCount"), &Variables::Weapon::PoisonCount, 0.0f, 1000000.0f, OBFUSCATE("Poison Count: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest damage."));
                Utils::FSlider(OBFUSCATE("##PoisonMultiplier"), &Variables::Weapon::PoisonMultiplier, 0.0f, 100.0f, OBFUSCATE("Poison Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }

            ImGui::Checkbox(OBFUSCATE("Stun Effect"), &Variables::Weapon::StunEffect);
            HelpMarker(OBFUSCATE("Gives your damage the stun effect."));
            if(Variables::Weapon::StunEffect) {
                Utils::FSlider(OBFUSCATE("##StunDuration"), &Variables::Weapon::StunDuration, 0.0f, 1000000.0f, OBFUSCATE("Stun Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
                Utils::FSlider(OBFUSCATE("##StunRadius"), &Variables::Weapon::StunRadius, 0.0f, 1000000.0f, OBFUSCATE("Stun Radius: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest area of effect."));
                Utils::FSlider(OBFUSCATE("##StunMultiplier"), &Variables::Weapon::StunMultiplier, 0.0f, 100.0f, OBFUSCATE("Stun Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }

            ImGui::Checkbox(OBFUSCATE("Curse Effect"), &Variables::Weapon::CurseEffect);
            HelpMarker(OBFUSCATE("Gives your damage the curse effect."));
            if(Variables::Weapon::CurseEffect) {
                Utils::FSlider(OBFUSCATE("##CurseDuration"), &Variables::Weapon::CurseDuration, 0.0f, 1000000.0f, OBFUSCATE("Curse Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest damage."));
                Utils::FSlider(OBFUSCATE("##CurseMultiplier"), &Variables::Weapon::CurseMultiplier, 0.0f, 100.0f, OBFUSCATE("Curse Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }

            ImGui::Checkbox(OBFUSCATE("Shock Effect"), &Variables::Weapon::Shocker);
            HelpMarker(OBFUSCATE("Gives your damage the shock effect."));
            if(Variables::Weapon::Shocker) {
                Utils::FSlider(OBFUSCATE("##ShockerRange"), &Variables::Weapon::ShockerRange, 0.0f, 1000000.0f, OBFUSCATE("Shocker Range: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest range."));
                Utils::FSlider(OBFUSCATE("##ShockerMultiplier"), &Variables::Weapon::ShockerMultiplier, 0.0f, 100.0f, OBFUSCATE("Shocker Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
            }

            ImGui::Checkbox(OBFUSCATE("Charm Effect"), &Variables::Weapon::CharmEffect);
            HelpMarker(OBFUSCATE("Gives your damage the charm effect."));
            if(Variables::Weapon::CharmEffect) {
                Utils::FSlider(OBFUSCATE("##CharmDuration"), &Variables::Weapon::CharmDuration, 0.0f, 1000000.0f, OBFUSCATE("Charm Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
            }

            ImGui::Checkbox(OBFUSCATE("Blind Effect"), &Variables::Weapon::BlindEffect);
            HelpMarker(OBFUSCATE("Gives your damage the blind effect."));
            if(Variables::Weapon::BlindEffect) {
                Utils::FSlider(OBFUSCATE("##BlindDuration"), &Variables::Weapon::BlindDuration, 0.0f, 1000000.0f, OBFUSCATE("Blind Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
            }

            ImGui::Checkbox(OBFUSCATE("Weakness Effect"), &Variables::Weapon::WeaknessEffect);
            HelpMarker(OBFUSCATE("Gives your damage the weakness effect."));
            if(Variables::Weapon::WeaknessEffect) {
                Utils::FSlider(OBFUSCATE("##WeaknessDuration"), &Variables::Weapon::WeaknessDuration, 0.0f, 1000000.0f, OBFUSCATE("Weakness Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
            }

            ImGui::Checkbox(OBFUSCATE("Lightning Effect"), &Variables::Weapon::LightningEffect);
            HelpMarker(OBFUSCATE("Gives your damage the lightning effect."));
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Bullets"))) {
            ImGui::Checkbox(OBFUSCATE("Flamethrower"), &Variables::Weapon::Flamethrower);
            HelpMarker(OBFUSCATE("Makes your bullets shoot flames."));

            ImGui::Checkbox(OBFUSCATE("Explosive Bullets"), &Variables::Weapon::ExplosiveBullets);
            HelpMarker(OBFUSCATE("Makes your bullets explode on impact."));

            ImGui::Checkbox(OBFUSCATE("Shotgun Bullets"), &Variables::Weapon::Shotgun);
            HelpMarker(OBFUSCATE("Makes your bullets shotgun bullets."));

            ImGui::Checkbox(OBFUSCATE("Railgun"), &Variables::Weapon::Railgun);
            HelpMarker(OBFUSCATE("Makes your bullets railgun bullets."));
            if(Variables::Weapon::Railgun) {
                ImGui::Checkbox(OBFUSCATE("Railgun Clipping"), &Variables::Weapon::RailgunClipping);
                HelpMarker(OBFUSCATE("Makes your railgun bullets shoot through walls."));
                ImGui::Separator();
            }

            ImGui::Checkbox(OBFUSCATE("Bazooka"), &Variables::Weapon::Bazooka);
            HelpMarker(OBFUSCATE("Makes your bullets bazookas."));

            ImGui::Checkbox(OBFUSCATE("Harpoon"), &Variables::Weapon::Harpoon);
            HelpMarker(OBFUSCATE("Makes your bullets harpoons."));
            if(Variables::Weapon::Harpoon) {
                Utils::FSlider(OBFUSCATE("##HarpoonDistance"), &Variables::Weapon::HarpoonDistance, 0.0f, 1000000.0f, OBFUSCATE("Harpoon Distance: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping this set at 1000000 for highest range."));
            }
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Misc"))) {
            ImGui::Checkbox(OBFUSCATE("Polymorpher"), &Variables::Weapon::ForcePolymorpher);
            HelpMarker(OBFUSCATE("Changes anyone you shoot to the type selected."));
            if(Variables::Weapon::ForcePolymorpher) {
                Utils::FSlider(OBFUSCATE("##PolymorpherDuration"), &Variables::Weapon::PolymorpherDuration, 0.0f, 1000000.0f, OBFUSCATE("Polymorpher Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
                Utils::FSlider(OBFUSCATE("##PolymorpherHealth"), &Variables::Weapon::PolymorpherHealth, 0.0f, 1000000.0f, OBFUSCATE("Polymorpher Health: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 so they can't die and become normal again."));

                const char *items[] = { "Sheep", "Beetle", "Mutant", "Cube" };
                const int numItems  = sizeof(items) / sizeof(items[0]);

                if(ImGui::BeginCombo("Select Type", items[Variables::Weapon::PolymorpherType])) {
                    for(int i = 0; i < numItems; ++i) {
                        bool isSelected = (Variables::Weapon::PolymorpherType == i);
                        if(ImGui::Selectable(items[i], isSelected))
                            Variables::Weapon::PolymorpherType = i;

                        if(isSelected)
                            ImGui::SetItemDefaultFocus();
                    }
                    ImGui::EndCombo();
                }
                HelpMarker(OBFUSCATE("Sets the entity you turn people into when you shoot them."));
            }

            ImGui::Checkbox(OBFUSCATE("Head Magnifier"), &Variables::Weapon::HeadMagnifier);
            HelpMarker(OBFUSCATE("Enlarges anyone you shoots head."));
            if(Variables::Weapon::HeadMagnifier) {
                Utils::FSlider(OBFUSCATE("##MagnifierDuration"), &Variables::Weapon::MagnifierDuration, 0.0f, 1000000.0f, OBFUSCATE("Magnifier Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
            }

            ImGui::Checkbox(OBFUSCATE("Jump Disabler"), &Variables::Weapon::JumpDisabler);
            HelpMarker(OBFUSCATE("Disables the jump of anyone who you shoot."));
            if(Variables::Weapon::JumpDisabler) {
                Utils::FSlider(OBFUSCATE("##DisabledDuration"), &Variables::Weapon::JumpDisabledDuration, 0.0f, 1000000.0f, OBFUSCATE("Disabled Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
            }

            ImGui::Checkbox(OBFUSCATE("Reflection Rays"), &Variables::Weapon::ReflectionRays);
            HelpMarker(OBFUSCATE("Makes a your screen a disco."));
            if(Variables::Weapon::ReflectionRays) {
                Utils::FSlider(OBFUSCATE("##ReflectionCount"), &Variables::Weapon::ReflectionCount, 0.0f, 1000000.0f, OBFUSCATE("Reflection Count: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 50 the most amount of reflections, without freezing your game."));
            }

            ImGui::Checkbox(OBFUSCATE("Anti Barrier"), &Variables::Weapon::AntiBarrier);
            HelpMarker(OBFUSCATE("Allows you to shoot through barriers."));
        }
    }

    void Pet()
    {
        ImGui::Checkbox(OBFUSCATE("Pet Health"), &Variables::Pet::PetHealth);
        HelpMarker(OBFUSCATE("Changes your pets health."));
        if(Variables::Pet::PetHealth) {
            Utils::FSlider(OBFUSCATE("##PetHealth"), &Variables::Pet::PetHealthValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Health: %.1f"));
            HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible health."));
        }

        ImGui::Checkbox(OBFUSCATE("Pet Damage"), &Variables::Pet::PetDamage);
        HelpMarker(OBFUSCATE("Changes your pets damage."));
        if(Variables::Pet::PetDamage) {
            Utils::FSlider(OBFUSCATE("##PetDamage"), &Variables::Pet::PetDamageValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Damage: %.1f"));
            HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible damage."));
        }

        ImGui::Checkbox(OBFUSCATE("Pet Speed"), &Variables::Pet::PetSpeed);
        HelpMarker(OBFUSCATE("Changes your pets speed."));
        if(Variables::Pet::PetSpeed) {
            Utils::FSlider(OBFUSCATE("##PetSpeed"), &Variables::Pet::PetSpeedValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Speed: %.1f"));
            HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible speed."));
        }
    }

    void Exploits()
    {
        if(ImGui::CollapsingHeader(OBFUSCATE("Game"))) {
            ImGui::Checkbox(OBFUSCATE("Match Invisibility"), &Variables::Gameplay::MatchInvisibility);
            HelpMarker(OBFUSCATE("Makes everyone invisible."));
            if(Variables::Gameplay::MatchInvisibility) {
                Utils::FSlider(OBFUSCATE("##InvisibilityDuration"), &Variables::Gameplay::MatchInvisibilityDuration, 0.0f, 1000000.0f, OBFUSCATE("Invisibility Duration: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
            }

            ImGui::Checkbox(OBFUSCATE("Game Speed"), &Variables::Gameplay::GameSpeed);
            HelpMarker(OBFUSCATE("Speeds up your whole game including bullets, movement, loading etc."));
            if(Variables::Gameplay::GameSpeed) {
                ImGui::Text(OBFUSCATE("Game Speed Key: %s"), Utils::GetKeyNameFromVirtualKey(Variables::Gameplay::GameSpeedKey).c_str());
                Utils::FSlider(OBFUSCATE("##SpeedMultiplier"), &Variables::Gameplay::GameSpeedMultiplier, 0.0f, 100.0f, OBFUSCATE("Speed Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("If you change the Speed Multiplier you must toggle Game Speed off and back on for it to update. Anything over 2 is likely to kick you or crash you."));
            }

            ImGui::Checkbox(OBFUSCATE("Score Modifier"), &Variables::Weapon::ScoreModifier);
            HelpMarker(OBFUSCATE("Modifys the score you get from a kill."));
            if(Variables::Weapon::ScoreModifier) {
                Utils::FSlider(OBFUSCATE("##KillModifier"), &Variables::Weapon::KillModifier, 0.0f, 1000000.0f, OBFUSCATE("Kill Modifier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
                Utils::FSlider(OBFUSCATE("##AssistModifier"), &Variables::Weapon::AssistModifier, 0.0f, 1000000.0f, OBFUSCATE("Assist Modifier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
                Utils::FSlider(OBFUSCATE("##RevengeModifier"), &Variables::Weapon::RevengeModifier, 0.0f, 1000000.0f, OBFUSCATE("Revenge Modifier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
            }
        }

        if(ImGui::CollapsingHeader(OBFUSCATE("Account"))) {
            ImGui::Checkbox(OBFUSCATE("Currency Modifier"), &Variables::Miscellaneous::AddCurrency);
            HelpMarker(OBFUSCATE("Adds currency to your account."));
            if(Variables::Miscellaneous::AddCurrency) {
                Utils::FSlider(OBFUSCATE("##CurrencyAmount"), &Variables::Miscellaneous::CurrencyAmount, 0.0f, 1000000.0f, OBFUSCATE("Currency Amount: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it set at 1000 to be safe."));
                if(ImGui::BeginCombo(OBFUSCATE("##Select Currency"), CurrencyList[Variables::Miscellaneous::SelectedCurrency])) {
                    for(int i = 0; i < IM_ARRAYSIZE(CurrencyList); i++) {
                        const bool is_selected = (Variables::Miscellaneous::SelectedCurrency == i);
                        if(ImGui::Selectable(CurrencyList[i], is_selected))
                            Variables::Miscellaneous::SelectedCurrency = i;

                        if(is_selected)
                            ImGui::SetItemDefaultFocus();
                    }
                    ImGui::EndCombo();
                }
                ImGui::SameLine();
                if(ImGui::Button(OBFUSCATE("Add Currency"))) {
                    Variables::Miscellaneous::IsAddCurrency = true;
                }
            }

            ImGui::Checkbox(OBFUSCATE("Infinite Gems"), &Variables::Miscellaneous::InfiniteGems);
            HelpMarker(OBFUSCATE("Go into the armoury then double click any weapon and go to gallery, once enabled spam on any of the locked weapons."));

            ImGui::Checkbox(OBFUSCATE("Lottery"), &Variables::Miscellaneous::Lottery);
            HelpMarker(OBFUSCATE("Makes lottery boxes free."));
            if(Variables::Miscellaneous::Lottery) {
                Utils::FSlider(OBFUSCATE("##LotteryPrice"), &Variables::Miscellaneous::LotteryPrice, -100.0f, 100.0f, OBFUSCATE("Lottery Price: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it at 0. Anything below 0 will give you the amount of you set."));
            }

            ImGui::Checkbox(OBFUSCATE("Premium Pass"), &Variables::Miscellaneous::PremiumPass);
            HelpMarker(OBFUSCATE("Gives you the premium pixel pass. Click on the pass to claim the rewards. Removes the pass when feature is turned off."));

            ImGui::Checkbox(OBFUSCATE("Reward Multiplier"), &Variables::Miscellaneous::RewardMultiplier);
            HelpMarker(OBFUSCATE("Changes the amount of rewards you get from doing something. Possibility to get you banned."));
            if(Variables::Miscellaneous::RewardMultiplier) {
                Utils::FSlider(OBFUSCATE("##Multiplier"), &Variables::Miscellaneous::RewardMultiplierAmount, 0.0f, 250.0f, OBFUSCATE("Multiplier: %.1f"));
                HelpMarker(OBFUSCATE("I recommend keeping it at 10 for safest usage."));
            }

            ImGui::Checkbox(OBFUSCATE("Max Level"), &Variables::Miscellaneous::MaxLevel);
            HelpMarker(OBFUSCATE("Gives you max level. Click 1 and Click 2 when it says. Possibility to get you banned."));
            if(Variables::Miscellaneous::MaxLevel) {
                ImGui::Checkbox(OBFUSCATE("Max Level 1"), &Variables::Miscellaneous::MaxLevelOne);
                HelpMarker(OBFUSCATE("Tick this and spin the chest then untick when the chest is spinning."));
                ImGui::Checkbox(OBFUSCATE("Max Level 2"), &Variables::Miscellaneous::MaxLevelTwo);
                HelpMarker(OBFUSCATE("Tick this and spin the chest then untick when the chest is spinning, repeat until you get all the rewards, normally twice."));
            }

            ImGui::Checkbox(OBFUSCATE("Add Weapons"), &Variables::Miscellaneous::AddWeapons);
            if(Variables::Miscellaneous::AddWeapons) {
                static int WeaponIndex = 0;
                if(ImGui::BeginCombo("##SelectWeapon", WeaponNames[WeaponIndex].c_str())) {
                    for(int i = 0; i < WeaponNames.size(); ++i) {
                        const bool isSelected = (WeaponIndex == i);
                        if(ImGui::Selectable(WeaponNames[i].c_str(), isSelected)) {
                            WeaponIndex                          = i;
                            Variables::Miscellaneous::WeaponName = WeaponNames[i];
                        }
                    }
                    ImGui::EndCombo();
                }
                ImGui::Checkbox(OBFUSCATE("Add All Weapons"), &Variables::Miscellaneous::AddAllWeapons);
                HelpMarker(OBFUSCATE("Adds all weapons to your account. Might crash the game or freeze it, just restart and it should have everything unlocked."));
                ImGui::Checkbox(OBFUSCATE("Auto Upgrade"), &Variables::Miscellaneous::AutoUpgrade);
                HelpMarker(OBFUSCATE("Automatically upgrades the weapons you get. Works for Add All and Individal weapons."));
            }
        }
    }

    void Settings()
    {
        ImGui::Checkbox(OBFUSCATE("ImGui Demo"), &Variables::Visuals::ImGuiDemo);
        HelpMarker(OBFUSCATE("Shows the ImGui demo window."));
        ImGui::Checkbox(OBFUSCATE("Dumper"), &Variables::Visuals::EnableDumper);
        HelpMarker(OBFUSCATE("Dumps the game assembly."));
#ifdef _DEBUG
        ImGui::Separator();
        ImGui::Text(OBFUSCATE("Developer Logs"));
#endif
    }
}

void Drawing::Draw()
{
    if(Variables::Visuals::EnableDumper)
        DrawInspector();

    if(isActive()) {
        StyleInnit();

        if(!ImGui::Begin(OBFUSCATE("@bosslawl"), 0, 96)) {
            ImGui::End();
            return;
        }

        if(ImGui::BeginTabBar(OBFUSCATE("##tabs"), ImGuiTabBarFlags_None)) {
            if(ImGui::BeginTabItem(OBFUSCATE("Main"))) {
                Tabs::Main();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem(OBFUSCATE("Visuals"))) {
                Tabs::Visuals();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem(OBFUSCATE("Player"))) {
                Tabs::Player();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem(OBFUSCATE("Pet"))) {
                Tabs::Pet();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem(OBFUSCATE("Weapons"))) {
                Tabs::Weapons();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem(OBFUSCATE("Exploits"))) {
                Tabs::Exploits();
                ImGui::EndTabItem();
            }
            if(ImGui::BeginTabItem(OBFUSCATE("Settings"))) {
                Tabs::Settings();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();
    }

    if(GetAsyncKeyState(VK_INSERT) & 1)
        bDraw = !bDraw;
}

void Drawing::Loops()
{
    if(Utils::KeyPressed(Variables::Gameplay::GameSpeedKey)) {
        Variables::Gameplay::GameSpeed = !Variables::Gameplay::GameSpeed;
        if(Variables::Gameplay::GameSpeed)
            Internal::UnityEngine::SetTimeScale(Variables::Gameplay::GameSpeedMultiplier);
        else
            Internal::UnityEngine::SetTimeScale(1.0f);
    }

    bool adding        = false;
    int addingprogress = 0;
    if(Variables::Miscellaneous::AddWeapons) {
        if(Variables::Miscellaneous::AddAllWeapons) {
            adding    = true;
            int count = -1;
            for(auto Weapon : WeaponNames) {
                count++;
                if(count < addingprogress)
                    continue;
                if(count > addingprogress + 25) {
                    addingprogress = addingprogress + 25;
                    break;
                }
                Internal::Miscellaneous::GiveWeapon(Utils::SystemString(Weapon), true, Variables::Miscellaneous::AutoUpgrade);
            }
            if(count >= WeaponNames.size() - 1) {
                adding         = false;
                addingprogress = 0;
            };
        } else {
            Internal::Miscellaneous::GiveWeapon(Utils::SystemString(Variables::Miscellaneous::WeaponName), true, Variables::Miscellaneous::AutoUpgrade);
        }
        if(!adding)
            Variables::Miscellaneous::AddAllWeapons = false;
    }

    if(Variables::Visuals::EnableCircleFov && Variables::Visuals::EnableRainbowCircle)
        Utils::UseFov(true);
    else if(Variables::Visuals::EnableCircleFov && !Variables::Visuals::EnableRainbowCircle)
        Utils::UseFov(false);

    if(Variables::Visuals::EnableCrosshair && Variables::Visuals::EnableRainbowCrosshair)
        Utils::UseCrosshair(true);
    else if(Variables::Visuals::EnableCrosshair && !Variables::Visuals::EnableRainbowCrosshair)
        Utils::UseCrosshair(false);

    if(Variables::Visuals::EnableWatermark && Variables::Visuals::EnableFPS)
        Utils::Watermark(true, OBFUSCATE("@bosslawl"), Variables::Visuals::WatermarkColor, ImVec4(255, 255, 255, 0));
    else if(Variables::Visuals::EnableWatermark && !Variables::Visuals::EnableFPS)
        Utils::Watermark(false, OBFUSCATE("@bosslawl"), Variables::Visuals::WatermarkColor, ImVec4(255, 255, 255, 0));

    if(Variables::Visuals::ImGuiDemo) {
        static bool ShowMeAGreatDemoWindow = true;
        ImGui::ShowDemoWindow(&ShowMeAGreatDemoWindow);
    }
}