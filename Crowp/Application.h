#pragma once
#include "GenericReader.h"
#include "FileUtilities.h"

class Application
{
public:
	Application();
	~Application();
	int main();
protected:
	GenericReader<string>* readFile;
	FileUtils* fp;
private:

};