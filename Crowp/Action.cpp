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