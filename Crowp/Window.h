#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include "SDL.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"
#include "Agent.h"
#include <stdio.h>
#include <string>
#include <iostream>

enum MoveOptions
{
	actionTray = 0,
	actionBin = 1,
	goalTray = 2,
	goalBin = 3
};

enum CrowpWindowEvent
{
	none = 0,
	updateFilePath = 1,
	saveAgent = 2,
	saveGoal = 3,
	saveAction = 4,
};

class Window
{
public:
	Window();
	Window(std::string* _windowName);
	Window(std::string* _windowName, vector<Agent*> _agents);
	~Window();
	void WindowSetup();
	void DrawWindow();
	void Update();
	void UpdateAgents(vector<Agent*> _agents);
	void Render();
	void GatherInputs();
	void SetRunning(int _newVal);
	void ClearEvent();
	int Running();
	CrowpWindowEvent GetWindowEvent();
	string* FilePath();
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
	bool b_inputFilePath = false;
	int _bufferSize = 64;
	int _currentAgent = 0;
	vector<Agent*> aV_agents;
	MoveOptions mo_options = actionTray;
	CrowpWindowEvent cwe_event = none;
	string* s_filePath;
private:

};