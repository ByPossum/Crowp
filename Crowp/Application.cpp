#include "Application.h"

Application::Application()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	fp = new FileUtils();
	am_agents = new AgentManager();
	window = new Window(new string("Crowp"), am_agents->GetAgents());
	i_running = 1;
}

Application::~Application()
{
	delete fp;
	delete window;
	delete am_agents;
	SDL_Quit();
}

void Application::main()
{
	window->Update();
	HandleWindowEvents();
	i_running = window->Running();
}

void Application::HandleWindowEvents()
{
	switch (window->GetWindowEvent())
	{
		case none:
			break;
		case updateFilePath:
			am_agents->SetFilePath(window->FilePath());
			am_agents->LoadAgents();
			window->UpdateAgents(am_agents->GetAgents());
			window->ClearEvent();
			break;
		case saveAgent:
			break;
		case saveGoal:
			break;
		case saveAction:
			break;
	}
}

int Application::Running()
{
	return i_running;
}