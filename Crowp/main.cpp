#include "Application.h"

int main(int argv, char** args)
{
	int running = 1;
	Application* app = new Application();
	while (app->Running())
	{
		app->main();
	}
	delete app;
	return 0;
}