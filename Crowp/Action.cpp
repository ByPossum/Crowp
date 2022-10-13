#include "Action.h"

Action::Action(string _name, StateCollection _pre, StateCollection _post)
{
	s_name = &_name;
	sc_precondition = &_pre;
	sc_postCondition = &_post;
}

Action::Action(string* _name, StateCollection* _pre, StateCollection* _post)
{
	s_name = _name;
	sc_precondition = _pre;
	sc_postCondition = _post;
}

Action::~Action()
{
	delete s_name;
	delete sc_precondition;
	delete sc_postCondition;
}

void Action::DebugAction()
{
	cout << *s_name << endl;
	cout << "PreConditions:" << endl;
	for (int i = 0; i < sc_precondition->GetStates().size(); i++)
		cout << sc_precondition->GetStates()[i]->GetName() << endl;
	cout << "PostConditions:" << endl;
	for (int i = 0; i < sc_postCondition->GetStates().size(); i++)
		cout << sc_postCondition->GetStates()[i]->GetName() << endl;
}

string Action::Name()
{
	return *s_name;
}