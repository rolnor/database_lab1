// palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "myTimer.h"
#include <string>
#include <stack>
#include <queue>
#include <algorithm>



using namespace std;

void menu();


class palindromeCheckerQueue
{
private:
    queue<char> inputQueue;
public:
    void push(string inputString);
    int check(string inputString);
};


class palindromeCheckerStack
{
private:
    stack<char> inputStack;
public:
    void push(string inputString);
    int check(string inputString);
};



int main()
{
    string inputString;
    palindromeCheckerStack myStack;
    palindromeCheckerQueue myQueue;
    myTimer timeKeeper;

    cout << inputString;

    char choise = ' ';


    while (choise != '0')
    {
        cout << endl << "Enter string to check" << endl;
        cin.ignore();
        getline(cin, inputString);

        inputString.erase(remove(inputString.begin(), inputString.end(), ' '), inputString.end());
        menu();
        cin >> choise;

        switch(choise)
        { 
            case '1':
                cout << "stack"; 
                timeKeeper.start();
                myStack.push(inputString);
                cout << endl << myStack.check(inputString);
                timeKeeper.stop("Stack time");
                break;
            case '2':
                cout << "queue";
                timeKeeper.start();
                myQueue.push(inputString);
                cout << endl << myQueue.check(inputString);
                timeKeeper.stop("Queue time");
                break;
            default:
                break;
        }
    }
    return 0;
}

void menu()
{
    cout << endl << "1. Check palindrome with stack." << endl;
    cout << "2. Check palindrome with queue." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter choise: ";
}

void palindromeCheckerQueue::push(string inputString)
{
    while (!inputQueue.empty())
        inputQueue.pop();

    int size = inputString.length();
    while(size >= 0)
    {
        if(inputString[size] != '\0')
            inputQueue.push(inputString[size]);
        size--;
    }
}

int palindromeCheckerQueue::check(string inputString)
{
    for (char myChar : inputString)
    {
        if (tolower(myChar) != tolower(inputQueue.front()))
            return 0;
        else
            inputQueue.pop();
    }
    return 1;
}

void palindromeCheckerStack::push(string inputString)
{
    while (!inputStack.empty())
        inputStack.pop();

    for(char myChar : inputString)
    {
        inputStack.push(myChar);
    }
}
int palindromeCheckerStack::check(string inputString)
{
    for (char myChar : inputString)
    {
        if (tolower(myChar) != tolower(inputStack.top()))
            return 0;
        else
            inputStack.pop();
    }
    return 1;
}

