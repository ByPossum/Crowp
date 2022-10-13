#include "Application.h"

Application::Application()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	fp = new FileUtils();
	string* filePath = new string("C://Users//ImHiP//AppData//LocalLow//Bon//CROWPImp//Goap//Agents//TestAgent.xml");
	readFile = new GenericReader<string>(filePath);
	Agent* _newAgent = readFile->ReadAgent(*filePath);
	_newAgent->DebugAgent();
	agents.push_back(_newAgent);
	window = new Window(new string("Crowp"), agents);
	i_running = 1;
}

Application::~Application()
{
	delete fp;
	delete readFile;
	delete window;
	for (int i = 0; i < agents.size(); i++)
	{
		delete agents[i];
	}
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