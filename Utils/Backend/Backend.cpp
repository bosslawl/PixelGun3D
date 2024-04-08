#include "../Backend/Backend.h"
#include "../../Cheat/Functions/Functions.h"

Backend::presentVariable originalPresent;
Backend::presentVariable hookedPresent;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static bool init = false;

Backend RunBackend;
WNDPROC oWndProc;
static FILE* f;

void HelpMarker(const char* desc)
{
	ImGui::TextDisabled("[?]");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void StyleInnit()
{
	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	//style.WindowPadding = ImVec2(8.00f, 8.00f);
	//style.FramePadding = ImVec2(5.00f, 2.00f);
	//style.CellPadding = ImVec2(6.00f, 6.00f);
	//style.ItemSpacing = ImVec2(6.00f, 6.00f);
	//style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	//style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	//style.FrameBorderSize = 1;
	style.WindowRounding = 4;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
}

bool Backend::DirectXPresentHook()
{
	ZeroMemory(&m_gSwapChainDescription, sizeof(m_gSwapChainDescription));

	m_gSwapChainDescription.BufferCount = 2;
	m_gSwapChainDescription.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	m_gSwapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	m_gSwapChainDescription.OutputWindow = GetForegroundWindow();
	m_gSwapChainDescription.SampleDesc.Count = 1;
	m_gSwapChainDescription.Windowed = TRUE;
	m_gSwapChainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	HRESULT createDevice = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, m_gFeatureLevels, 2, D3D11_SDK_VERSION, &m_gSwapChainDescription, &m_gSwapChain, &m_gDevice, nullptr, nullptr);

	if (FAILED(createDevice))
		return false; // dont return false make an endless cycle (only if u wanna go cpu boom) 

	void** DX11Vtable = *reinterpret_cast<void***>(m_gSwapChain);

	UnloadDevices(false); // don't need to reset mainrendertargetview
	hookedPresent = (Backend::presentVariable)DX11Vtable[8]; // 8. virtual table is present

	return true;
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (RunBackend.m_bOpenMenu && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) // if menu open then handle imgui events
		return true;

	return CallWindowProc(RunBackend.m_goriginalWndProc, hWnd, uMsg, wParam, lParam);
}

void Backend::LoadImGui(HWND window, ID3D11Device* device, ID3D11DeviceContext* context)
{
	ImGui::CreateContext(); // creating the context cus we need imgui
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange; // dont change cursors
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, context); // u need the device's context since u can't draw with only device, thanx dx11
} // loading the imgui

namespace Tabs {
	void Main() {
		ImGui::Text("Press INSERT to toggle the menu");
		ImGui::Text("Press END to close the cheat");
		ImGui::Separator();
		ImGui::Text("Leave all values default if you don't know what they do.");
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
		HelpMarker("Hold space to fly. I wouldn't recommend enabling this and infinite jump at the same time.");
		ImGui::Separator();

		ImGui::Checkbox("Invisibility", &Variables::Invisibility);
		ImGui::SameLine();
		HelpMarker("Makes you invisible.");
		if (Variables::Invisibility)
		{
			ImGui::Checkbox("InvisibilityRPC", &Variables::MatchInvisibility);
			ImGui::SameLine();
			HelpMarker("Makes all players invisible. Might kick you.");
		}
		ImGui::Separator();

		ImGui::Checkbox("Heal", &Variables::HealOnline);
		ImGui::SameLine();
		HelpMarker("Heals you. Might kick you. Possibly detected in future updates.");
		ImGui::Separator();
	}

	void Weapons() {
		ImGui::Checkbox("Infinite Ammo", &Variables::InfiniteAmmo);
		ImGui::SameLine();
		HelpMarker("Gives you unlimited ammo, still have to reload.");
		if (Variables::InfiniteAmmo)
		{
			ImGui::Checkbox("InfiniteAmmoRPC", &Variables::AmmoOnline);
			ImGui::SameLine();
			HelpMarker("Stops your weapon using any ammo, no reloading required. Possibly detected in future updates.");
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

		ImGui::Checkbox("No Spread", &Variables::NoSpread);
		ImGui::SameLine();
		HelpMarker("Stops bullets spreading on guns like shotguns.");
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
		ImGui::Separator();
	}

	void Misc() {
		ImGui::Checkbox("Game Speed", &Variables::GameSpeed);
		ImGui::SameLine();
		HelpMarker("Speeds up your whole game including bullets, movement, loading etc.");
		if (Variables::GameSpeed)
		{
			ImGui::Text("Game Speed Key: %s", Utils::GetKeyNameFromVirtualKey(Variables::GameSpeedKey).c_str());
			ImGui::SliderFloat("##SpeedMultiplier", &Variables::GSpeedMultiplier, 0.0f, 1000000.0f, "Speed Multiplier: %.1f");
			ImGui::SameLine();
			HelpMarker("If you change the Speed Multiplier you must toggle Game Speed off and back on for it to update. Anything over 2 is likely to kick you or crash you.");
		}
	}

	void Settings() {
		ImGui::Button("Close Cheat", ImVec2(ImGui::GetWindowWidth() - 20, 0));
		if (ImGui::IsItemClicked()) {
			RunHooks.Unload(f);;
			RunBackend.Unload();
		}

#ifdef _DEBUG
		ImGui::Seperator();
		ImGui::Text("Developer Logs");
#endif
	}
}

void Backend::DrawImGui(ID3D11DeviceContext* context, ID3D11RenderTargetView* targetview)
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (m_bOpenMenu)
	{
		if (!ImGui::Begin("@bosslawl", 0, 96))
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

	RunBackend.RenderCheat();
	ImGui::EndFrame();
	ImGui::Render();
	context->OMSetRenderTargets(1, &targetview, NULL);  // 1 render target, render it to our monitor, no dsv
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData()); // drawing the imgui menu
}

