#pragma once
#include "GenericReader.h"
#include "FileUtilities.h"
#include "Window.h"

class Application
{
public:
	Application();
	~Application();
	void main();
	int Running();
protected:
	GenericReader<string>* readFile;
	FileUtils* fp;
	Window* window;
	int i_running;
private:

};
