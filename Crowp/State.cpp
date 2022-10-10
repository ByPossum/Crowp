#include "State.h"

State::State(string _name, bool _currentState)
{
	s_name = &_name;
	b_currentState = &_currentState;
}

State::~State()
{
	delete s_name;
	delete b_currentState;
}