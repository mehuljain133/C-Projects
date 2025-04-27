// Create a class Triangle. Include overloaded functions for calculating area. Overload assignment operator and equality operator.

#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;

public:
    // Constructor to initialize name
    Person(string n) : name(n) {}

    // Virtual function for runtime polymorphism
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

// Derived class Student from Person
class Student : public Person {
private:
    string course;
    float marks;
    int year;

public:
    // Constructor to initialize Student specific attributes
    Student(string n, string c, float m, int y) : Person(n), course(c), marks(m), year(y) {}

    // Override display method to show Student specific attributes
    void display() override {
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class Employee from Person
class Employee : public Person {
private:
    string department;
    float salary;

public:
    // Constructor to initialize Employee specific attributes
    Employee(string n, string d, float s) : Person(n), department(d), salary(s) {}

    // Override display method to show Employee specific attributes
    void display() override {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // Creating objects of Student and Employee
    Person* p1 = new Student("John Doe", "Computer Science", 90.5, 2023);
    Person* p2 = new Employee("Jane Smith", "HR", 55000);

    // Showing runtime polymorphism
    cout << "Student Information:" << endl;
    p1->display();  // Calls Student's display

    cout << "\nEmployee Information:" << endl;
    p2->display();  // Calls Employee's display

    // Clean up memory
    delete p1;
    delete p2;

    return 0;
}
