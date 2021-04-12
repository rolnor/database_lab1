#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

class myStack
{
private:
	vector<string> students;
public:
	void push(string name);
	void pop();
	int empty();
	string top();
};
