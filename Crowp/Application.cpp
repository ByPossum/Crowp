#include "Application.h"

Application::Application()
{
	fp = new FileUtils();
	string* filePath = new string(fp->CurrentPath() + "\\TestFiles\\Test.txt");
	readFile = new GenericReader<string>(filePath);
	delete fp;
}

Application::~Application()
{
	delete fp;
	delete readFile;
}

int Application::main()
{
	return 0;
}