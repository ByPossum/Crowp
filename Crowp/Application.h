#pragma once
#include "GenericReader.h"
#include "FileUtilities.h"
#include "Window.h"
#include "AgentManager.h"
class Application
{
public:
	Application();
	~Application();
	void main();
	int Running();
protected:
	FileUtils* fp;
	Window* window;
	int i_running;
	void HandleWindowEvents();
	AgentManager* am_agents;
private:

};
