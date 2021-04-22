#include "mystack.h"
#include "myTimer.h"

void menu();
void palindrome();

class course_node
{
private:
    course_node* next_course;
    string course_name;
    myStack students;
    myStack temp_queue_students;
public:
    ~course_node();
    course_node(course_node* nextnode);
    course_node(string input_name);
    string getCourseName();
    course_node* getNext();
    void addNode(string inputString, string nameString);
    void setNodeName(string inputString);
    void addStudent(string name);
    void removeStudent(string name);
    void print();

};



int main()
{   
    myTimer myTimer;
    char choise = ' ';
    course_node* main_node = nullptr;
    course_node* course_traverser = nullptr;
    string inputString = "";
    string nameString = "";

    while (choise != '0')
    {
        string input_name = "";
        menu();
        cin >> choise;
        switch (choise)
        {
        case '1':
            myTimer.start();
            if (main_node == nullptr)
            {
                main_node = new course_node("");
                cout << "Empty Db Created" << endl;
            }
            myTimer.stop("Create db: ");
            break;
        case '2':
            cout << "Enter course name: ";
            cin >> inputString;
            cout << "Enter name: ";
            cin >> nameString;
            myTimer.start();
            course_traverser = main_node;
            while (course_traverser != nullptr)
            {
                if (course_traverser->getCourseName() == inputString || course_traverser->getCourseName() == "")
                {
                    if (course_traverser->getCourseName() == "")
                        course_traverser->setNodeName(inputString);

                    course_traverser->addStudent(nameString);
                    course_traverser = nullptr;
                }
                else
                {
                    if(course_traverser->getNext() != nullptr)
                        course_traverser = course_traverser->getNext();
                    else
                    {
                        course_traverser->addNode(inputString, nameString);    
                        course_traverser = nullptr;
                    }
                }
            }
            myTimer.stop("Insert student: ");
            break;
        case '3':
            cout << "Enter course name: ";
            cin >> inputString;
            cout << "Enter name: ";
            cin >> nameString;
            myTimer.start();
            course_traverser = main_node;
            while (course_traverser != nullptr)
            {
                if (course_traverser->getCourseName() == inputString)
                {
                    course_traverser->removeStudent(nameString);
                    break;
                }
                else
                {
                    course_traverser = course_traverser->getNext();
                }
            }
            myTimer.stop("Remove student: ");
            break;
        case '4':
            myTimer.start();
            if (main_node != nullptr)
            {
                course_traverser = main_node;
                while (course_traverser != nullptr)
                {
                    course_traverser->print();
                    course_traverser = course_traverser->getNext();
                }
                cout << endl << endl;
            }
            myTimer.stop("Print: ");
            break;
        case '5':
            palindrome();
            break;
        case '0':
            break;
        default:
            cout << "Guru meditation." << endl;
            break;
        }
    }
    delete main_node;
}

course_node::~course_node()
{
    if (this->next_course != nullptr)
        delete this->next_course;
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


string course_node::getCourseName()
{
    return this->course_name;
}

course_node* course_node::getNext()
{
    return this->next_course;
}

void course_node::addNode(string inputString, string nameString)
{
    course_node* traverser;
    this->next_course = new course_node(inputString);
    traverser = this->next_course;
    traverser->addStudent(nameString);
}

void course_node::setNodeName(string inputString)
{
    this->course_name = inputString;
}

void course_node::addStudent(string name)
{
    students.push(name);
}

void course_node::removeStudent(string name)
{
    while (!this->students.empty())
    {
        if (this->students.top() == name)
        {
            this->students.pop();
            break;
        }
        else
        {
            this->temp_queue_students.push(this->students.top());
            this->students.pop();
        }
    }

    while (!this->temp_queue_students.empty())
    {
        this->students.push(this->temp_queue_students.top());
        this->temp_queue_students.pop();
    }
}

void course_node::print()
{
    cout << endl << this->course_name << ": ";
    while (!this->students.empty())
    {
        cout << this->students.top() << " ";
        this->temp_queue_students.push(this->students.top());
        this->students.pop();
    }
    while (!this->temp_queue_students.empty())
    {
        this->students.push(this->temp_queue_students.top());
        this->temp_queue_students.pop();
    }
}



void menu()
{
    cout << endl << "1. Build an empty database" << endl;
    cout << "2. Insert a course application to the database" << endl;
    cout << "3. Delete a course application from the database." << endl;
    cout << "4. Print the contents of the database in the following form:" << endl;
    cout << "0. Exit." << endl;
    cout << "Enter choise: ";
}