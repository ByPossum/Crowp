#pragma once
#include <rapidxml.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "Agent.h"
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
		xml_document<T>* doc = nullptr;
		//string* _file = ReadFromFile(*_fileName);
		//std::cout << *_file << std::endl;
		//doc.parse<0>(_file);
		//xml_node<> _firstNode = doc->first_node();
		//std::cout << _firstNode.m_type + " | " + _firstNode.m_name << std::endl;
		return doc;
	}
	/// <summary>
	/// Read XML data for an agent from specified Filepath.
	/// </summary>
	/// <returns>Pointer to newly created Agent</returns>
	Agent* ReadAgent(string _fileName)
	{
		// Create the XML document and parse it into XML Document
		xml_document<> doc;
		ifstream file(_fileName);
		vector<char> buf((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
		buf.push_back('\0');
		doc.parse<0>(&buf[0]);

		// Get our first node and assign Agent's name
		xml_node<>* root = NULL;
		root = doc.first_node("Agent");
		string* agentName = new string(root->last_attribute("Name", 0, true)->value());
		
		// Initialize our Agent's attributes
		ActionSet* _as = new ActionSet();
		vector<StateCollection*> _goals;

		// Get our ActionSet from XML
		for (xml_node<>* _allActions = root->first_node("Actions"); _allActions; _allActions = _allActions->next_sibling())
		{
			for (xml_node<>* _actionSet = _allActions->first_node("GetActionSet"); _actionSet; _actionSet = _actionSet->next_sibling())
			{
				for (xml_node<>* _action = _actionSet->first_node("Action"); _action; _action = _action->next_sibling())
				{
					// Obtain the actions name and attributes
					string* _actionName = new string(_action->first_attribute("ActionName")->value());
					StateCollection* _preconditions = GetConditions(_action, "Precondition");
					StateCollection* _postconditions = GetConditions(_action, "PostCondition");
					Action* _newAction = new Action(_actionName, _preconditions, _postconditions);
					// Add it to our ActionSet
					_as->AddAction(_newAction);
				}
			}
		}
		for (xml_node<>* _newGoal = root->first_node("Goals"); _newGoal; _newGoal = _newGoal->next_sibling())
		{
			for (xml_node<>* _allStates = _newGoal->first_node("States"); _allStates; _allStates = _allStates->next_sibling())
			{
				StateCollection* _newGoals = new StateCollection();
				for (xml_node<>* _state = _allStates->first_node("State"); _state; _state = _state->next_sibling())
				{
					bool* _b = new bool(_state->first_attribute("CurrentState")->value());
					State* _newState = new State(new string(_state->first_attribute("Name")->value()), _b);
					_newGoals->AddState(_newState);
				}
				_goals.push_back(_newGoals);
			}
		}
		Agent* newAg = new Agent(agentName, _goals, _as);
		return newAg;
	}

	/// <summary>
	/// Get a StateCollection from the specified Parent Node
	/// </summary>
	/// <param name="_parent">The Parent Node that owns the <States><State></State></States> </param>
	/// <param name="_nodeName">The name of the Parent Node</param>
	/// <returns>State Collection from specified are of XML</returns>
	StateCollection* GetConditions(xml_node<>* _parent, const char* _nodeName)
	{
		StateCollection* _conditions = new StateCollection();
		xml_node<>* _pre = _parent->first_node(_nodeName);
		for(xml_node<>* _stateCollection = _pre->first_node("States"); _stateCollection; _stateCollection = _stateCollection->next_sibling())
			for (xml_node<>* _state = _stateCollection->first_node("State"); _state; _state = _state->next_sibling())
			{
				bool* _b = new bool(_state->first_attribute("CurrentState")->value());
				State* _newState = new State(new string(_state->first_attribute("Name")->value()), _b);
				_conditions->AddState(_newState);
			}
		return _conditions;
	}

	/// <summary>
	/// Buffer data from source then return the bufferd data
	/// </summary>
	/// <param name="_fileName">File Path to Buffered Data</param>
	/// <returns>Buffered Data</returns>
	xml_document<T> ReadData(string* _fileName)
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
		readFile->append('\0');
		return readFile;
	}
private:

};