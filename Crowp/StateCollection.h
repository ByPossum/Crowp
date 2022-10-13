#pragma once
#include "State.h"
#include <iostream>
#include <vector>


class  StateCollection
{
public:
	StateCollection();
	 StateCollection(State _states[], int _stateSize);
	~StateCollection();
	void AddState(State* _state);
	vector<State*> GetStates();
protected:

private:
	vector<State*> sV_states;
};