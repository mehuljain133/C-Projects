//Programming Fundamentals: Data types, Variables, Operators, Expressions, Arrays,Keywords, Naming Convention, Decision making constructs (if, switch), Looping (for, while,do…while), Type Casting, Input-output statements, Functions, Command Line Arguments/Parameters
#include <iostream>
#include <string>
#include <cmath> // For mathematical expressions
#include <cstdlib> // For command line arguments handling
#include <limits>  // For numeric limits

using namespace std;

// Function prototypes
void demonstrateDataTypes();
void demonstrateOperators();
void demonstrateDecisionMaking();
void demonstrateLoops();
void demonstrateTypeCasting();
void demonstrateFunctionWithParameters(int argc, char* argv[]);
void demonstrateArrays();
void demonstrateCommandLineArguments(int argc, char* argv[]);

// Main function
int main(int argc, char* argv[]) {
    // Call functions to demonstrate various concepts
    cout << "Demonstrating Data Types and Variables:" << endl;
    demonstrateDataTypes();
    
    cout << "\nDemonstrating Operators:" << endl;
    demonstrateOperators();
    
    cout << "\nDemonstrating Decision Making Constructs:" << endl;
    demonstrateDecisionMaking();
    
    cout << "\nDemonstrating Loops:" << endl;
    demonstrateLoops();
    
    cout << "\nDemonstrating Type Casting:" << endl;
    demonstrateTypeCasting();
    
    cout << "\nDemonstrating Function with Parameters:" << endl;
    demonstrateFunctionWithParameters(argc, argv);
    
    cout << "\nDemonstrating Arrays:" << endl;
    demonstrateArrays();
    
    cout << "\nDemonstrating Command Line Arguments:" << endl;
    demonstrateCommandLineArguments(argc, argv);
    
    return 0;
}

// Function to demonstrate data types and variables
void demonstrateDataTypes() {
    int age = 30;                // Integer data type
    double height = 5.9;         // Double data type for floating-point numbers
    char gender = 'M';           // Character data type
    bool isStudent = false;      // Boolean data type
    string name = "Alice";       // String data type

    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Gender: " << gender << endl;
    cout << "Is Student: " << isStudent << endl;
    cout << "Name: " << name << endl;
}

// Function to demonstrate operators and expressions
void demonstrateOperators() {
    int a = 10, b = 20;
    int sum = a + b;
    int product = a * b;
    float division = (float) b / a;  // Type casting during division

    // Arithmetic operators
    cout << "Sum of a and b: " << sum << endl;
    cout << "Product of a and b: " << product << endl;
    cout << "Division of b by a: " << division << endl;

    // Relational operators
    if (a < b) {
        cout << "a is less than b" << endl;
    }

    // Logical operators
    if (a < b && b > 10) {
        cout << "Both conditions are true" << endl;
    }

    // Increment and Decrement operators
    cout << "Pre-increment of a: " << ++a << endl;
    cout << "Post-increment of b: " << b++ << " (value after increment: " << b << ")" << endl;
}

// Function to demonstrate decision making constructs (if, switch)
void demonstrateDecisionMaking() {
    int x = 15;

    // if-else construct
    if (x > 10) {
        cout << "x is greater than 10" << endl;
    } else {
        cout << "x is less than or equal to 10" << endl;
    }

    // switch-case construct
    switch (x) {
        case 10:
            cout << "x is 10" << endl;
            break;
        case 15:
            cout << "x is 15" << endl;
            break;
        default:
            cout << "x is neither 10 nor 15" << endl;
            break;
    }
}

// Function to demonstrate loops (for, while, do-while)
void demonstrateLoops() {
    cout << "For loop output: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "While loop output: ";
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    cout << "Do-while loop output: ";
    i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 5);
    cout << endl;
}

// Function to demonstrate type casting
void demonstrateTypeCasting() {
    double doubleValue = 9.99;
    int intValue = static_cast<int>(doubleValue); // Explicit type casting

    cout << "Original double value: " << doubleValue << endl;
    cout << "After type casting to int: " << intValue << endl;

    int a = 10;
    char charValue = static_cast<char>(a); // Casting an int to char

    cout << "Integer value: " << a << endl;
    cout << "After casting to char: " << charValue << endl;
}

// Function to demonstrate functions with parameters
void demonstrateFunctionWithParameters(int argc, char* argv[]) {
    cout << "Command-line Arguments: ";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << endl;
}

// Function to demonstrate arrays
void demonstrateArrays() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to demonstrate command line arguments
void demonstrateCommandLineArguments(int argc, char* argv[]) {
    if (argc > 1) {
        cout << "Command Line Arguments (excluding program name): ";
        for (int i = 1; i < argc; i++) {
            cout << argv[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No command-line arguments provided." << endl;
    }
}
