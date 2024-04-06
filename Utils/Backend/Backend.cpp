#include "../Backend/Backend.h"
#include "../../Cheat/Functions/Functions.h"

Backend::presentVariable originalPresent;
Backend::presentVariable hookedPresent;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static bool init = false;

Backend RunBackend;

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
	}

	void Visuals() {
		ImGui::Checkbox("Circle FOV", &Variables::EnableCircleFov);
		if (Variables::EnableCircleFov)
		{
			ImGui::SliderFloat("##CircleFOV", &Variables::CircleFov, 20, 180, "Circle FOV: %.0f");
			ImGui::ColorEdit3("Circle Colour", (float*)&Variables::CircleColour);
			ImGui::Checkbox("Rainbow?", &Variables::EnableRainbowCircle);
		}
		ImGui::Checkbox("Crosshair", &Variables::EnableCrosshair);
		if (Variables::EnableCrosshair)
		{
			ImGui::SliderFloat("##CrosshairSize", &Variables::CrosshairSize, 1, 20, "Crosshair Size: %.0f");
			ImGui::ColorEdit3("Crosshair Colour", (float*)&Variables::CrosshairColor);
			ImGui::Checkbox("Rainbow?", &Variables::EnableRainbowCrosshair);
		}
		ImGui::Checkbox("Watermark", &Variables::EnableWatermark);
		if (Variables::EnableWatermark)
		{
			ImGui::Checkbox("FPS?", &Variables::EnableFPS);
			ImGui::Checkbox("Rainbow?", &Variables::EnableRainbowWatermark);
		}
	}

	void Player() {
		bool isSettingHotkey = false;

		ImGui::Checkbox("Game Speed", &Variables::GameSpeed);
		if (ImGui::Button("[-]")) {
			isSettingHotkey = !isSettingHotkey;
		}
		
		if (isSettingHotkey) {
			ImGui::SameLine();
			ImGui::Text("Press a key to set as hotkey...");

			for (int key = 1; key < 512; key++)
			{
				if (Utils::KeyPressed(key) & 0x8000)
				{
					Variables::GameSpeedKey = key;
					isSettingHotkey = false;
					break;
				}
			}
		}
		else {
			const char* keyName = "None";
			switch (Variables::GameSpeedKey)
			{
				case VK_LBUTTON: keyName = "Left Mouse Button"; break;
				case VK_RBUTTON: keyName = "Right Mouse Button"; break;
				case VK_CANCEL: keyName = "Control-break processing"; break;
				case VK_MBUTTON: keyName = "Middle Mouse Button"; break;
				case VK_XBUTTON1: keyName = "X1 Mouse Button"; break;
				case VK_XBUTTON2: keyName = "X2 Mouse Button"; break;
				case VK_BACK: keyName = "Backspace"; break;
				case VK_TAB: keyName = "Tab"; break;
				case VK_CLEAR: keyName = "Clear"; break;
				case VK_RETURN: keyName = "Enter"; break;
				case VK_SHIFT: keyName = "Shift"; break;
				case VK_CONTROL: keyName = "Ctrl"; break;
				case VK_MENU: keyName = "Alt"; break;
				case VK_PAUSE: keyName = "Pause"; break;
				case VK_CAPITAL: keyName = "Caps Lock"; break;
				case VK_ESCAPE: keyName = "Escape"; break;
				case VK_SPACE: keyName = "Spacebar"; break;
				case VK_PRIOR: keyName = "Page Up"; break;
				case VK_NEXT: keyName = "Page Down"; break;
				case 0x41: keyName = "A"; break;
				case 0x42: keyName = "B"; break;
				case 0x43: keyName = "C"; break;
				case 0x44: keyName = "D"; break;
				case 0x45: keyName = "E"; break;
				case 0x46: keyName = "F"; break;
				case 0x47: keyName = "G"; break;
				case 0x48: keyName = "H"; break;
				case 0x49: keyName = "I"; break;
				case 0x4A: keyName = "J"; break;
				case 0x4B: keyName = "K"; break;
				case 0x4C: keyName = "L"; break;
				case 0x4D: keyName = "M"; break;
				case 0x4E: keyName = "N"; break;
				case 0x4F: keyName = "O"; break;
				case 0x50: keyName = "P"; break;
				case 0x51: keyName = "Q"; break;
				case 0x52: keyName = "R"; break;
				case 0x53: keyName = "S"; break;
				case 0x54: keyName = "T"; break;
				case 0x55: keyName = "U"; break;
				case 0x56: keyName = "V"; break;
				case 0x57: keyName = "W"; break;
				case 0x58: keyName = "X"; break;
				case 0x59: keyName = "Y"; break;
				case 0x5A: keyName = "Z"; break;
			}
			ImGui::SameLine();
			ImGui::Text("GameSpeed key: %s", keyName);
		}
		if (Variables::GameSpeed)
			ImGui::SliderFloat("##SpeedMultiplier", &Variables::SpeedMultipler, 0.1f, 10.0f, "Speed Multiplier: %.1f");
	}

	void Settings() {
		#ifdef _DEBUG
		ImGui::Text("Developer Logs");
		ImGui::Text("Screen Size: %.0f x %.0f", Variables::ScreenSize.x, Variables::ScreenSize.y);
		ImGui::Text("Screen Center: %.0f x %.0f", Variables::ScreenCenter.x, Variables::ScreenCenter.y);
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
	if(renderTargetViewReset) if (m_gMainRenderTargetView) { m_gMainRenderTargetView->Release(); m_gMainRenderTargetView = nullptr; }
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
			GameFunctions::SetTimeScale(Variables::SpeedMultipler);
		else
			GameFunctions::SetTimeScale(1.0f);
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
		Utils::Watermark("@bosslawl", true); // text to set the watermark, and true/false to show fps
	else if(Variables::EnableWatermark && !Variables::EnableFPS)
		Utils::Watermark("@bosslawl", false); // text to set the watermark, and true/false to show fps
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
	if (isRed > 0.99f && isBlue == 0.0f) {isRed = 1.0f; isGreen += 0.01f; }
	if (isGreen > 0.99f && isBlue == 0.0f) { isGreen = 1.0f; isRed -= 0.01f; }
	if (isRed < 0.01f && isGreen == 1.0f){ isRed = 0.0f; isBlue += 0.01f; }
	if (isBlue > 0.99f && isRed == 0.0f) { isBlue = 1.0f; isGreen -= 0.01f; } // ugliest function ive ever seen
	if (isGreen < 0.01f && isBlue == 1.0f) { isGreen = 0.0f; isRed += 0.01f; }
	if (isRed > 0.99f && isGreen == 0.0f) { isRed = 1.0f; isBlue -= 0.01f; }
	if (isBlue < 0.01f && isGreen == 0.0f) { isBlue = 0.0f; isRed -= 0.01f;
		if (isRed < 0.01f) isGreen = 0.01f; }

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