void Backend::UnloadImGui()
{
	MH_DisableHook(hookedPresent);
	MH_RemoveHook(hookedPresent);
	MH_Uninitialize();

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void Backend::UnloadDevices(bool renderTargetViewReset)
{
	if (renderTargetViewReset) if (m_gMainRenderTargetView) { m_gMainRenderTargetView->Release(); m_gMainRenderTargetView = nullptr; }
	if (m_gPointerContext) { m_gPointerContext->Release(); m_gPointerContext = nullptr; }
	if (m_gDevice) { m_gDevice->Release(); m_gDevice = nullptr; }
	SetWindowLongPtr(m_gWindow, GWLP_WNDPROC, (LONG_PTR)(m_goriginalWndProc));
}

void Backend::RenderCheat()
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
		Utils::Watermark(true, "@bosslawl", Variables::WatermarkColor, ImVec4(255, 255, 255, 0));
	else if (Variables::EnableWatermark && !Variables::EnableFPS)
		Utils::Watermark(false, "@bosslawl", Variables::WatermarkColor, ImVec4(255, 255, 255, 0));
}

static long __stdcall PresentHook(IDXGISwapChain* pointerSwapChain, UINT sync, UINT flags)
{
	if (!init) {
		if (SUCCEEDED(pointerSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&RunBackend.m_gDevice))) // check if device working 
		{
			RunBackend.m_gDevice->GetImmediateContext(&RunBackend.m_gPointerContext); // need context immediately!!
			pointerSwapChain->GetDesc(&RunBackend.m_gPresentHookSwapChain); // welp we need the presenthook's outputwindow so it's actually ours o_o
			RunBackend.m_gWindow = RunBackend.m_gPresentHookSwapChain.OutputWindow;

			pointerSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&RunBackend.m_gPointerBackBuffer); // getting back buffer
			if (RunBackend.m_gPointerBackBuffer != nullptr) RunBackend.m_gDevice->CreateRenderTargetView(RunBackend.m_gPointerBackBuffer, NULL, &RunBackend.m_gMainRenderTargetView); // from backbuffer to our monitor
			RunBackend.m_gPointerBackBuffer->Release(); // don't need this shit anymore, but please comeback the next injection

			RunBackend.LoadImGui(RunBackend.m_gWindow, RunBackend.m_gDevice, RunBackend.m_gPointerContext); // load imgui!!!
			RunBackend.m_goriginalWndProc = (WNDPROC)SetWindowLongPtr(RunBackend.m_gWindow, GWLP_WNDPROC, (LONG_PTR)WndProc); // i think u need this

			RunBackend.m_gPointerContext->RSGetViewports(&RunBackend.m_gVps, &RunBackend.m_gViewport);
			Variables::ScreenSize = { RunBackend.m_gViewport.Width, RunBackend.m_gViewport.Height };
			Variables::ScreenCenter = { RunBackend.m_gViewport.Width / 2.0f, RunBackend.m_gViewport.Height / 2.0f };

			ImGui::GetIO().Fonts->AddFontDefault();
			RunBackend.g_mFontConfig.GlyphExtraSpacing.x = 1.2;
			BaseFonts::GameFont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(BaseFonts::TTSquaresCondensedBold, 14, 14, &RunBackend.g_mFontConfig);
			ImGui::GetIO().Fonts->AddFontDefault();

			init = true;
		}
		else
			return originalPresent(pointerSwapChain, sync, flags); // returning original too
	}

	if (Utils::KeyPressed(VK_INSERT))
		RunBackend.m_bOpenMenu = !RunBackend.m_bOpenMenu;

	static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
	int FrameCount = ImGui::GetFrameCount();

	if (isGreen == 0.01f && isBlue == 0.0f) isRed += 0.01f;
	if (isRed > 0.99f && isBlue == 0.0f) { isRed = 1.0f; isGreen += 0.01f; }
	if (isGreen > 0.99f && isBlue == 0.0f) { isGreen = 1.0f; isRed -= 0.01f; }
	if (isRed < 0.01f && isGreen == 1.0f) { isRed = 0.0f; isBlue += 0.01f; }
	if (isBlue > 0.99f && isRed == 0.0f) { isBlue = 1.0f; isGreen -= 0.01f; }
	if (isGreen < 0.01f && isBlue == 1.0f) { isGreen = 0.0f; isRed += 0.01f; }
	if (isRed > 0.99f && isGreen == 0.0f) { isRed = 1.0f; isBlue -= 0.01f; }
	if (isBlue < 0.01f && isGreen == 0.0f) {
		isBlue = 0.0f; isRed -= 0.01f;
		if (isRed < 0.01f) isGreen = 0.01f;
	}

	Variables::RainbowColor = ImVec4(isRed, isGreen, isBlue, 1.0f);

	RunBackend.DrawImGui(RunBackend.m_gPointerContext, RunBackend.m_gMainRenderTargetView); // draw imgui every time
	return originalPresent(pointerSwapChain, sync, flags); // return the original so no stack corruption
}

bool Backend::Load()
{
	RunBackend.DirectXPresentHook(); // this always okay if game directx11
	MH_Initialize(); // aint no error checking cuz if minhook bad then its your problem 

	MH_CreateHook(reinterpret_cast<void**>(hookedPresent), &PresentHook, reinterpret_cast<void**>(&originalPresent));
	MH_EnableHook(hookedPresent); // hooking present

	return true;
}

void Backend::Unload()
{
	UnloadImGui(); // imgui unload
	UnloadDevices(true); // unloading all devices
}