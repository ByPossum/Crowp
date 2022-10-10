#pragma once
#include "StateCollection.h"
#include <string>

using namespace std;

class Action
{
public:
	Action(string _name, StateCollection _pre, StateCollection _post);
	Action(string* _name, StateCollection* _pre, StateCollection* _post);
	~Action();
protected:

private:
	string* s_name;
	StateCollection* sc_precondition;
	StateCollection* sc_postCondition;
};