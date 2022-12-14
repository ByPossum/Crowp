#pragma once
#include "ActionSet.h"
#include "StateCollection.h"
#include <vector>
#include <string>


using namespace std;

class Agent
{
public:
	Agent();
	Agent(string _name, vector<StateCollection> _goals, ActionSet _actions);
	Agent(string _name, StateCollection _goals[], ActionSet _actions);
	Agent(string* _name, vector<StateCollection*> _goals, ActionSet* _actions);
	Agent(string* _name, StateCollection* _goals[], ActionSet _actions);
	~Agent();
	void DebugAgent();
	void RemoveAction(int _index);
	void RemoveGoal(int _index);
	ActionSet* GetActions();
	vector<StateCollection*> GetStates();

	string Name();
protected:

private:
	string* s_agentName;
	vector<StateCollection*> scV_goals;
	ActionSet* as_actions;
};