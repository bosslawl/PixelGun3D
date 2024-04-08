#include "Drawing.h"
#include "../../Cheat/Functions/Functions.h"
#include "../../Cheat/Utils/Variables.h"

ImGuiWindowFlags Drawing::WindowFlags = 0;
bool Drawing::bDraw = true;
UI::WindowItem Drawing::lpSelectedWindow = { nullptr, "", "" };

bool Drawing::isActive()
{
	return bDraw == true;
}

namespace Tabs {
	void Main() {
		ImGui::Text(OBFUSCATE("Press INSERT to toggle the menu"));
		ImGui::Text(OBFUSCATE("Press END to close the cheat"));
		ImGui::Separator();
		ImGui::Text(OBFUSCATE("To use the menu you need to be in windowed mode or you can be in borderless windowed and press Alt+Enter."));
		ImGui::Text(OBFUSCATE("Leave all values default if you don't know what they do."));
	}

	void Visuals() {
		ImGui::Checkbox("FOV Circle", &Variables::EnableCircleFov);
		ImGui::SameLine();
		HelpMarker("Displays a FOV Circle in the middle of the screen.");
		if (Variables::EnableCircleFov)
		{
			ImGui::SliderFloat("##CircleFOV", &Variables::CircleFov, 0, 360, "Circle FOV: %.0f");
			ImGui::SameLine();
			HelpMarker("Changes the Circle size.");
			ImGui::ColorEdit3("Circle Colour", (float*)&Variables::CircleColour);
			ImGui::SameLine();
			HelpMarker("Changes the Circle colour.");
			ImGui::Checkbox("Rainbow?", &Variables::EnableRainbowCircle);
			ImGui::SameLine();
			HelpMarker("Makes the Circle rainbow, ignores the set Circle colour.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Crosshair", &Variables::EnableCrosshair);
		ImGui::SameLine();
		HelpMarker("Displays a Crosshair in the middle of the screen.");
		if (Variables::EnableCrosshair)
		{
			ImGui::SliderFloat("##CrosshairSize", &Variables::CrosshairSize, 1, 20, "Crosshair Size: %.0f");
			ImGui::SameLine();
			HelpMarker("Changes the Crosshair size.");
			ImGui::ColorEdit3("Crosshair Colour", (float*)&Variables::CrosshairColor);
			ImGui::SameLine();
			HelpMarker("Changes the Crosshair colour.");
			ImGui::Checkbox("Rainbow?", &Variables::EnableRainbowCrosshair);
			ImGui::SameLine();
			HelpMarker("Makes the Crosshair rainbow, ignores the set Crosshair colour.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Watermark", &Variables::EnableWatermark);
		ImGui::SameLine();
		HelpMarker("Draws a Watermark in the top left of the screen.");
		if (Variables::EnableWatermark)
		{
			ImGui::Checkbox("Show FPS", &Variables::EnableFPS);
			ImGui::SameLine();
			HelpMarker("Displays FPS along side the watermark.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Chams", &Variables::XRay);
		ImGui::SameLine();
		HelpMarker("Makes all players visible through walls.");
	}

	void Player() {
		ImGui::Checkbox("Speed Hack", &Variables::PlayerSpeed);
		ImGui::SameLine();
		HelpMarker("Speeds up your player.");
		if (Variables::PlayerSpeed)
		{
			ImGui::SliderFloat("##SpeedMultiplier", &Variables::SpeedValue, 0.0f, 1000000.0f, "Speed Hack: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it at 1000. The Speed Multiplier caps out at some point around 1000.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Infinite Jump", &Variables::InfiniteAmmo);
		ImGui::SameLine();
		HelpMarker("Allows you to jump forver. Infinite Jump is a bit buggy, you can spam it but will make you fall after a while unless you hold it.");
		if (Variables::InfiniteJump)
			ImGui::Text("Infinite Jump Key: %s", Utils::GetKeyNameFromVirtualKey(Variables::JumpKey).c_str());
		ImGui::Separator();

		ImGui::Checkbox("Jetpack Fly", &Variables::JetpackFly);
		ImGui::SameLine();
		HelpMarker("Hold space to fly. I wouldn't recommend enabling this and infinite jump at the same time. Only press it once, it will toggle itself off, to deactivate press it once again.");
		ImGui::Separator();

		ImGui::Checkbox("Invisibility", &Variables::Invisibility);
		ImGui::SameLine();
		HelpMarker("Makes everyone invisible.");
		ImGui::Separator();

		ImGui::Checkbox("Heal", &Variables::HealOnline);
		ImGui::SameLine();
		HelpMarker("Heals you. Might kick you. Possibly detected in future updates.");
		if (Variables::HealOnline)
		{
			ImGui::SliderFloat("##HealthValue", &Variables::HealthValue, 0.0f, 1000000.0f, "Health Value: %.1f");
			ImGui::SameLine();
			HelpMarker("How much health you restore. Not sure what to set it as, experiment.");
		}
	}

	void Weapons() {
		ImGui::Checkbox("Infinite Ammo", &Variables::InfiniteAmmo);
		ImGui::SameLine();
		HelpMarker("Gives you unlimited ammo, still have to reload.");
		if (Variables::InfiniteAmmo)
		{
			ImGui::Checkbox("InfiniteAmmoRPC", &Variables::AmmoOnline);
			ImGui::SameLine();
			HelpMarker("Stops your weapon using any ammo, no reloading required. Possibly detected in future updates. Might kick you.");
			if (Variables::AmmoOnline)
			{
				ImGui::SliderFloat("##AmmoValue", &Variables::AmmoValue, 0.0f, 1000000.0f, "Ammo Value: %.1f");
				ImGui::SameLine();
				HelpMarker("How much ammo you restore. Not sure what to set it as, experiment.");
			}
		}
		ImGui::Separator();

		ImGui::Checkbox("Recoil Modifier", &Variables::RecoilModifier);
		ImGui::SameLine();
		HelpMarker("Modifys your weapon recoil.");
		if (Variables::RecoilModifier)
		{
			ImGui::SliderFloat("##RecoilValue", &Variables::RecoilValue, 0.0f, 1000000.0f, "Recoil Value: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 0 for no recoil.");
		}
		ImGui::Separator();

		ImGui::Checkbox("No Spread", &Variables::NoSpread);
		ImGui::SameLine();
		HelpMarker("Stops bullets spreading on guns like shotguns.");
		ImGui::Separator();

		ImGui::Checkbox("Range Modifier", &Variables::RangeModifier);
		ImGui::SameLine();
		HelpMarker("Modifys your weapon range.");
		if (Variables::RangeModifier)
		{
			ImGui::SliderFloat("##RangeValue", &Variables::RangeValue, 0.0f, 1000000.0f, "Range Value: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for infinite range.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Full Auto", &Variables::FullAuto);
		ImGui::SameLine();
		HelpMarker("Makes any gun fully automatic.");
		ImGui::Separator();

		ImGui::Checkbox("Zoom XRay", &Variables::ZoomXRay);
		ImGui::SameLine();
		HelpMarker("Gives you XRay vision when aiming down a scope.");
		ImGui::Separator();

		ImGui::Checkbox("Scope Speed", &Variables::ScopeModifier);
		ImGui::SameLine();
		HelpMarker("Modifys your weapons ADS speed.");
		if (Variables::ScopeModifier)
		{
			ImGui::SliderFloat("##ScopeValue", &Variables::ScopeValue, 0.0f, 1000000.0f, "Scope Value: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for instant ADS.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Force Criticals", &Variables::ForceCriticals);
		ImGui::SameLine();
		HelpMarker("Forces critical hits. Only visual?");
		ImGui::Separator();

		ImGui::Checkbox("Charge Modifier", &Variables::ChargeModifier);
		ImGui::SameLine();
		HelpMarker("Modifys your weapons charge time.");
		if (Variables::ChargeModifier)
		{
			ImGui::SliderFloat("##ChargeMax", &Variables::ChargeMax, 0.0f, 1000000.0f, "Charge Max: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 0 for instant max charge.");
			ImGui::SliderFloat("##ChargeDuration", &Variables::ChargeDuration, 0.0f, 1000000.0f, "Charge Duration: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 0 for instant charge.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Silent Aim", &Variables::AOEBullets);
		ImGui::SameLine();
		HelpMarker("Allows you to kill people from anywhere on the map without aiming at them (AOE Bullets).");
		if (Variables::AOEBullets)
		{
			ImGui::SliderFloat("##FrontAngle", &Variables::FrontAngle, 0.0f, 360.0f, "Front Angle: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 360 for highest range.");
			ImGui::SliderFloat("##BackAngle", &Variables::BackAngle, 0.0f, 360.0f, "Back Angle: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 360 for highest range.");
			ImGui::SliderFloat("##AOERadius", &Variables::AOERadius, 0.0f, 1000000.0f, "AOE Radius: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for biggest area of effect.");
			ImGui::SliderFloat("##FrontMultiplier", &Variables::FrontMultiplier, 0.0f, 1000000.0f, "Front Multiplier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
			ImGui::SliderFloat("##BackMultiplier", &Variables::BackMultiplier, 0.0f, 1000000.0f, "Back Multiplier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
			ImGui::SliderFloat("##SideMultiplier", &Variables::SideMultiplier, 0.0f, 1000000.0f, "Side Multiplier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Frost Aura", &Variables::FrostAura);
		ImGui::SameLine();
		HelpMarker("Gives you a damage aura.");
		if (Variables::FrostAura)
		{
			ImGui::SliderFloat("##AuraRadius", &Variables::AuraRadius, 0.0f, 1000000.0f, "Aura Radius: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for biggest area of effect.");
			ImGui::SliderFloat("##AuraMultiplier", &Variables::AuraMultiplier, 0.0f, 1000000.0f, "Aura Multiplier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Force Effects", &Variables::ForceEffects);
		ImGui::SameLine();
		HelpMarker("Gives your damage custom effects.");
		if (Variables::ForceEffects)
		{
			ImGui::Checkbox("Poison Effect", &Variables::PoisonEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the poison effect.");
			if (Variables::PoisonEffect)
			{
				ImGui::SliderFloat("##PoisonDuration", &Variables::PoisonDuration, 0.0f, 1000000.0f, "Poison Duration: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for longest duration.");
				ImGui::SliderFloat("##PoisonCount", &Variables::PoisonCount, 0.0f, 1000000.0f, "Poison Count: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for highest damage.");
				ImGui::SliderFloat("##PoisonMultiplier", &Variables::PoisonMultiplier, 0.0f, 1000000.0f, "Poison Multiplier: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
			}

			ImGui::Checkbox("Stun Effect", &Variables::StunEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the stun effect.");
			if (Variables::StunEffect)
			{
				ImGui::SliderFloat("##StunDuration", &Variables::StunDuration, 0.0f, 1000000.0f, "Stun Duration: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for longest duration.");
				ImGui::SliderFloat("##StunRadius", &Variables::StunRadius, 0.0f, 1000000.0f, "Stun Radius: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for highest area of effect.");
				ImGui::SliderFloat("##StunMultiplier", &Variables::StunMultiplier, 0.0f, 1000000.0f, "Stun Multiplier: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
			}

			ImGui::Checkbox("Curse Effect", &Variables::CurseEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the curse effect.");
			if (Variables::CurseEffect)
			{
				ImGui::SliderFloat("##CurseDuration", &Variables::CurseDuration, 0.0f, 1000000.0f, "Curse Duration: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for highest damage.");
				ImGui::SliderFloat("##CurseMultiplier", &Variables::CurseMultiplier, 0.0f, 1000000.0f, "Curse Multiplier: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage.");
			}

			ImGui::Checkbox("Charm Effect", &Variables::CharmEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the charm effect.");
			if (Variables::CharmEffect)
			{
				ImGui::SliderFloat("##CharmDuration", &Variables::CharmDuration, 0.0f, 1000000.0f, "Charm Duration: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for longest duration.");
			}

			ImGui::Checkbox("Blind Effect", &Variables::BlindEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the blind effect.");
			if (Variables::BlindEffect)
			{
				ImGui::SliderFloat("##BlindDuration", &Variables::BlindDuration, 0.0f, 1000000.0f, "Blind Duration: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for longest duration.");
			}

			ImGui::Checkbox("Weakness Effect", &Variables::WeaknessEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the weakness effect.");
			if (Variables::WeaknessEffect)
			{
				ImGui::SliderFloat("##WeaknessDuration", &Variables::WeaknessDuration, 0.0f, 1000000.0f, "Weakness Duration: %.1f");
				ImGui::SameLine();
				HelpMarker("I recommend keeping it set at 1000000 for longest duration.");
			}

			ImGui::Checkbox("Lightning Effect", &Variables::LightningEffect);
			ImGui::SameLine();
			HelpMarker("Gives your damage the lightning effect.");
		}
	}

	void Misc() {
		ImGui::Checkbox("Game Speed", &Variables::GameSpeed);
		ImGui::SameLine();
		HelpMarker("Speeds up your whole game including bullets, movement, loading etc.");
		if (Variables::GameSpeed)
		{
			ImGui::Text("Game Speed Key: %s", Utils::GetKeyNameFromVirtualKey(Variables::GameSpeedKey).c_str());
			ImGui::SliderFloat("##SpeedMultiplier", &Variables::GSpeedMultiplier, 0.0f, 100.0f, "Speed Multiplier: %.1f");
			ImGui::SameLine();
			HelpMarker("If you change the Speed Multiplier you must toggle Game Speed off and back on for it to update. Anything over 2 is likely to kick you or crash you.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Score Modifier", &Variables::ScoreModifier);
		ImGui::SameLine();
		HelpMarker("Modifys the score you get from a kill.");
		if (Variables::ScoreModifier)
		{
			ImGui::SliderFloat("##KillModifier", &Variables::KillModifier, 0.0f, 1000000.0f, "Kill Modifier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for highest score.");
			ImGui::SliderFloat("##AssistModifier", &Variables::AssistModifier, 0.0f, 1000000.0f, "Assist Modifier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for highest score.");
			ImGui::SliderFloat("##RevengeModifier", &Variables::RevengeModifier, 0.0f, 1000000.0f, "Revenge Modifier: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for highest score.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Polymorpher", &Variables::ForcePolymorpher);
		ImGui::SameLine();
		HelpMarker("Changes anyone you shoot to the type selected.");
		if (Variables::ForcePolymorpher)
		{
			ImGui::SliderFloat("##PolymorpherDuration", &Variables::PolymorpherDuration, 0.0f, 1000000.0f, "Polymorpher Duration: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 for longest time.");
			ImGui::SliderFloat("##PolymorpherHealth", &Variables::PolymorpherHealth, 0.0f, 1000000.0f, "Polymorpher Health: %.1f");
			ImGui::SameLine();
			HelpMarker("I recommend keeping it set at 1000000 so they can't die and become normal again.");
			ImGui::SliderFloat("##PolymorpherType", &Variables::PolymorpherType, 0, 3, "Polymorpher Type: %.0f");
			ImGui::SameLine();
			HelpMarker("Changes the entity you change people to. 0 - Sheep, 1 - Beetle, 2 - Mutant, 3 - Cube.");
		}
	}

	void Settings() {
		ImGui::Checkbox("ImGui Demo", &Variables::ImGuiDemo);
#ifdef _DEBUG
		ImGui::Separator();
		ImGui::Text("Developer Logs");
#endif
	}
}

void Drawing::Draw()
{
	if (isActive())
	{
		if (!ImGui::Begin(OBFUSCATE("@bosslawl"), 0, 96))
		{
			ImGui::End();
			return;
		}

		StyleInnit();
		ImGui::SetWindowSize(ImVec2(375, 400), ImGuiCond_Once);

		if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("Main"))
			{
				Tabs::Main();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Visuals"))
			{
				Tabs::Visuals();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Player"))
			{
				Tabs::Player();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Weapons"))
			{
				Tabs::Weapons();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Misc"))
			{
				Tabs::Misc();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Settings"))
			{
				Tabs::Settings();
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		ImGui::End();
	}

	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
}

void Drawing::Loops()
{
	if (Utils::KeyPressed(Variables::GameSpeedKey))
	{
		Variables::GameSpeed = !Variables::GameSpeed;
		if (Variables::GameSpeed)
			Internal::SetTimeScale(Variables::GSpeedMultiplier);
		else
			Internal::SetTimeScale(1.0f);
	}

	if (Variables::EnableCircleFov && Variables::EnableRainbowCircle)
		Utils::UseFov(true);
	else if (Variables::EnableCircleFov && !Variables::EnableRainbowCircle)
		Utils::UseFov(false);

	if (Variables::EnableCrosshair && Variables::EnableRainbowCrosshair)
		Utils::UseCrosshair(true);
	else if (Variables::EnableCrosshair && !Variables::EnableRainbowCrosshair)
		Utils::UseCrosshair(false);

	if (Variables::EnableWatermark && Variables::EnableFPS)
		Utils::Watermark(true, OBFUSCATE("@bosslawl"), Variables::WatermarkColor, ImVec4(255, 255, 255, 0));
	else if (Variables::EnableWatermark && !Variables::EnableFPS)
		Utils::Watermark(false, OBFUSCATE("@bosslawl"), Variables::WatermarkColor, ImVec4(255, 255, 255, 0));

	if (Variables::ImGuiDemo)
	{
		static bool ShowMeAGreatDemoWindow = true;
		ImGui::ShowDemoWindow(&ShowMeAGreatDemoWindow);
	}
}