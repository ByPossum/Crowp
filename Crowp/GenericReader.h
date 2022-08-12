#pragma once
#include <rapidxml.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
using namespace rapidxml;

template <typename T>

class GenericReader
{
public:
	GenericReader<T>(string* _filePath)
	{
		s_filePath = _filePath;
		xml_doc = BufferData(s_filePath);
	}
	~GenericReader()
	{
		delete s_filePath;
		//delete xml_doc;
	}
	/// <summary>
	/// Write data from buffer to file
	/// </summary>
	void WriteData() {}
	/// <summary>
	/// Write data from a new source to file
	/// </summary>
	/// <param name="_source"></param>
	void WriteData(T _source) {}
	/// <summary>
	/// Read from file XML data and stored it in memory
	/// </summary>
	/// <param name="_fileName">Path to data</param>
	xml_document<T>* BufferData(string* _fileName)
	{
		//xml_document<T>* doc = new xml_document<T>();
		string* _file = ReadFromFile(*_fileName);
		std::cout << *_file << std::endl;
		//doc->parse(_file);
		delete _file;
		//return doc;
		return nullptr;
	}
	/// <summary>
	/// Read XML data from already buffered source
	/// </summary>
	/// <returns>Buffered Data</returns>
	xml_document<T> ReadData()
	{
		return xml_doc;
	}
	/// <summary>
	/// Buffer data from source then return the bufferd data
	/// </summary>
	/// <param name="_fileName">File Path to Buffered Data</param>
	/// <returns>Buffered Data</returns>
	xml_document<T> ReadData(string _fileName)
	{
		return xml_doc;
	}
protected:
	xml_document<T>* xml_doc;
	string* s_filePath;
	string* ReadFromFile(string _fileName)
	{
		ifstream fileData (_fileName, std::ifstream::in);
		string* readFile = new string();
		string _line;
		if (fileData.is_open())
		{
			while (getline(fileData, _line))
			{
				readFile->append(_line);
			}
		}
		return readFile;
	}
private:
};