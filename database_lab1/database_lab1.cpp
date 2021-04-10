// database_lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class course_node
{
    private:
        course_node* next;
        string student_name;
    public:
        ~course_node();
        course_node(course_node* nextnode);
        course_node(string input_name);
        void print();
};

int main()
{
    std::cout << "Hello World!\n";
    course_node HEAD("kalle");
    HEAD.print();
}

course_node::~course_node()
{
   // delete student_name;
}

course_node::course_node(course_node* nextnode)
{
    next = nextnode;  
};

course_node::course_node(string input_name)
{
    next = nullptr;
    student_name = input_name;
}
void course_node::print()
{
    cout << this->student_name << endl;
}
;