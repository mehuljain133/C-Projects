// Write a program to calculate GCD of two numbers (i) with recursion (ii) without recursion. 

#include <iostream>
using namespace std;

// GCD with recursion (Euclidean algorithm)
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

// GCD without recursion (Euclidean algorithm)
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, choice;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose the GCD method:\n";
    cout << "1. GCD (Recursive)\n";
    cout << "2. GCD (Iterative)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int result;
    if (choice == 1) {
        result = gcdRecursive(num1, num2);
    } else if (choice == 2) {
        result = gcdIterative(num1, num2);
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
