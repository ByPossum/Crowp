#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <filesystem>
#include <experimental/filesystem>
#include <string>
class FileUtils
{
public:
	FileUtils();
	~FileUtils();
	std::string* CurrentPathPtr();
	std::string CurrentPath();
private:
	std::string* s_currentPath;
};