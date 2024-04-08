#pragma once

#define WIN32_LEAN_AND_MEAN
#define UNITY_CALLING_CONVENTION __fastcall*

#include <windows.h>
#include <iostream>
#include <WinUser.h>
#include <tchar.h>
#include <thread>
#include <stdlib.h> 
#include <dwmapi.h>
#include <TlHelp32.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <MinHook.h>

#include "./ImGui/imgui.h"
#include "./ImGui/imgui_impl_win32.h"
#include "./ImGui/imgui_impl_dx11.h"
#include "./ImGui/imgui_internal.h"

#include "../Cheat/Utils/SDK.h"
#include "../Cheat/Utils/Offsets.h"
#include "../Cheat/Utils/Variables.h"
#include "../Cheat/Signatures/Signatures.h"
#include "../Cheat/Hooks/Hooks.h"
#include "../IL2CPPResolver/il2cpp_resolver.hpp"
#include "../IL2CPPResolver/Unity/Structures/Engine.hpp"
#include "../Utils/IL2CPPHeader/il2cpp.h"

#include "../Utils/Math/Vectors/Vector2.h"
#include "../Utils/Math/Vectors/Vector3.h"

#include "../Utils/Obfuscation/Obfuscate.h"

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

namespace Utils {
	inline uintptr_t String2Offset(const char* c) {
		int base = 16;
		// See if this function catches all possibilities.
		// If it doesn't, the function would have to be amended
		// whenever you add a combination of architecture and
		// compiler that is not yet addressed.
		static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
			|| sizeof(uintptr_t) == sizeof(unsigned long long),
			"");

		// Now choose the correct function ...
		if (sizeof(uintptr_t) == sizeof(unsigned long)) {
			return strtoul(c, nullptr, base);
		}

