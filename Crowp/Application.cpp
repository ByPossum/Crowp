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
	delete context;
}

int Application::main()
{
	ImGui::NewFrame();
	ImGui::EndFrame();
	ImGui::Render();
	DrawWindow();
	return 0;
}

void Application::WindowSetup()
{
	context = ImGui::CreateContext();
	ImGui::SetCurrentContext(context);
	b_activeWindow = true;
}

void Application::DrawWindow()
{
	ImGui::Begin("Crowp", &b_activeWindow, ImGuiWindowFlags_MenuBar);
	ImGui::SetWindowSize(ImVec2(900, 900));
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