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
	i_windowRunning = 1;
	//bool b = true;
	b_open = true;
}

Window::~Window()
{
	//delete s_windowName;
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void Window::WindowSetup()
{
	//atlas = new ImFontAtlas();
	//tex = new ImTextureID();
	//w_window = new ImGuiWindow(context, s_windowName->c_str());
	//atlas->SetTexID(tex);
	//atlas->Build();
	//io->DisplaySize = ImVec2(900, 900);
	//context->IO = *io;
	//ImGui::SetCurrentContext(context);
	//ImGui::CreateNewWindowSettings("Crowp");
	// SDL Init
	sdl_window = SDL_CreateWindow(s_windowName->c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_BORDERLESS);
	sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	// Dear ImGui Init
	context = ImGui::CreateContext();
	io = &ImGui::GetIO(); (void)io;

	// Backend glue
	ImGui_ImplSDL2_InitForSDLRenderer(sdl_window, sdl_renderer);
	ImGui_ImplSDLRenderer_Init(sdl_renderer);
	b_activeWindow = true;
}

void Window::DrawWindow()
{
	ImGui::Begin("Crowp", &b_open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_MenuBar);
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowSize(ImVec2(900, 900), 0);
	ImGui::End();
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File", true))
		{
			if (ImGui::MenuItem("Connect To Unity")) {}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

void Window::Update()
{
	GatherInputs();
	Render();
}

void Window::Render()
{
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	DrawWindow();

	SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
	SDL_RenderClear(sdl_renderer);

	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(sdl_renderer);
}

void Window::GatherInputs()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		ImGui_ImplSDL2_ProcessEvent(&_event);
		if (_event.type == SDL_QUIT)
			SetRunning(0);
		if (_event.type == SDL_WINDOWEVENT && _event.window.event == SDL_WINDOWEVENT_CLOSE && _event.window.windowID == SDL_GetWindowID(sdl_window))
			SetRunning(0);
		if (_event.type == SDL_MOUSEBUTTONDOWN && _event.button.button == SDL_BUTTON_LEFT)
		{
		}
	}
}

int Window::Running()
{
	return b_open;
}

void Window::SetRunning(int _newVal)
{
	b_open = _newVal;
}