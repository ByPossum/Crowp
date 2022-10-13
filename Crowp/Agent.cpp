#include "Agent.h"

Agent::Agent()
{
	s_agentName = new string("Empty Agent");
	as_actions = new ActionSet();
}

Agent::Agent(string _name, StateCollection _goals[], ActionSet _actions)
{
	s_agentName = &_name;
	as_actions = &_actions;
	for (int i = 0; i < sizeof(_goals); i++)
		scV_goals.push_back(&_goals[i]);
}

Agent::Agent(string* _name, vector<StateCollection*> _goals, ActionSet* _actions)
{
	s_agentName = _name;
	as_actions = _actions;
	scV_goals = _goals;
}

Agent::~Agent()
{
	delete s_agentName;
	delete as_actions;
	if(scV_goals.size() > 0)
		for (int i = 0; i < scV_goals.size(); i++)
			delete scV_goals[i];
}

void Agent::DebugAgent()
{
	cout << *s_agentName << endl;
	as_actions->DebugActionSet();
	cout << "Goals:" << endl;
	for (int i = 0; i < scV_goals.size(); i++)
		for (int j = 0; j < scV_goals[i]->GetStates().size(); j++)
			cout << scV_goals[i]->GetStates()[j]->GetName() << endl;
}

string Agent::Name()
{
	return *s_agentName;
}

ActionSet* Agent::GetActions()
{
	return as_actions;
}

vector<StateCollection*> Agent::GetStates()
{
	return scV_goals;
}