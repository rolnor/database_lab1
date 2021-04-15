#include "myQueue.h"


void myQueue::push(string name)
{
	students.insert(students.end(),name);
}

void myQueue::erasefirstInLine()
{
	students.erase(students.begin());
}

int myQueue::empty()
{
	if (students.size() == 0)
		return 1;
	else return 0;
}

string myQueue::firstInLine()
{
	return students.front();
}

