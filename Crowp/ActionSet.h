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
protected:

private:
	vector<Action*> as_actionSet;
};