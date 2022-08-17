#include "Application.h"

Application::Application()
{
	fp = new FileUtils();
	string* filePath = new string(fp->CurrentPath() + "\\TestFiles\\Test.txt");
	readFile = new GenericReader<string>(filePath);
	delete fp;
	window = new Window(new string("Crowp"));
}

Application::~Application()
{
	delete fp;
	delete readFile;
	delete window;
}

int Application::main()
{
	window->Update();
	return 0;
}