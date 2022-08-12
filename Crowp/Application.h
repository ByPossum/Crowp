#pragma once
#include "GenericReader.h"
#include "FileUtilities.h"
#include "imgui.h"

class Application
{
public:
	Application();
	~Application();
	int main();
protected:
	GenericReader<string>* readFile;
	FileUtils* fp;
	void WindowSetup();
private:

};
