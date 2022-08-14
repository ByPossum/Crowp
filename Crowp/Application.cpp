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
	delete w_window;
}

int Application::main()
{
	ImGui::SetWindowSize(w_window, io->DisplaySize, 0);
	ImGui::NewFrame();
	ImGui::EndFrame();
	ImGui::Render();
	DrawWindow();
	return 0;
}

void Application::WindowSetup()
{
	context = ImGui::CreateContext();
	w_window = new ImGuiWindow(context, "Crowp");
	atlas = new ImFontAtlas();
	ImTextureID* tex = new ImTextureID();
	atlas->TexID = tex;
	atlas->Build();
	io = new ImGuiIO();
	io->DisplaySize = ImVec2(900, 900);
	context->IO = *io;
	ImGui::SetCurrentContext(context);
	ImGui::CreateNewWindowSettings("Crowp");
	b_activeWindow = true;
}

void Application::DrawWindow()
{
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