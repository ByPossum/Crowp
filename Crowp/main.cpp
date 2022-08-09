#include "Application.h"

int main()
{
	int running = 1;
	Application* app = new Application();
	while (running)
	{
		return app->main();
	}
	delete app;
	return 0;
}