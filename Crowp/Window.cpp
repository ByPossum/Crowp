#include "Window.h"

Window::Window()
{
	s_windowName = new std::string("Blank Window");
	WindowSetup();
}

Window::Window(std::string* _windowName)
{
	s_windowName = _windowName;
	WindowSetup();
}

Window::~Window()
{
	delete context;
	delete w_window;
	delete s_windowName;
	delete io;
	delete atlas;
	delete tex;
}

void Window::WindowSetup()
{
	context = ImGui::CreateContext();
	w_window = new ImGuiWindow(context, s_windowName->c_str());
	atlas = new ImFontAtlas();
	tex = new ImTextureID();
	atlas->SetTexID(tex);
	atlas->Build();
	io = new ImGuiIO();
	io->DisplaySize = ImVec2(900, 900);
	context->IO = *io;
	ImGui::SetCurrentContext(context);
	ImGui::CreateNewWindowSettings("Crowp");
	b_activeWindow = true;
}

void Window::DrawWindow()
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
}

void Window::Update()
{
	ImGui::SetWindowSize(w_window, io->DisplaySize, 0);
	ImGui::NewFrame();
	ImGui::EndFrame();
	ImGui::Render();
	DrawWindow();
}