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
		ImGui::Checkbox(OBFUSCATE("FOV Circle"), &Variables::EnableCircleFov);
		HelpMarker(OBFUSCATE("Displays a FOV Circle in the middle of the screen."));
		if (Variables::EnableCircleFov)
		{
			ImGui::SliderFloat(OBFUSCATE("##CircleFOV"), &Variables::CircleFov, 0, 360, OBFUSCATE("Circle FOV: %.0f"));
			HelpMarker(OBFUSCATE("Changes the Circle size."));
			ImGui::ColorEdit3(OBFUSCATE("Circle Colour"), (float*)&Variables::CircleColour);
			HelpMarker(OBFUSCATE("Changes the Circle colour."));
			ImGui::Checkbox(OBFUSCATE("Rainbow?"), &Variables::EnableRainbowCircle);
	
			HelpMarker(OBFUSCATE("Makes the Circle rainbow, ignores the set Circle colour."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Crosshair"), &Variables::EnableCrosshair);
		HelpMarker(OBFUSCATE("Displays a Crosshair in the middle of the screen."));
		if (Variables::EnableCrosshair)
		{
			ImGui::SliderFloat(OBFUSCATE("##CrosshairSize"), &Variables::CrosshairSize, 1, 20, "Crosshair Size: %.0f");
			HelpMarker(OBFUSCATE("Changes the Crosshair size."));
			ImGui::ColorEdit3(OBFUSCATE("Crosshair Colour"), (float*)&Variables::CrosshairColor);
			HelpMarker(OBFUSCATE("Changes the Crosshair colour."));
			ImGui::Checkbox(OBFUSCATE("Rainbow?"), &Variables::EnableRainbowCrosshair);
			HelpMarker(OBFUSCATE("Makes the Crosshair rainbow, ignores the set Crosshair colour."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Watermark"), &Variables::EnableWatermark);

		HelpMarker(OBFUSCATE("Draws a Watermark in the top left of the screen."));
		if (Variables::EnableWatermark)
		{
			ImGui::Checkbox(OBFUSCATE("Show FPS"), &Variables::EnableFPS);
			HelpMarker(OBFUSCATE("Displays FPS along side the watermark."));
		}
		ImGui::Separator();
		ImGui::Checkbox(OBFUSCATE("Chams"), &Variables::XRay);
		HelpMarker(OBFUSCATE("Makes all players visible through walls."));
	}

	void Player() {
		ImGui::Checkbox(OBFUSCATE("Speed Hack"), &Variables::PlayerSpeed);
		HelpMarker(OBFUSCATE("Speeds up your player."));
		if (Variables::PlayerSpeed)
		{
			ImGui::SliderFloat(OBFUSCATE("##SpeedMultiplier"), &Variables::SpeedValue, 0.0f, 1000000.0f, OBFUSCATE("Speed Hack: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it at 1000. The Speed Multiplier caps out at some point around 1000."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Jetpack Fly"), &Variables::JetpackFly);
		HelpMarker(OBFUSCATE("Hold space to fly. Only press it once, it will toggle itself off, to deactivate press it once again."));
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Godmode"), &Variables::Godmode);
		HelpMarker(OBFUSCATE("Stops you taking any damage."));
	}

	void Weapons() {
		ImGui::Checkbox(OBFUSCATE("Infinite Ammo"), &Variables::InfiniteAmmo);
		HelpMarker(OBFUSCATE("Gives you unlimited ammo, still have to reload."));
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("No Reload"), &Variables::ReloadModifier);
		HelpMarker(OBFUSCATE("Makes you not have to reload your weapons."));
		if (Variables::ReloadModifier)
		{
			ImGui::SliderFloat(OBFUSCATE("##ReloadValue"), &Variables::ReloadValue, 0.0f, 99999.0f, OBFUSCATE("Reload Value: %.1f"));
	
			HelpMarker(OBFUSCATE("I recommend keeping it set at 99999 for no reload."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Recoil Modifier"), &Variables::RecoilModifier);
		HelpMarker(OBFUSCATE("Modifys your weapon recoil."));
		if (Variables::RecoilModifier)
		{
			ImGui::SliderFloat(OBFUSCATE("##RecoilValue"), &Variables::RecoilValue, 0.0f, 1000000.0f, OBFUSCATE("Recoil Value: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for no recoil."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("No Spread"), &Variables::NoSpread);
		HelpMarker(OBFUSCATE("Stops bullets spreading on guns like shotguns."));
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Range Modifier"), &Variables::RangeModifier);
		HelpMarker(OBFUSCATE("Modifys your weapon range."));
		if (Variables::RangeModifier)
		{
			ImGui::SliderFloat(OBFUSCATE("##RangeValue"), &Variables::RangeValue, 0.0f, 1000000.0f, OBFUSCATE("Range Value: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for infinite range."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Full Auto"), &Variables::FullAuto);
		HelpMarker(OBFUSCATE("Makes any gun fully automatic."));
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Zoom XRay"), &Variables::ZoomXRay);
		HelpMarker(OBFUSCATE("Gives you XRay vision when aiming down a scope."));
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Scope Speed"), &Variables::ScopeModifier);
		HelpMarker(OBFUSCATE("Modifys your weapons ADS speed."));
		if (Variables::ScopeModifier)
		{
			ImGui::SliderFloat(OBFUSCATE("##ScopeValue"), &Variables::ScopeValue, 0.0f, 1000000.0f, OBFUSCATE("Scope Value: %.1f"));
	
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for instant ADS."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Force Criticals"), &Variables::ForceCriticals);
		HelpMarker(OBFUSCATE("Forces critical hits. Only visual?"));
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Charge Modifier"), &Variables::ChargeModifier);
		HelpMarker(OBFUSCATE("Modifys your weapons charge time."));
		if (Variables::ChargeModifier)
		{
			ImGui::SliderFloat(OBFUSCATE("##ChargeMax"), &Variables::ChargeMax, 0.0f, 1000000.0f, OBFUSCATE("Charge Max: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant max charge."));
			ImGui::SliderFloat(OBFUSCATE("##ChargeDuration"), &Variables::ChargeDuration, 0.0f, 1000000.0f, OBFUSCATE("Charge Duration: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant charge."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Silent Aim"), &Variables::AOEBullets);
		HelpMarker(OBFUSCATE("Allows you to kill people from anywhere on the map without aiming at them (AOE Bullets)."));
		if (Variables::AOEBullets)
		{
			ImGui::SliderFloat(OBFUSCATE("##FrontAngle"), &Variables::FrontAngle, 0.0f, 360.0f, OBFUSCATE("Front Angle: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for highest range."));
			ImGui::SliderFloat(OBFUSCATE("##BackAngle"), &Variables::BackAngle, 0.0f, 360.0f, OBFUSCATE("Back Angle: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for highest range."));
			ImGui::SliderFloat(OBFUSCATE("##AOERadius"), &Variables::AOERadius, 0.0f, 1000000.0f, OBFUSCATE("AOE Radius: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for biggest area of effect."));
			ImGui::SliderFloat(OBFUSCATE("##FrontMultiplier"), &Variables::FrontMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Front Multiplier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			ImGui::SliderFloat(OBFUSCATE("##BackMultiplier"), &Variables::BackMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Back Multiplier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			ImGui::SliderFloat(OBFUSCATE("##SideMultiplier"), &Variables::SideMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Side Multiplier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Force Effects"), &Variables::ForceEffects);
		HelpMarker(OBFUSCATE("Gives your damage custom effects."));
		if (Variables::ForceEffects)
		{
			ImGui::Checkbox(OBFUSCATE("Poison Effect"), &Variables::PoisonEffect);
			HelpMarker(OBFUSCATE("Gives your damage the poison effect."));
			if (Variables::PoisonEffect)
			{
				ImGui::SliderFloat(OBFUSCATE("##PoisonDuration"), &Variables::PoisonDuration, 0.0f, 1000000.0f, OBFUSCATE("Poison Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
				ImGui::SliderFloat(OBFUSCATE("##PoisonCount"), &Variables::PoisonCount, 0.0f, 1000000.0f, OBFUSCATE("Poison Count: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest damage."));
				ImGui::SliderFloat(OBFUSCATE("##PoisonMultiplier"), &Variables::PoisonMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Poison Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}

			ImGui::Checkbox(OBFUSCATE("Stun Effect"), &Variables::StunEffect);
	
			HelpMarker(OBFUSCATE("Gives your damage the stun effect."));
			if (Variables::StunEffect)
			{
				ImGui::SliderFloat(OBFUSCATE("##StunDuration"), &Variables::StunDuration, 0.0f, 1000000.0f, OBFUSCATE("Stun Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
				ImGui::SliderFloat(OBFUSCATE("##StunRadius"), &Variables::StunRadius, 0.0f, 1000000.0f, OBFUSCATE("Stun Radius: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest area of effect."));
				ImGui::SliderFloat(OBFUSCATE("##StunMultiplier"), &Variables::StunMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Stun Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}

			ImGui::Checkbox(OBFUSCATE("Curse Effect"), &Variables::CurseEffect);
			HelpMarker(OBFUSCATE("Gives your damage the curse effect."));
			if (Variables::CurseEffect)
			{
				ImGui::SliderFloat(OBFUSCATE("##CurseDuration"), &Variables::CurseDuration, 0.0f, 1000000.0f, OBFUSCATE("Curse Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest damage."));
				ImGui::SliderFloat(OBFUSCATE("##CurseMultiplier"), &Variables::CurseMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Curse Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}
			ImGui::Checkbox(OBFUSCATE("Charm Effect"), &Variables::CharmEffect);
			HelpMarker(OBFUSCATE("Gives your damage the charm effect."));
			if (Variables::CharmEffect)
			{
				ImGui::SliderFloat(OBFUSCATE("##CharmDuration"), &Variables::CharmDuration, 0.0f, 1000000.0f, OBFUSCATE("Charm Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
			}

			ImGui::Checkbox(OBFUSCATE("Blind Effect"), &Variables::BlindEffect);
			HelpMarker(OBFUSCATE("Gives your damage the blind effect."));
			if (Variables::BlindEffect)
			{
				ImGui::SliderFloat(OBFUSCATE("##BlindDuration"), &Variables::BlindDuration, 0.0f, 1000000.0f, OBFUSCATE("Blind Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
			}
			ImGui::Checkbox(OBFUSCATE("Weakness Effect"), &Variables::WeaknessEffect);
			HelpMarker(OBFUSCATE("Gives your damage the weakness effect."));
			if (Variables::WeaknessEffect)
			{
				ImGui::SliderFloat(OBFUSCATE("##WeaknessDuration"), &Variables::WeaknessDuration, 0.0f, 1000000.0f, OBFUSCATE("Weakness Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
			}
			ImGui::Checkbox(OBFUSCATE("Lightning Effect"), &Variables::LightningEffect);
			HelpMarker(OBFUSCATE("Gives your damage the lightning effect."));
		}
	}

	void Pet() {
		ImGui::Checkbox(OBFUSCATE("Pet Health"), &Variables::PetHealth);
		HelpMarker(OBFUSCATE("Changes your pets health."));
		if (Variables::PetDamage)
		{
			ImGui::SliderFloat(OBFUSCATE("##PetHealth"), &Variables::PetHealthValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Health: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible health."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Pet Damage"), &Variables::PetDamage);
		HelpMarker(OBFUSCATE("Changes your pets damage."));
		if (Variables::PetDamage)
		{
			ImGui::SliderFloat(OBFUSCATE("##PetDamage"), &Variables::PetDamageValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Damage: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible damage."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Pet Speed"), &Variables::PetSpeed);
		HelpMarker(OBFUSCATE("Changes your pets speed."));
		if (Variables::PetSpeed)
		{
			ImGui::SliderFloat(OBFUSCATE("##PetSpeed"), &Variables::PetSpeedValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Speed: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible speed."));
		}
	}

	void Misc() {
		ImGui::Checkbox(OBFUSCATE("Game Speed"), &Variables::GameSpeed);
		HelpMarker(OBFUSCATE("Speeds up your whole game including bullets, movement, loading etc."));
		if (Variables::GameSpeed)
		{
			ImGui::Text(OBFUSCATE("Game Speed Key: %s"), Utils::GetKeyNameFromVirtualKey(Variables::GameSpeedKey).c_str());
			ImGui::SliderFloat(OBFUSCATE("##SpeedMultiplier"), &Variables::GSpeedMultiplier, 0.0f, 100.0f, OBFUSCATE("Speed Multiplier: %.1f"));
			HelpMarker(OBFUSCATE("If you change the Speed Multiplier you must toggle Game Speed off and back on for it to update. Anything over 2 is likely to kick you or crash you."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Invisibility"), &Variables::Invisibility);
		HelpMarker(OBFUSCATE("Makes everyone invisible."));
		ImGui::Separator();
		ImGui::Checkbox(OBFUSCATE("Score Modifier"), &Variables::ScoreModifier);
		HelpMarker(OBFUSCATE("Modifys the score you get from a kill."));
		if (Variables::ScoreModifier)
		{
			ImGui::SliderFloat(OBFUSCATE("##KillModifier"), &Variables::KillModifier, 0.0f, 1000000.0f, OBFUSCATE("Kill Modifier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
			ImGui::SliderFloat(OBFUSCATE("##AssistModifier"), &Variables::AssistModifier, 0.0f, 1000000.0f, OBFUSCATE("Assist Modifier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
			ImGui::SliderFloat(OBFUSCATE("##RevengeModifier"), &Variables::RevengeModifier, 0.0f, 1000000.0f, OBFUSCATE("Revenge Modifier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Kill Aura"), &Variables::FrostAura);
		HelpMarker(OBFUSCATE("Gives you a damage aura."));
		if (Variables::FrostAura)
		{
			ImGui::SliderFloat(OBFUSCATE("##AuraRadius"), &Variables::AuraRadius, 0.0f, 1000000.0f, OBFUSCATE("Aura Radius: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for biggest area of effect."));
			ImGui::SliderFloat(OBFUSCATE("##AuraAngle)"), &Variables::AuraAngle, 0.0f, 360.0f, OBFUSCATE("Aura Angle: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for biggest area of effect."));
			ImGui::SliderFloat(OBFUSCATE("##AuraMultiplier"), &Variables::AuraMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Aura Multiplier: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Polymorpher"), &Variables::ForcePolymorpher);
		HelpMarker(OBFUSCATE("Changes anyone you shoot to the type selected."));
		if (Variables::ForcePolymorpher)
		{
			ImGui::SliderFloat(OBFUSCATE("##PolymorpherDuration"), &Variables::PolymorpherDuration, 0.0f, 1000000.0f, OBFUSCATE("Polymorpher Duration: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
			ImGui::SliderFloat(OBFUSCATE("##PolymorpherHealth"), &Variables::PolymorpherHealth, 0.0f, 1000000.0f, OBFUSCATE("Polymorpher Health: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 so they can't die and become normal again."));
			ImGui::SliderFloat(OBFUSCATE("##PolymorpherType"), &Variables::PolymorpherType, 0, 3, OBFUSCATE("Polymorpher Type: %.0f"));
			HelpMarker(OBFUSCATE("Changes the entity you change people to. 0 - Sheep, 1 - Beetle, 2 - Mutant, 3 - Cube."));
		}
		ImGui::Separator();

		ImGui::Checkbox(OBFUSCATE("Gadget Cooldown"), &Variables::GadgetCooldown);
		HelpMarker(OBFUSCATE("Makes your gadgets come back instantly."));
	}

	void Exploits() {
		ImGui::Checkbox(OBFUSCATE("Infinite Gems"), &Variables::InfiniteGems);
		HelpMarker(OBFUSCATE("Go into the armoury then double click any weapon and go to gallery, once enabled spam on any of the locked weapons."));
	}

	void Settings() {
		ImGui::Checkbox(OBFUSCATE("ImGui Demo"), &Variables::ImGuiDemo);
#ifdef _DEBUG
		ImGui::Separator();
		ImGui::Text(OBFUSCATE("Developer Logs"));
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
		ImGui::SetWindowSize(ImVec2(500, 500), ImGuiCond_Once);

		float spacing = (500 - ImGui::GetContentRegionAvailWidth()) / 2;

		ImGui::Dummy(ImVec2(spacing, 0));
		if (ImGui::BeginTabBar(OBFUSCATE("##tabs"), ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem(OBFUSCATE("Main")))
			{
				Tabs::Main();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Visuals")))
			{
				Tabs::Visuals();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Player")))
			{
				Tabs::Player();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Pet")))
			{
				Tabs::Pet();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Weapons")))
			{
				Tabs::Weapons();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Misc")))
			{
				Tabs::Misc();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Exploits")))
			{
				Tabs::Exploits();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(OBFUSCATE("Settings")))
			{
				Tabs::Settings();
				ImGui::EndTabItem();
			}
			ImGui::Dummy(ImVec2(spacing, 0));
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