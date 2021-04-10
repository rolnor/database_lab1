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
        course_object_stack* push(string name);
        void print();
        course_object_stack* getNext();
        void setNext();
        course_object_stack(string name, course_object_stack* next_node);
        ~course_object_stack();
};


class course_node
{
    private:
        course_node* next_course;
        string course_name;
        course_object_stack* students;
        course_object_stack* search_students;
    public:
        ~course_node();
        course_node(course_node* nextnode);
        course_node(string input_name);
        course_object_stack* pop();
        string getCourseName();
        course_node* getNext();
        void addStudent(string name);
        void print();
};



int main()
{
    char choise = ' ';
    course_node* main_node = nullptr;
    course_node* course_traverser = nullptr;
    string inputString = "";

    course_object_stack* poppedItem = nullptr;

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
                cout << "Enter course name: ";
                cin >> inputString;
                course_traverser = main_node;
                while (course_traverser != nullptr)
                {
                    if (course_traverser->getCourseName() == inputString)
                    {
                        cout << "Course found. Enter name: ";
                        cin >> inputString;
                        course_traverser->addStudent(inputString);
                        course_traverser = nullptr;
                    }
                    else
                    {
                        course_traverser = course_traverser->getNext();
                    }
                    
                }
                break;
            case '3':
                // todo switch main node and fix nullptr pop crash
                poppedItem = main_node->pop();
                delete poppedItem;
                break;
            case '4':
                if (main_node != nullptr)
                {
                    main_node->print();
                    cout << endl << endl;
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
    delete this->students;
    delete this->search_students;
}

course_node::course_node(course_node* nextnode)
{
    next_course = nextnode;  
    students = nullptr;
    search_students = nullptr;
};

course_node::course_node(string input_name)
{
    next_course = nullptr;
    course_name = input_name;
}
course_object_stack* course_node::pop()
{
    course_object_stack* poppedItem = this->students;
    this->students = poppedItem->getNext();
    poppedItem->setNext();
    return poppedItem;
}
string course_node::getCourseName()
{
    return this->course_name;
}
course_node* course_node::getNext()
{
    return this->next_course;
}
void course_node::addStudent(string name)
{
    this->students = this->students->push(name);
}
void course_node::print()
{
    cout << this->course_name << ": ";
    this->students->print();
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

course_object_stack* course_object_stack::push(string name)
{
    course_object_stack* new_student = new course_object_stack(name, this);
    return new_student;
}


void course_object_stack::print()
{
    course_object_stack* traverser = this;
    while(traverser != nullptr)
    {
        cout << traverser->name << " ";
        traverser = traverser->next;
    }
}

course_object_stack* course_object_stack::getNext()
{
    return this->next;
}

void course_object_stack::setNext()
{
    this->next = nullptr;
}

course_object_stack::course_object_stack(string name, course_object_stack* next_node )
{
    this->name = name;
    this->next = next_node;
}

course_object_stack::~course_object_stack()
{
    if (this->next != nullptr)
        delete this->next;
}
