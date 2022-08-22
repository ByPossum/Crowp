#include "Application.h"

int main(int argv, char** args)
{
	Application* app = new Application();
	while (app->Running())
	{
		app->main();
	}
	delete app;
	return 0;
}