#include "StateCollection.h"

StateCollection::StateCollection() {}

StateCollection::StateCollection(State _state[], int _stateSize)
{
	for (int i = 0; i < sizeof(_state); i++)
		sV_states.push_back(&_state[i]);
}

StateCollection::~StateCollection()
{
	for (int i = 0; i < sV_states.size(); i++)
		delete sV_states[i];
}

void StateCollection::AddState(State* _newState)
{
	sV_states.push_back(_newState);
}

vector<State*> StateCollection::GetStates()
{
	return sV_states;
}