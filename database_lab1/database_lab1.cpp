// database_lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void menu();

class course_object_stack
{
    private:
        course_object_stack* next;
        string name;
    public:
        void push(string name);
        void pop();
        course_object_stack();
        ~course_object_stack();
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
    course_node* main_node = nullptr;

    while (choise != '0')
    {
        string input_name = "";
        menu();
        cin >> choise;
        switch (choise)
        {
            case '1':
                if (main_node == nullptr)
                {
                    cin >> input_name;
                    main_node = new course_node(input_name);
                }
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                if (main_node != nullptr)
                {

                    main_node->print();
                }
                break;
            default:
                break;
        }
    }
    delete main_node;
}

course_node::~course_node()
{
    delete this->active_course;
}

course_node::course_node(course_node* nextnode)
{
    next_course = nextnode;  
    active_course = new course_object_stack();
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

void course_object_stack::push(string name)
{
}

void course_object_stack::pop()
{
}

course_object_stack::course_object_stack()
{
    this->next = nullptr;
}

course_object_stack::~course_object_stack()
{
    if (this->next != nullptr)
        delete this->next;
}
