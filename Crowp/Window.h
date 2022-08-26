#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include "SDL.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
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
	void Render();
	void GatherInputs();
	int Running();
	void SetRunning(int _newVal);
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
	int i_windowRunning;
	bool b_open;
private:

};