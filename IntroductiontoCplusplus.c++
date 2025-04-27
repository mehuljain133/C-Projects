//ntroduction to C++: Overview of Procedural Programming and Object-Oriented Programming, Using main () function, Header Files, Compiling and Executing Simple Programs in C++. 
#include <iostream>
#include <string>
#include <memory> // For smart pointers
#include <vector> // For dynamic array operations

using namespace std;

// ---- Procedural Programming Section ----

// Function to greet a user with dynamic memory allocation
void greetProcedurally(const string& name) {
    // Using dynamic memory allocation (heap allocation)
    char* greeting = new char[100];
    sprintf(greeting, "Hello, %s! Welcome to Procedural Programming in C++.\n", name.c_str());
    cout << greeting;
    delete[] greeting;  // Don't forget to deallocate the memory
}

// ---- Object-Oriented Programming (OOP) Section ----

// Class definition for Greeter
class Greeter {
private:
    string name;
    int age;

public:
    // Default constructor
    Greeter() : name("Unknown"), age(0) {}

    // Parameterized constructor
    Greeter(const string& n, int a) : name(n), age(a) {}

    // Getter methods for encapsulation
    string getName() const { return name; }
    int getAge() const { return age; }

    // Method to greet using OOP
    void greet() const {
        cout << "Hello, " << name << " (" << age << " years old)! Welcome to Object-Oriented Programming in C++.\n";
    }

    // Method to update the name (demonstrating encapsulation)
    void updateName(const string& newName) {
        name = newName;
    }

    // Method to update the age
    void updateAge(int newAge) {
        age = newAge;
    }
};

// ---- Advanced OOP with Polymorphism ----

// Abstract base class
class AbstractGreeter {
public:
    virtual void greet() const = 0;  // Pure virtual function
    virtual ~AbstractGreeter() {}     // Virtual destructor
};

// Derived class implementing the abstract base class
class AdvancedGreeter : public AbstractGreeter {
private:
    string name;
    string customMessage;

public:
    // Constructor to initialize the greeter
    AdvancedGreeter(const string& n, const string& msg) : name(n), customMessage(msg) {}

    // Overridden greet method with polymorphism
    void greet() const override {
        cout << "Hello, " << name << "! " << customMessage << endl;
    }
};

// ---- Main Function ----
int main() {
    // Procedural approach
    string userName = "Alice";
    greetProcedurally(userName);  // Calling procedural function

    // Object-Oriented approach with multiple constructors
    Greeter greeter1;  // Default constructor
    Greeter greeter2("Bob", 25);  // Parameterized constructor
    greeter1.greet();
    greeter2.greet();

    // Demonstrate encapsulation by updating the object state
    greeter1.updateName("Charlie");
    greeter1.updateAge(30);
    greeter1.greet();  // After state update

    // Advanced OOP with polymorphism
    unique_ptr<AbstractGreeter> advancedGreeter = make_unique<AdvancedGreeter>("David", "Hope you're having a great day!");
    advancedGreeter->greet();  // Polymorphic call

    // Using vectors (dynamic arrays) to hold objects and demonstrate dynamic memory management
    vector<Greeter> greeters = { greeter1, greeter2 };
    for (const auto& greeter : greeters) {
        greeter.greet();  // Looping through and calling greet for each greeter
    }

    return 0;
}
