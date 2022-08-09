#pragma once
#include "GenericReader.h"

class Application
{
public:
	Application();
	~Application();
	int main();
protected:
	GenericReader<string>* readFile;
private:

};