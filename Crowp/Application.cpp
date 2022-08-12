#include "Application.h"

Application::Application()
{
	fp = new FileUtils();
	string* filePath = new string(fp->CurrentPath() + "\\TestFiles\\Test.txt");
	readFile = new GenericReader<string>(filePath);
	delete fp;
	
	WindowSetup();

}

Application::~Application()
{
	delete fp;
	delete readFile;
}

int Application::main()
{
	ImGui::NewFrame();
	ImGui::Render();
	ImGui::EndFrame();
	return 0;
}

void Application::WindowSetup()
{
	bool b_activeWindow = true;

	ImGui::Begin("Crowp", &b_activeWindow, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Connect To Unity")) {}
		}
		ImGui::EndMenu();
	}
	ImGui::EndMenuBar();

	ImGui::End();
	cout << "New Window Made" << endl;
}