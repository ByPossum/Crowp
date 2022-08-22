#include "Application.h"

Application::Application()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	fp = new FileUtils();
	string* filePath = new string(fp->CurrentPath() + "\\TestFiles\\Test.txt");
	readFile = new GenericReader<string>(filePath);
	window = new Window(new string("Crowp"));
	i_running = 1;
}

Application::~Application()
{
	delete fp;
	delete readFile;
	delete window;
	SDL_Quit();
}

void Application::main()
{
	window->Update();
	i_running = 1;
}

int Application::Running()
{
	return i_running;
}