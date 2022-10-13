#include "ActionSet.h"

ActionSet::ActionSet() {}

ActionSet::ActionSet(Action _set[])
{
	for (int i = 0; i < sizeof(_set); i++)
	{
		as_actionSet[i] = &_set[i];
	}
}

ActionSet::ActionSet(Action* _set[])
{
	for (int i = 0; i < sizeof(_set); i++)
	{
		as_actionSet[i] = _set[i];
	}
}

ActionSet::~ActionSet()
{
	for (int i = 0; i < as_actionSet.size(); i++)
	{
		delete as_actionSet[i];
	}
}

void ActionSet::AddAction(Action* _newAction)
{
	as_actionSet.push_back(_newAction);
}

void ActionSet::RemoveAction(int _ind)
{
	Action* _deleteAction = as_actionSet[_ind];
	as_actionSet.erase(as_actionSet.begin() + _ind);
	delete _deleteAction;
}

void ActionSet::DebugActionSet()
{
	for (int i = 0; i < as_actionSet.size(); i++)
		as_actionSet[i]->DebugAction();
}

vector<Action*> ActionSet::GetActions()
{
	return as_actionSet;
}