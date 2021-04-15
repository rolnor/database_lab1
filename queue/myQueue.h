#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

class myQueue
{
private:
	vector<string> students;
public:
	void push(string name);
	void erasefirstInLine();
	int empty();
	string firstInLine();
};
