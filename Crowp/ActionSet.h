#pragma once
#include "Action.h"
#include <vector>

using namespace std;

class ActionSet
{
public:
	ActionSet();
	ActionSet(Action _actions[]);
	ActionSet(Action* _actions[]);
	~ActionSet();
	void DebugActionSet();
	void AddAction(Action* _action);
	void RemoveAction(int _ind);
	vector<Action*> GetActions();
protected:

private:
	vector<Action*> as_actionSet;
};