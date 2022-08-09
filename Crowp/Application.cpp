#include "Application.h"
#include "GenericReader.h"

Application::Application()
{
	string* fp = new string("C:\\Users\\ImHiP\\Documents\\GitHub\\Crowp\\Crowp\\TestFiles\\Test.txt");
	readFile = new GenericReader<string>(fp);
	delete fp;
}

Application::~Application()
{
	delete readFile;
}

int Application::main()
{
	return 0;
}