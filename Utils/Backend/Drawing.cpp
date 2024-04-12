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
		ImGui::Text(OBFUSCATE("To use the menu your game must be windowed, you can fullscreen after."));
		ImGui::Text(OBFUSCATE("Leave all values default if you don't know what they do."));
		ImGui::Separator();
		ImGui::Text(OBFUSCATE("You can press Control and Click on a slider to edit it by typing."));
	}

	void Visuals() {
		if (ImGui::CollapsingHeader(OBFUSCATE("Visual")))
		{
			ImGui::Checkbox(OBFUSCATE("FOV Circle"), &Variables::EnableCircleFov);
			HelpMarker(OBFUSCATE("Displays a FOV Circle in the middle of the screen."));
			if (Variables::EnableCircleFov)
			{
				Utils::FSlider(OBFUSCATE("##CircleFOV"), &Variables::CircleFov, 0, 360, OBFUSCATE("Circle FOV: %.0f"));
				HelpMarker(OBFUSCATE("Changes the Circle size."));
				ImGui::ColorEdit3(OBFUSCATE("Circle Colour"), (float*)&Variables::CircleColour);
				HelpMarker(OBFUSCATE("Changes the Circle colour."));
				ImGui::Checkbox(OBFUSCATE("Rainbow?"), &Variables::EnableRainbowCircle);

				HelpMarker(OBFUSCATE("Makes the Circle rainbow, ignores the set Circle colour."));
			}

			ImGui::Checkbox(OBFUSCATE("Crosshair"), &Variables::EnableCrosshair);
			HelpMarker(OBFUSCATE("Displays a Crosshair in the middle of the screen."));
			if (Variables::EnableCrosshair)
			{
				Utils::FSlider(OBFUSCATE("##CrosshairSize"), &Variables::CrosshairSize, 1, 20, "Crosshair Size: %.0f");
				HelpMarker(OBFUSCATE("Changes the Crosshair size."));
				ImGui::ColorEdit3(OBFUSCATE("Crosshair Colour"), (float*)&Variables::CrosshairColor);
				HelpMarker(OBFUSCATE("Changes the Crosshair colour."));
				ImGui::Checkbox(OBFUSCATE("Rainbow?"), &Variables::EnableRainbowCrosshair);
				HelpMarker(OBFUSCATE("Makes the Crosshair rainbow, ignores the set Crosshair colour."));
			}

			ImGui::Checkbox(OBFUSCATE("Watermark"), &Variables::EnableWatermark);
			HelpMarker(OBFUSCATE("Draws a Watermark in the top left of the screen."));
			if (Variables::EnableWatermark)
			{
				ImGui::Checkbox(OBFUSCATE("Show FPS"), &Variables::EnableFPS);
				HelpMarker(OBFUSCATE("Displays FPS along side the watermark."));
			}
		}

		if (ImGui::CollapsingHeader(OBFUSCATE("Game")))
		{
			ImGui::Checkbox(OBFUSCATE("Chams"), &Variables::XRay);
			HelpMarker(OBFUSCATE("Makes all players visible through walls."));
		}
	}

	void Player() {
		if (ImGui::CollapsingHeader(OBFUSCATE("Movement")))
		{
			ImGui::Checkbox(OBFUSCATE("Speed Hack"), &Variables::PlayerSpeed);
			HelpMarker(OBFUSCATE("Speeds up your player."));
			if (Variables::PlayerSpeed)
			{
				Utils::FSlider(OBFUSCATE("##SpeedMultiplier"), &Variables::SpeedValue, 0.0f, 1000000.0f, OBFUSCATE("Speed Hack: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it at 1000. The Speed Multiplier caps out at some point around 1000."));
			}

			ImGui::Checkbox(OBFUSCATE("Jetpack Fly"), &Variables::JetpackFly);
			HelpMarker(OBFUSCATE("Hold space to fly. Only press it once, it will toggle itself off, to deactivate press it once again."));
		}

		if (ImGui::CollapsingHeader(OBFUSCATE("Immunities")))
		{
			ImGui::Checkbox(OBFUSCATE("Fire Immunity"), &Variables::FireImmunity);
			HelpMarker(OBFUSCATE("Makes you immune to the fire effect."));
			ImGui::Checkbox(OBFUSCATE("Toxic Immunity"), &Variables::ToxicImmunity);
			HelpMarker(OBFUSCATE("Makes you immune to the toxic effect."));
			ImGui::Checkbox(OBFUSCATE("Bleed Immunity"), &Variables::BleedImmunity);
			HelpMarker(OBFUSCATE("Makes you immune to the bleed effect."));
		}

		if (ImGui::CollapsingHeader(OBFUSCATE("Miscellaneous")))
		{
			ImGui::Checkbox(OBFUSCATE("Kill Aura"), &Variables::FrostAura);
			HelpMarker(OBFUSCATE("Gives you a damage aura."));
			if (Variables::FrostAura)
			{
				Utils::FSlider(OBFUSCATE("##AuraRadius"), &Variables::AuraRadius, 0.0f, 1000000.0f, OBFUSCATE("Aura Radius: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for biggest area of effect."));
				Utils::FSlider(OBFUSCATE("##AuraAngle)"), &Variables::AuraAngle, 0.0f, 360.0f, OBFUSCATE("Aura Angle: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for biggest area of effect."));
				Utils::FSlider(OBFUSCATE("##AuraMultiplier"), &Variables::AuraMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Aura Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}

			ImGui::Checkbox(OBFUSCATE("Invisibility"), &Variables::Invisibility);
			HelpMarker(OBFUSCATE("Makes you invisible after a kill or respawning."));
			if (Variables::Invisibility)
			{
				Utils::FSlider(OBFUSCATE("##InvisibilityDuration"), &Variables::SInvisibilityDuration, 0.0f, 1000000.0f, OBFUSCATE("Invisibility Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
			}

			ImGui::Checkbox(OBFUSCATE("Gadget Cooldown Modifier"), &Variables::GadgetCooldown);
			HelpMarker(OBFUSCATE("Makes your gadgets come back instantly."));
			if (Variables::GadgetCooldown)
			{
				Utils::FSlider(OBFUSCATE("##GadgetCooldown"), &Variables::CooldownValue, 0.0f, 1000000.0f, OBFUSCATE("Gadget Cooldown: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant cooldown."));
			}

			ImGui::Checkbox(OBFUSCATE("Godmode"), &Variables::Godmode);
			HelpMarker(OBFUSCATE("Stops you taking any damage."));
		}
	}

	void Weapons() {
		if (ImGui::CollapsingHeader(OBFUSCATE("Aim")))
		{
			ImGui::Checkbox(OBFUSCATE("AOE Bullets"), &Variables::AOEBullets);
			HelpMarker(OBFUSCATE("Allows you to kill people from anywhere on the map without aiming at them."));
			if (Variables::AOEBullets)
			{
				Utils::FSlider(OBFUSCATE("##FrontAngle"), &Variables::FrontAngle, 0.0f, 360.0f, OBFUSCATE("Front Angle: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for highest range."));
				Utils::FSlider(OBFUSCATE("##BackAngle"), &Variables::BackAngle, 0.0f, 360.0f, OBFUSCATE("Back Angle: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 360 for highest range."));
				Utils::FSlider(OBFUSCATE("##AOERadius"), &Variables::AOERadius, 0.0f, 1000000.0f, OBFUSCATE("AOE Radius: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for biggest area of effect."));
				Utils::FSlider(OBFUSCATE("##FrontMultiplier"), &Variables::FrontMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Front Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
				Utils::FSlider(OBFUSCATE("##BackMultiplier"), &Variables::BackMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Back Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
				Utils::FSlider(OBFUSCATE("##SideMultiplier"), &Variables::SideMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Side Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}
		}

		if (ImGui::CollapsingHeader(OBFUSCATE("Modifiers")))
		{
			ImGui::Checkbox(OBFUSCATE("Fire Rate Modifier"), &Variables::FireRate);
			HelpMarker(OBFUSCATE("Allows you to modify your shoot speed. Might kick you."));
			if (Variables::FireRate)
			{
				Utils::FSlider(OBFUSCATE("##FireRateValue"), &Variables::RapidValue, 0.0f, 1000000.0f, OBFUSCATE("Fire Rate: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for fastest fire rate."));
			}

			ImGui::Checkbox(OBFUSCATE("Reload Modifier"), &Variables::ReloadModifier);
			HelpMarker(OBFUSCATE("Allows you to modify your reload."));
			if (Variables::ReloadModifier)
			{
				Utils::FSlider(OBFUSCATE("##ReloadValue"), &Variables::ReloadValue, 0.0f, 99999.0f, OBFUSCATE("Reload Value: %.1f"));

				HelpMarker(OBFUSCATE("I recommend keeping it set at 99999 for no reload."));
			}

			ImGui::Checkbox(OBFUSCATE("Recoil Modifier"), &Variables::RecoilModifier);
			HelpMarker(OBFUSCATE("Modifys your weapon recoil."));
			if (Variables::RecoilModifier)
			{
				Utils::FSlider(OBFUSCATE("##RecoilValue"), &Variables::RecoilValue, 0.0f, 1000000.0f, OBFUSCATE("Recoil Value: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for no recoil."));
			}

			ImGui::Checkbox(OBFUSCATE("Range Modifier"), &Variables::RangeModifier);
			HelpMarker(OBFUSCATE("Modifys your weapon range."));
			if (Variables::RangeModifier)
			{
				Utils::FSlider(OBFUSCATE("##RangeValue"), &Variables::RangeValue, 0.0f, 1000000.0f, OBFUSCATE("Range Value: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for infinite range."));
			}

			ImGui::Checkbox(OBFUSCATE("Scope Speed Modifier"), &Variables::ScopeModifier);
			HelpMarker(OBFUSCATE("Modifys your weapons ADS speed."));
			if (Variables::ScopeModifier)
			{
				Utils::FSlider(OBFUSCATE("##ScopeValue"), &Variables::ScopeValue, 0.0f, 1000000.0f, OBFUSCATE("Scope Value: %.1f"));

				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for instant ADS."));
			}

			ImGui::Checkbox(OBFUSCATE("Charge Modifier"), &Variables::ChargeModifier);
			HelpMarker(OBFUSCATE("Modifys your weapons charge time."));
			if (Variables::ChargeModifier)
			{
				Utils::FSlider(OBFUSCATE("##ChargeMax"), &Variables::ChargeMax, 0.0f, 1000000.0f, OBFUSCATE("Charge Max: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant max charge."));
				Utils::FSlider(OBFUSCATE("##ChargeDuration"), &Variables::ChargeDuration, 0.0f, 1000000.0f, OBFUSCATE("Charge Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 0 for instant charge."));
			}

			ImGui::Checkbox(OBFUSCATE("No Spread"), &Variables::NoSpread);
			HelpMarker(OBFUSCATE("Stops bullets spreading on guns like shotguns."));

			ImGui::Checkbox(OBFUSCATE("Full Auto"), &Variables::FullAuto);
			HelpMarker(OBFUSCATE("Makes any gun fully automatic."));

			ImGui::Checkbox(OBFUSCATE("Infinite Ammo"), &Variables::InfiniteAmmo);
			HelpMarker(OBFUSCATE("Gives you unlimited ammo, still have to reload."));

			ImGui::Checkbox(OBFUSCATE("Zoom XRay"), &Variables::ZoomXRay);
			HelpMarker(OBFUSCATE("Gives you XRay vision when aiming down a scope."));

			ImGui::Checkbox(OBFUSCATE("Force Criticals"), &Variables::ForceCriticals);
			HelpMarker(OBFUSCATE("Forces critical hits. Only visual?"));
		}
		
		if (ImGui::CollapsingHeader(OBFUSCATE("Effects")))
		{
			ImGui::Checkbox(OBFUSCATE("Poison Effect"), &Variables::PoisonEffect);
			HelpMarker(OBFUSCATE("Gives your damage the poison effect."));
			if (Variables::PoisonEffect)
			{
				Utils::FSlider(OBFUSCATE("##PoisonDuration"), &Variables::PoisonDuration, 0.0f, 1000000.0f, OBFUSCATE("Poison Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
				Utils::FSlider(OBFUSCATE("##PoisonCount"), &Variables::PoisonCount, 0.0f, 1000000.0f, OBFUSCATE("Poison Count: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest damage."));
				Utils::FSlider(OBFUSCATE("##PoisonMultiplier"), &Variables::PoisonMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Poison Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}

			ImGui::Checkbox(OBFUSCATE("Stun Effect"), &Variables::StunEffect);
			HelpMarker(OBFUSCATE("Gives your damage the stun effect."));
			if (Variables::StunEffect)
			{
				Utils::FSlider(OBFUSCATE("##StunDuration"), &Variables::StunDuration, 0.0f, 1000000.0f, OBFUSCATE("Stun Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
				Utils::FSlider(OBFUSCATE("##StunRadius"), &Variables::StunRadius, 0.0f, 1000000.0f, OBFUSCATE("Stun Radius: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest area of effect."));
				Utils::FSlider(OBFUSCATE("##StunMultiplier"), &Variables::StunMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Stun Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}

			ImGui::Checkbox(OBFUSCATE("Curse Effect"), &Variables::CurseEffect);
			HelpMarker(OBFUSCATE("Gives your damage the curse effect."));
			if (Variables::CurseEffect)
			{
				Utils::FSlider(OBFUSCATE("##CurseDuration"), &Variables::CurseDuration, 0.0f, 1000000.0f, OBFUSCATE("Curse Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest damage."));
				Utils::FSlider(OBFUSCATE("##CurseMultiplier"), &Variables::CurseMultiplier, 0.0f, 1000000.0f, OBFUSCATE("Curse Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 5. Anything above around 7 will kick you for doing too much damage."));
			}

			ImGui::Checkbox(OBFUSCATE("Charm Effect"), &Variables::CharmEffect);
			HelpMarker(OBFUSCATE("Gives your damage the charm effect."));
			if (Variables::CharmEffect)
			{
				Utils::FSlider(OBFUSCATE("##CharmDuration"), &Variables::CharmDuration, 0.0f, 1000000.0f, OBFUSCATE("Charm Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
			}

			ImGui::Checkbox(OBFUSCATE("Blind Effect"), &Variables::BlindEffect);
			HelpMarker(OBFUSCATE("Gives your damage the blind effect."));
			if (Variables::BlindEffect)
			{
				Utils::FSlider(OBFUSCATE("##BlindDuration"), &Variables::BlindDuration, 0.0f, 1000000.0f, OBFUSCATE("Blind Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
			}

			ImGui::Checkbox(OBFUSCATE("Weakness Effect"), &Variables::WeaknessEffect);
			HelpMarker(OBFUSCATE("Gives your damage the weakness effect."));
			if (Variables::WeaknessEffect)
			{
				Utils::FSlider(OBFUSCATE("##WeaknessDuration"), &Variables::WeaknessDuration, 0.0f, 1000000.0f, OBFUSCATE("Weakness Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest duration."));
			}

			ImGui::Checkbox(OBFUSCATE("Lightning Effect"), &Variables::LightningEffect);
			HelpMarker(OBFUSCATE("Gives your damage the lightning effect."));
		}

		if (ImGui::CollapsingHeader(OBFUSCATE("Miscellaneous")))
		{
			ImGui::Checkbox(OBFUSCATE("Polymorpher"), &Variables::ForcePolymorpher);
			HelpMarker(OBFUSCATE("Changes anyone you shoot to the type selected."));
			if (Variables::ForcePolymorpher)
			{
				Utils::FSlider(OBFUSCATE("##PolymorpherDuration"), &Variables::PolymorpherDuration, 0.0f, 1000000.0f, OBFUSCATE("Polymorpher Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
				Utils::FSlider(OBFUSCATE("##PolymorpherHealth"), &Variables::PolymorpherHealth, 0.0f, 1000000.0f, OBFUSCATE("Polymorpher Health: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 so they can't die and become normal again."));

				const char* items[] = { "Sheep", "Beetle", "Mutant", "Cube" };
				const int numItems = sizeof(items) / sizeof(items[0]);

				if (ImGui::BeginCombo("Select Type", items[Variables::PolymorpherType])) {
					for (int i = 0; i < numItems; ++i) {
						bool isSelected = (Variables::PolymorpherType == i);
						if (ImGui::Selectable(items[i], isSelected))
							Variables::PolymorpherType = i;

						if (isSelected)
							ImGui::SetItemDefaultFocus();
					}
					ImGui::EndCombo();
				}
				HelpMarker(OBFUSCATE("Sets the entity you turn people into when you shoot them."));
			}

			ImGui::Checkbox(OBFUSCATE("Head Magnifier"), &Variables::HeadMagnifier);
			HelpMarker(OBFUSCATE("Enlarges anyone you shoots head."));
			if (Variables::HeadMagnifier)
			{
				Utils::FSlider(OBFUSCATE("##MagnifierDuration"), &Variables::MagnifierDuration, 0.0f, 1000000.0f, OBFUSCATE("Magnifier Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
			}

			ImGui::Checkbox(OBFUSCATE("Jump Disabler"), &Variables::JumpDisabler);
			HelpMarker(OBFUSCATE("Disables the jump of anyone who you shoot."));
			if (Variables::JumpDisabler)
			{
				Utils::FSlider(OBFUSCATE("##DisabledDuration"), &Variables::JDisabledDuration, 0.0f, 1000000.0f, OBFUSCATE("Disabled Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
			}

			ImGui::Checkbox(OBFUSCATE("Reflection Rays"), &Variables::ReflectionRays);
			HelpMarker(OBFUSCATE("Makes a your screen a disco."));
			if (Variables::ReflectionRays)
			{
				Utils::FSlider(OBFUSCATE("##ReflectionCount"), &Variables::ReflectionCount, 0.0f, 1000000.0f, OBFUSCATE("Reflection Count: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 50 the most amount of reflections, without freezing your game."));
			}
		}
	}

	void Pet() {
		ImGui::Checkbox(OBFUSCATE("Pet Health"), &Variables::PetHealth);
		HelpMarker(OBFUSCATE("Changes your pets health."));
		if (Variables::PetHealth)
		{
			Utils::FSlider(OBFUSCATE("##PetHealth"), &Variables::PetHealthValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Health: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible health."));
		}

		ImGui::Checkbox(OBFUSCATE("Pet Damage"), &Variables::PetDamage);
		HelpMarker(OBFUSCATE("Changes your pets damage."));
		if (Variables::PetDamage)
		{
			Utils::FSlider(OBFUSCATE("##PetDamage"), &Variables::PetDamageValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Damage: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible damage."));
		}

		ImGui::Checkbox(OBFUSCATE("Pet Speed"), &Variables::PetSpeed);
		HelpMarker(OBFUSCATE("Changes your pets speed."));
		if (Variables::PetSpeed)
		{
			Utils::FSlider(OBFUSCATE("##PetSpeed"), &Variables::PetSpeedValue, 0.0f, 1000000.0f, OBFUSCATE("Pet Speed: %.1f"));
			HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highst possible speed."));
		}
	}

	void Exploits() {
		if (ImGui::CollapsingHeader(OBFUSCATE("Game")))
		{
			ImGui::Checkbox(OBFUSCATE("Match Invisibility"), &Variables::MatchInvisibility);
			HelpMarker(OBFUSCATE("Makes everyone invisible."));
			if (Variables::MatchInvisibility)
			{
				Utils::FSlider(OBFUSCATE("##InvisibilityDuration"), &Variables::MInvisibilityDuration, 0.0f, 1000000.0f, OBFUSCATE("Invisibility Duration: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for longest time."));
			}

			ImGui::Checkbox(OBFUSCATE("Game Speed"), &Variables::GameSpeed);
			HelpMarker(OBFUSCATE("Speeds up your whole game including bullets, movement, loading etc."));
			if (Variables::GameSpeed)
			{
				ImGui::Text(OBFUSCATE("Game Speed Key: %s"), Utils::GetKeyNameFromVirtualKey(Variables::GameSpeedKey).c_str());
				Utils::FSlider(OBFUSCATE("##SpeedMultiplier"), &Variables::GSpeedMultiplier, 0.0f, 100.0f, OBFUSCATE("Speed Multiplier: %.1f"));
				HelpMarker(OBFUSCATE("If you change the Speed Multiplier you must toggle Game Speed off and back on for it to update. Anything over 2 is likely to kick you or crash you."));
			}

			ImGui::Checkbox(OBFUSCATE("Score Modifier"), &Variables::ScoreModifier);
			HelpMarker(OBFUSCATE("Modifys the score you get from a kill."));
			if (Variables::ScoreModifier)
			{
				Utils::FSlider(OBFUSCATE("##KillModifier"), &Variables::KillModifier, 0.0f, 1000000.0f, OBFUSCATE("Kill Modifier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
				Utils::FSlider(OBFUSCATE("##AssistModifier"), &Variables::AssistModifier, 0.0f, 1000000.0f, OBFUSCATE("Assist Modifier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
				Utils::FSlider(OBFUSCATE("##RevengeModifier"), &Variables::RevengeModifier, 0.0f, 1000000.0f, OBFUSCATE("Revenge Modifier: %.1f"));
				HelpMarker(OBFUSCATE("I recommend keeping it set at 1000000 for highest score."));
			}
		}

		if (ImGui::CollapsingHeader(OBFUSCATE("Account")))
		{
			ImGui::Checkbox(OBFUSCATE("Infinite Gems"), &Variables::InfiniteGems);
			HelpMarker(OBFUSCATE("Go into the armoury then double click any weapon and go to gallery, once enabled spam on any of the locked weapons."));

			ImGui::Checkbox(OBFUSCATE("Lottery"), &Variables::Lottery);
			HelpMarker(OBFUSCATE("Makes lottery boxes free."));

			ImGui::Checkbox(OBFUSCATE("Max Level"), &Variables::MaxLevel);
			HelpMarker(OBFUSCATE("Gives you max level. Click 1 and Click 2 when it says."));
			if (Variables::MaxLevel)
			{
				ImGui::Checkbox(OBFUSCATE("Max Level 1"), &Variables::MaxLevelOne);
				HelpMarker(OBFUSCATE("Tick this and spin the chest then untick when the chest is spinning."));
				ImGui::Checkbox(OBFUSCATE("Max Level 2"), &Variables::MaxLevelTwo);
				HelpMarker(OBFUSCATE("Tick this and spin the chest then untick when the chest is spinning, repeat until you get all the rewards, normally twice."));
			}
		}
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