#include "mystack.h"
#include "myTimer.h"

void menu();


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
    void addStudent(string name);
    void removeStudent(string name);
    void print();
    myTimer myTimer;
};

int main()
{
    char choise = ' ';
    course_node* main_node = nullptr;
    course_node* course_traverser = nullptr;
    string inputString = "";

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
            cout << "Enter course name: ";
            cin >> inputString;
            course_traverser = main_node;
            while (course_traverser != nullptr)
            {
                if (course_traverser->getCourseName() == inputString)
                {

                    cout << "Course found. Enter name: ";
                    cin >> inputString;
                    course_traverser->removeStudent(inputString);
                    break;
                }
                else
                {
                    course_traverser = course_traverser->getNext();
                }
            }
            break;
        case '4':
            if (main_node != nullptr)
            {
                main_node->print();
                cout << endl << endl;
            }
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

void course_node::addStudent(string name)
{
    students.push(name);
}

void course_node::removeStudent(string name)
{
    auto i_start = std::chrono::system_clock::now();

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
    auto i_end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = i_end - i_start;
    std::cout << "remove : " << elapsed.count() << "s";
}

void course_node::print()
{
    myTimer.start();
    cout << this->course_name << ": ";
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
    myTimer.stop("Print");
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