		// All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
		return strtoull(c, nullptr, base);
	}

	inline bool KeyPressed(int vKey)
	{
		return (GetAsyncKeyState(vKey) & 1) != 0;
	}

	inline std::string GetKeyNameFromVirtualKey(int virtualKey) {
		switch (virtualKey) {
		case VK_F1: return "F1";
		case VK_F2: return "F2";
		case VK_F3: return "F3";
		case VK_F4: return "F4";
		case VK_F5: return "F5";
		case VK_F6: return "F6";
		case VK_F7: return "F7";
		case VK_F8: return "F8";
		case VK_F9: return "F9";
		case VK_F10: return "F10";
		case VK_F11: return "F11";
		case VK_F12: return "F12";
		case VK_INSERT: return "INSERT";
		case VK_DELETE: return "DELETE";
		case VK_HOME: return "HOME";
		case VK_END: return "END";
		case VK_PRIOR: return "PAGE UP";
		case VK_NEXT: return "PAGE DOWN";
		case VK_UP: return "UP";
		case VK_DOWN: return "DOWN";
		case VK_LEFT: return "LEFT";
		case VK_RIGHT: return "RIGHT";
		case VK_LBUTTON: return "MOUSE 1";
		case VK_RBUTTON: return "MOUSE 2";
		case VK_MBUTTON: return "MOUSE 3";
		case VK_XBUTTON1: return "MOUSE 4";
		case VK_XBUTTON2: return "MOUSE 5";
		case VK_BACK: return "BACKSPACE";
		case VK_TAB: return "TAB";
		case VK_RETURN: return "ENTER";
		case VK_SHIFT: return "SHIFT";
		case VK_CONTROL: return "CTRL";
		case VK_MENU: return "ALT";
		case VK_CAPITAL: return "CAPS LOCK";
		case VK_ESCAPE: return "ESC";
		case VK_SPACE: return "SPACE";
		default: return "Unknown";
		}
	}

	inline void AddressLog(uintptr_t address, const char* name) {
		printf("[ LOG ] %s: 0x%llX\n", name, address);
	}

	inline bool World2Screen(Unity::Vector3 world, Vector2& screen)
	{
		Unity::CCamera* CameraMain = Unity::Camera::GetMain();
		if (!CameraMain) {
			return false;
		}

		Unity::Vector3 buffer = CameraMain->CallMethodSafe<Unity::Vector3>("WorldToScreenPoint", world, Unity::eye::mono); // Call the worldtoscren function using monoeye (2)

		if (buffer.x > Variables::ScreenSize.x || buffer.y > Variables::ScreenSize.y || buffer.x < 0 || buffer.y < 0 || buffer.z < 0) // check if point is on screen
		{
			return false;
		}

		if (buffer.z > 0.0f) // Check if point is in view
		{
			screen = Vector2(buffer.x, Variables::ScreenSize.y - buffer.y);
		}

		if (screen.x > 0 || screen.y > 0) // Check if point is in view
		{
			return true;
		}
	}

	inline void UseFov(static bool IsRainbow)
	{
		if(IsRainbow)
			ImGui::GetForegroundDrawList()->AddCircle(ImVec2(Variables::ScreenCenter.x, Variables::ScreenCenter.y), Variables::CircleFov, ImColor(Variables::RainbowColor.x, Variables::RainbowColor.y, Variables::RainbowColor.z, Variables::RainbowColor.w), 360);
		else
			ImGui::GetForegroundDrawList()->AddCircle(ImVec2(Variables::ScreenCenter.x, Variables::ScreenCenter.y), Variables::CircleFov, Variables::CircleColour, 360);
	}

	inline void UseCrosshair(static bool IsRainbow)
	{
		if (IsRainbow)
		{
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(Variables::ScreenCenter.x - Variables::CrosshairSize, Variables::ScreenCenter.y), ImVec2((Variables::ScreenCenter.x - Variables::CrosshairSize) + (Variables::CrosshairSize * 2), Variables::ScreenCenter.y), ImColor(Variables::RainbowColor.x, Variables::RainbowColor.y, Variables::RainbowColor.z, Variables::RainbowColor.w), 1.2f);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(Variables::ScreenCenter.x, Variables::ScreenCenter.y - Variables::CrosshairSize), ImVec2(Variables::ScreenCenter.x, (Variables::ScreenCenter.y - Variables::CrosshairSize) + (Variables::CrosshairSize * 2)), ImColor(Variables::RainbowColor.x, Variables::RainbowColor.y, Variables::RainbowColor.z, Variables::RainbowColor.w), 1.2f);
		}
		else 
		{
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(Variables::ScreenCenter.x - Variables::CrosshairSize, Variables::ScreenCenter.y), ImVec2((Variables::ScreenCenter.x - Variables::CrosshairSize) + (Variables::CrosshairSize * 2), Variables::ScreenCenter.y), Variables::CrosshairColor, 1.2f);
			ImGui::GetForegroundDrawList()->AddLine(ImVec2(Variables::ScreenCenter.x, Variables::ScreenCenter.y - Variables::CrosshairSize), ImVec2(Variables::ScreenCenter.x, (Variables::ScreenCenter.y - Variables::CrosshairSize) + (Variables::CrosshairSize * 2)), Variables::CrosshairColor, 1.2f);
		}
	}

	inline void Watermark(bool showFPS, const char* text, ImVec4 color, ImVec4 hoverColor)
	{
		bool open = true;
		const float distance = 10.0f;
		ImGuiIO& io = ImGui::GetIO();
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBackground;

		ImVec2 windowPos = ImVec2(distance, distance);

		ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);
		ImGui::SetNextWindowBgAlpha(0.0f);

		if (ImGui::Begin("Watermark", &open, windowFlags))
		{
			if (showFPS)
				ImGui::TextColored(color, "%s | FPS: %i", text, static_cast<int>(io.Framerate));
			else
				ImGui::TextColored(color, text);

			ImGui::End();
		}
	}
}
