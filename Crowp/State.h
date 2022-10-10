#pragma once
#include <string>

using namespace std;

class State
{
public:
	State(string _name, bool _currentState);
	~State();
protected:

private:
	string* s_name;
	bool* b_currentState;
};