#pragma once
#include "Agent.h"
#include "GenericReader.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;
class AgentManager
{
public:
	AgentManager();
	AgentManager(string* _filePath);
	~AgentManager();
	void AddAgent(Agent* _newAgent);
	void RemoveAgent(int _index);
	void LoadAgents();
	void SetFilePath(string* _fp);
	vector<Agent*> GetAgents();
protected:

private:
	string* s_filePath;
	vector<Agent*> aV_agents;
};