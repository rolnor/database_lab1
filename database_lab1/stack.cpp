#include "mystack.h"


void myStack::push(string name)
{
	students.push_back(name);
}

void myStack::pop()
{
	students.pop_back();
}

int myStack::empty()
{
	if (students.size() == 0)
		return 1;
	else return 0;
}

string myStack::top()
{
	return students.back();
}
