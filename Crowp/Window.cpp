#include "Window.h"

Window::Window()
{
	s_windowName = new std::string("Blank Window");
	WindowSetup();
}

Window::Window(std::string* _windowName)
{
	s_windowName = _windowName;
	WindowSetup();
	b_open = true;
}

Window::Window(std::string* _windowName, vector<Agent*> _agents)
{
	s_windowName = _windowName;
	aV_agents = _agents;
	WindowSetup();
	b_open = true;
}

Window::~Window()
{
	//delete s_windowName;
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void Window::WindowSetup()
{
	// SDL Init
	sdl_window = SDL_CreateWindow(s_windowName->c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_BORDERLESS);
	sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	// Dear ImGui Init
	context = ImGui::CreateContext();
	io = &ImGui::GetIO(); (void)io;

	// Backend glue
	ImGui_ImplSDL2_InitForSDLRenderer(sdl_window, sdl_renderer);
	ImGui_ImplSDLRenderer_Init(sdl_renderer);
	b_activeWindow = true;
}

void Window::DrawWindow()
{
	// Assign window style
	ImGuiStyle* _style = &ImGui::GetStyle();
	_style->WindowMinSize = ImVec2(900, 900);
	_style->Colors[ImGuiCol_WindowBg] = ImColor(18, 53, 36, 255);
	_style->Colors[ImGuiCol_Border] = ImColor(0, 0, 0, 255);
	_style->Colors[ImGuiCol_ChildBg] = ImColor(5, 34, 19, 255);

	// Create window
	ImGui::Begin("Crowp", &b_open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysUseWindowPadding);
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowSize(ImVec2(900, 900), 0);

	// Initialize button index
	int _btnInd = 0;

	// Create file menu
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File", true))
		{
			if (ImGui::MenuItem("Input Filepath"))
			{
				b_inputFilePath = !b_inputFilePath;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
		// Output the new filepath once you've ended the menu bar
		if (b_inputFilePath)
		{
			char _output[1024]{};
			if (ImGui::InputText("Filepath", _output, _bufferSize, ImGuiInputTextFlags_EnterReturnsTrue))
			{
				s_filePath = new string(_output);
				remove_if(s_filePath->begin(), s_filePath->end(), isspace);
				cwe_event = updateFilePath;
				b_inputFilePath = false;
			}

		}
	}
	
#pragma region Agent Tray
	// Agent Tray
	ImGui::BeginChild("Agents", ImVec2(300, 810), true);
	ImGui::Text("Agents");
	for (int i = 0; i < aV_agents.size(); i++)
	{
		if (ImGui::Button(aV_agents[i]->Name().c_str(), ImVec2((int)aV_agents[i]->Name().length() * 10, 30)))
		{
			_currentAgent = i;
		}
	}
	ImGui::EndChild();
#pragma endregion

#pragma region Goals and Actions
	#pragma region Agent Goals
	ImGui::SameLine();
	ImGui::BeginGroup();
		ImGui::BeginChild("AgentGoals", ImVec2(250, 400), true);
			ImGui::Text("Agent's Goals");
			//ImGui::InvisibleButton("AgentGoalButton", ImVec2(200, 300), ImGuiButtonFlags_AllowItemOverlap | ImGuiButtonFlags_FlattenChildren);
			if (ImGui::BeginDragDropTarget())
			{
				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("AgentGoalPayload"))
				{
					std::cout << "Zap" << std::endl;
				}
				ImGui::EndDragDropTarget();
			}
			if (!aV_agents.empty())
			{
				for (int i = 0; i < aV_agents[_currentAgent]->GetStates().size(); i++)
				{
					for (int j = 0; j < aV_agents[_currentAgent]->GetStates()[i]->GetStates().size(); j++)
					{
						string _name = aV_agents[_currentAgent]->GetStates()[i]->GetStates()[j]->GetName();
						if (ImGui::Button(_name.c_str(), ImVec2(_name.length() * 10, 30)))
						{

						}
						if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
						{
							ImGui::SetDragDropPayload("AgentGoalPayload", &j, sizeof(int));
							ImGui::EndDragDropSource();
						}
					}
				}
			}
		ImGui::EndChild();
	#pragma endregion
	#pragma region Agent Actions
		ImGui::SameLine();
		ImGui::BeginChild("AgentActions", ImVec2(250, 400), true);
			ImGui::Text("Agent's Actions");
			//ImGui::InvisibleButton("AgentActionButton", ImVec2(200, 300), ImGuiButtonFlags_AllowItemOverlap | ImGuiButtonFlags_FlattenChildren);
			if (ImGui::BeginDragDropTarget())
			{
				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("AgentActionPayload"))
				{
					if (mo_options == goalBin)
					{
						mo_options = goalTray;
					}
					std::cout << "Beep" << std::endl;
				}
				ImGui::EndDragDropTarget();
			}
			if (!aV_agents.empty())
				for (int j = 0; j < aV_agents[_currentAgent]->GetActions()->GetActions().size(); j++)
				{
					string _actionName = aV_agents[_currentAgent]->GetActions()->GetActions()[j]->Name();
					if (ImGui::Button(_actionName.c_str(), ImVec2(_actionName.length() * 10, 30)))
					{
						_btnInd = j;
					}
					if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
					{
						ImGui::SetDragDropPayload("AgentActionPayload", &j, sizeof(int));
						mo_options = goalTray;
						std::cout << _actionName << std::endl;
						ImGui::EndDragDropSource();

					}
				}

		ImGui::EndChild();
	#pragma endregion
	#pragma region Unused Goals
		ImGui::Separator();
		_style->Colors[ImGuiCol_WindowBg] = ImColor(3, 25, 10, 255);
		ImGui::BeginChild("UnusedGoals", ImVec2(250, 400), true);
			ImGui::Text("Unused Goals");
			if (ImGui::BeginDragDropTarget())
			{
				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("AgentGoalPayload"))
				{
					std::cout << "Beep" << std::endl;
				}
				ImGui::EndDragDropTarget();
			}
		ImGui::EndChild();
	#pragma endregion
	#pragma region Unused Actions
		ImGui::SameLine();
		ImGui::BeginChild("UnusedActions", ImVec2(250, 400), true);
			ImGui::Text("Unused Actions");
			if (ImGui::BeginDragDropTarget())
			{
				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("AgentActionPayload"))
				{
					int j = *(const int*) payload->Data;
					aV_agents[_currentAgent]->GetActions()->RemoveAction(j);
					std::cout << "Removing Action!" << std::endl;
				}
				ImGui::EndDragDropTarget();
			}
		ImGui::EndChild();
	#pragma endregion
	ImGui::EndGroup();
#pragma endregion

	ImGui::End();
}

void Window::Update()
{
	GatherInputs();
	Render();
}

void Window::UpdateAgents(vector<Agent*> _agents)
{
	aV_agents = _agents;
}

void Window::Render()
{
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	DrawWindow();

	SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
	SDL_RenderClear(sdl_renderer);

	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(sdl_renderer);
}

void Window::GatherInputs()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		ImGui_ImplSDL2_ProcessEvent(&_event);
		if (_event.type == SDL_QUIT)
			SetRunning(0);
		if (_event.type == SDL_WINDOWEVENT && _event.window.event == SDL_WINDOWEVENT_CLOSE && _event.window.windowID == SDL_GetWindowID(sdl_window))
			SetRunning(0);
		if (_event.type == SDL_MOUSEBUTTONDOWN && _event.button.button == SDL_BUTTON_LEFT)
		{
		}
	}
}

void Window::ClearEvent()
{
	cwe_event = none;
}

int Window::Running()
{
	return b_open;
}

CrowpWindowEvent Window::GetWindowEvent()
{
	return cwe_event;
}

void Window::SetRunning(int _newVal)
{
	b_open = _newVal;
}

string* Window::FilePath()
{
	return s_filePath;
}