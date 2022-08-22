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
	sdl_window = SDL_CreateWindow(s_windowName->c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
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
	ImGui::Begin("Crowp");
	//if (ImGui::BeginMenuBar())
	//{
	//	if (ImGui::BeginMenu("File"))
	//	{
	//		if (ImGui::MenuItem("Connect To Unity")) {}
	//	}
	//	ImGui::EndMenu();
	//}
	//ImGui::EndMenuBar();
	ImGui::Text("Hi There");
	ImGui::End();
}

void Window::Update()
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