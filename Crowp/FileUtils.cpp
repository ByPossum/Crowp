#include "FileUtilities.h"

FileUtils::FileUtils()
{
	std::experimental::filesystem::path _filePath = std::experimental::filesystem::current_path();
	s_currentPath = new std::string(_filePath.generic_string());
}

FileUtils::~FileUtils()
{

}

std::string* FileUtils::CurrentPathPtr()
{
	return s_currentPath;
}

std::string FileUtils::CurrentPath()
{
	return *s_currentPath;
}