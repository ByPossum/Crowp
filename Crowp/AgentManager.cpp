#include "AgentManager.h"

AgentManager::AgentManager()
{

}

AgentManager::AgentManager(string* _fileName)
{

}

AgentManager::~AgentManager()
{
	for (int i = 0; i < aV_agents.size(); i++)
		delete aV_agents[i];
}

void AgentManager::AddAgent(Agent* _newAgent)
{
	aV_agents.push_back(_newAgent);
}

void AgentManager::RemoveAgent(int _index)
{
	Agent* _toDelete = aV_agents[_index];
	aV_agents.erase(aV_agents.begin() + _index);
	delete _toDelete;
}

void AgentManager::LoadAgents()
{
	GenericReader<string>* _reader = new GenericReader<string>(s_filePath);
	for (const auto& entry : std::filesystem::directory_iterator(*s_filePath))
	{
		Agent* _newAgent = _reader->ReadAgent(entry.path().string());
		aV_agents.push_back(_newAgent);
	}
	delete _reader;
}

void AgentManager::SetFilePath(string* _fp)
{
	s_filePath = new string(*_fp + "\\Agents\\");
}

vector<Agent*> AgentManager::GetAgents()
{
	return aV_agents;
}