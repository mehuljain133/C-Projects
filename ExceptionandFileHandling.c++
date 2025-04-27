//Exception and File Handling: Using try, catch, throw, throws and finally; Nested try, creating user defined exceptions, File I/O Basics, File Operations. 

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

// User-defined exception class
class NegativeValueException : public exception {
public:
    const char* what() const noexcept override {
        return "Negative value is not allowed!";
    }
};

// Function to demonstrate throw, try, and catch with user-defined exception
void demonstrateExceptionHandling(int value) {
    try {
        if (value < 0) {
            throw NegativeValueException();  // Throw user-defined exception
        }
        cout << "Value is: " << value << endl;
    } catch (const NegativeValueException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}

// Nested try-catch example
void nestedTryCatch() {
    try {
        cout << "Entering outer try block." << endl;
        try {
            cout << "Entering inner try block." << endl;
            throw runtime_error("An error occurred in the inner block.");
        } catch (const runtime_error& e) {
            cout << "Caught in inner try-catch: " << e.what() << endl;
            throw;  // Rethrow the exception to be caught by outer catch
        }
    } catch (const runtime_error& e) {
        cout << "Caught in outer try-catch: " << e.what() << endl;
    }
}

// Function to demonstrate throwing exceptions and using finally-like behavior
void simulateFinally() {
    try {
        cout << "Executing try block." << endl;
        throw runtime_error("An error occurred in the try block.");
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    } finally {
        // Simulating finally using a cleanup block (no native finally in C++)
        cout << "Executing cleanup code (simulated finally block)." << endl;
    }
}

// File handling functions
void fileOperations() {
    // File writing
    ofstream outFile("example.txt");
    if (!outFile) {
        throw runtime_error("Failed to open the file for writing.");
    }
    outFile << "Hello, C++ File Handling!" << endl;
    outFile << "This is a simple demonstration of file I/O operations." << endl;
    outFile.close();  // Close the file after writing

    // File reading
    ifstream inFile("example.txt");
    if (!inFile) {
        throw runtime_error("Failed to open the file for reading.");
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();  // Close the file after reading
}

int main() {
    // Demonstrating exception handling with user-defined exception
    try {
        demonstrateExceptionHandling(-5);  // This will throw a NegativeValueException
        demonstrateExceptionHandling(10);  // This will print the value
    } catch (...) {
        cout << "Caught an unknown exception." << endl;
    }

    // Demonstrating nested try-catch
    nestedTryCatch();

    // Simulate a finally block (cleanup behavior)
    try {
        simulateFinally();
    } catch (...) {
        cout << "Caught an exception during the simulation." << endl;
    }

    // Demonstrating file handling
    try {
        fileOperations();
    } catch (const runtime_error& e) {
        cout << "File operation failed: " << e.what() << endl;
    }

    return 0;
}
