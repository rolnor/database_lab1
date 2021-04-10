// database_lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void menu();

class course_object_stack
{

};

class course_node
{
    private:
        course_node* next_course;
        string course_name;
        course_object_stack* active_course;
    public:
        ~course_node();
        course_node(course_node* nextnode);
        course_node(string input_name);
        void print();
};



int main()
{
    char choise = ' ';
    while (choise != '0')
    {
        menu();
        cin >> choise;
        switch (choise)
        {
            case '1':
                break;
            case '2':
                break;
            default:
                break;
        }
    }
}

/* 
    std::cout << "Hello World!\n";
    course_node HEAD("kalle");
    HEAD.print();
*/

course_node::~course_node()
{
   // delete student_name;
}

course_node::course_node(course_node* nextnode)
{
    next_course = nextnode;  
};

course_node::course_node(string input_name)
{
    next_course = nullptr;
    course_name = input_name;
}
void course_node::print()
{
    cout << this->course_name << endl;
}


void menu()
{
    cout << "1. Build an empty database" << endl;
    cout << "2. Insert a course application to the database" << endl;
    cout << "3. Delete a course application from the database." << endl;
    cout << "4. Print the contents of the database in the following form:" << endl;
    cout << "0. Exit." << endl;
    cout << "Enter choise: ";
}