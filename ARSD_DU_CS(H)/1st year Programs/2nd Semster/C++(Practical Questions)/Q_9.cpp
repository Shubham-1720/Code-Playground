#include <iostream>
using namespace std;

class Person
{

public:
    string name;
    void setData(void)
    {
        cout<<"Enter your name: "<<endl;
        cin>>name;
    }
    void display(void)
    {
        cout << "Your name is: " << name << endl;
    }
};

class Student : public Person
{
public:
    string course;
    int marks, year;

    void setData(void)
    {
        cout << "Enter your name: " << endl;
        cin >> name;
        cout << "Enter your course: " << endl;
        cin >> course;
        cout << "Enter your marks: " << endl;
        cin >> marks;
        cout << "Enter your year: " << endl;
        cin >> year;
    }

    void display()
    {
        cout << "Your name: " << name << endl
             << "Course: " << course << endl
             << "Marks: " << marks << endl
             << "Year: " << year << endl;
    }
};

class Employee : public Person
{
public:
    string department;
    int salary;

    void setData(void)
    {
        cout << "Enter your name: " << endl;
        cin >> name;
        cout << "Enter your department: " << endl;
        cin >> department;
        cout << "Enter your salary: " << endl;
        cin >> salary;
    }
    void display()
    {
        cout << "Your name: " << name << endl
             << "Department: " << department << endl
             << "Salary: " << salary << endl;
    }
};

int main()
{
    // Have to show runtime polymorphism in question
    // decalring pointer for the class person
    Person *person_ptr;
    // creating object of the class person
    // Person shubham;
    // referencing the object shubham with pointer person_ptr
    // person_ptr = &shubham;
    // (*person_ptr).name = "shubham";
    // person_ptr->display();
    // creating a object of the class student
    Student ankit;
    // referencing the object ankit with pointer of the class person
    person_ptr  = &ankit;
    (*person_ptr).setData();
    person_ptr->display();
    // the above segment instead of being object of student class it is invoking methods and variable of person class because pointer is of person class.
    // if we want to use method and variable of student class we have to make functions of person class virtual

    // person_ptr  = &ankit;
    // (*person_ptr).setData();
    // person_ptr->display();

   // same will work for employee 
   // in this is process decision of which function is to be executed is taking place at run time so called runtime polymorphism


    return 0;
}