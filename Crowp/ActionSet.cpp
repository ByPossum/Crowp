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