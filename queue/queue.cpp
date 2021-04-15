#include "myQueue.h"


void myQueue::push(string name)
{
	students.insert(students.begin(),name);
}

void myQueue::pop()
{
	students.erase(students.begin());
}

int myQueue::empty()
{
	if (students.size() == 0)
		return 1;
	else return 0;
}

string myQueue::top()
{
	return students.front();
}

