#pragma once
#include "GenericReader.h"
#include "FileUtilities.h"
#include "imgui.h"
#include "imgui_internal.h"

class Application
{
public:
	Application();
	~Application();
	int main();
protected:
	GenericReader<string>* readFile;
	FileUtils* fp;
	ImGuiContext* context;
	bool b_activeWindow;
	void WindowSetup();
	void DrawWindow();

private:

};
