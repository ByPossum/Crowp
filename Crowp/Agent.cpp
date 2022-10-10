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

Agent::~Agent()
{
	delete s_agentName;
	delete as_actions;
	for (int i = 0; i < sizeof(scV_goals); i++)
		delete scV_goals[i];
}