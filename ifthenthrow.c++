// Write a program to read two numbers p and q. If q is 0 then throw an exception elsedisplay the result of p/q

#include <iostream>
using namespace std;

// Exception class to handle division by zero
class DivisionByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Division by zero is not allowed!";
    }
};

int main() {
    float p, q;

    // Input two numbers p and q
    cout << "Enter two numbers (p and q): ";
    cin >> p >> q;

    try {
        // Throw an exception if q is 0
        if (q == 0) {
            throw DivisionByZeroException();
        }

        // Display the result of p / q
        cout << "Result: " << p / q << endl;
    }
    catch (const DivisionByZeroException& e) {
        // Catch the exception and display the error message
        cout << e.what() << endl;
    }

    return 0;
}
