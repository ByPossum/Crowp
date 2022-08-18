#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include "SDL.h"
#include "imgui_impl_sdl.h"
#include <stdio.h>
#include <string>

class Window
{
public:
	Window();
	Window(std::string* _windowName);
	~Window();
	void WindowSetup();
	void DrawWindow();
	void Update();
protected:
	SDL_Window* sdl_window;
	SDL_Renderer* sdl_renderer;
	ImGuiContext* context;
	ImGuiWindow* w_window;
	ImGuiIO* io;
	ImFontAtlas* atlas;
	std::string* s_windowName;
	ImTextureID* tex;
	bool b_activeWindow;
private:

};