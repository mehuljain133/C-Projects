//Pointers and References: Static and dynamic memory allocation, Pointer and ReferenceVariables, Pointers vs. References, Implementing Runtime polymorphism using pointers andreferences.

#include <iostream>
#include <string>

using namespace std;

// Base class to demonstrate runtime polymorphism
class Animal {
public:
    // Virtual function to be overridden by derived classes
    virtual void sound() {
        cout << "Animal makes a sound." << endl;
    }

    // Virtual destructor
    virtual ~Animal() {}
};

// Derived class to demonstrate runtime polymorphism
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows!" << endl;
    }
};

// Demonstrating Static and Dynamic Memory Allocation
void demonstrateMemoryAllocation() {
    // Static memory allocation (on the stack)
    int staticVar = 10;
    cout << "Static variable: " << staticVar << endl;

    // Dynamic memory allocation (on the heap)
    int* dynamicVar = new int(20); // Dynamically allocated integer
    cout << "Dynamically allocated variable: " << *dynamicVar << endl;

    // Clean up dynamically allocated memory
    delete dynamicVar;
}

// Demonstrating Pointers and References
void demonstratePointersAndReferences() {
    int num = 42;

    // Pointer to an integer
    int* pointerVar = &num;

    // Reference to an integer
    int& referenceVar = num;

    cout << "Original number: " << num << endl;
    cout << "Pointer to number: " << *pointerVar << endl;
    cout << "Reference to number: " << referenceVar << endl;

    // Modifying through pointer and reference
    *pointerVar = 100;
    referenceVar = 200;

    cout << "After modifications: " << endl;
    cout << "Original number: " << num << endl;
    cout << "Pointer to number: " << *pointerVar << endl;
    cout << "Reference to number: " << referenceVar << endl;
}

// Function to demonstrate pointers vs references
void pointersVsReferences() {
    int a = 10;
    int b = 20;

    // Pointer to an integer
    int* ptr = &a;

    // Reference to an integer
    int& ref = b;

    // Using pointer to change value
    *ptr = 30;

    // Using reference to change value
    ref = 40;

    cout << "Using pointer: a = " << a << endl;  // 30
    cout << "Using reference: b = " << b << endl;  // 40
}

// Implementing Runtime Polymorphism using Pointers and References
void demonstratePolymorphism() {
    // Using pointers to demonstrate polymorphism
    Animal* animalPtr;
    Dog dog;
    Cat cat;

    animalPtr = &dog;
    animalPtr->sound();  // Calls Dog's sound()

    animalPtr = &cat;
    animalPtr->sound();  // Calls Cat's sound()

    // Using references to demonstrate polymorphism
    Animal& animalRef = dog;
    animalRef.sound();  // Calls Dog's sound()

    Animal& animalRef2 = cat;
    animalRef2.sound();  // Calls Cat's sound()
}

int main() {
    // Demonstrate Static and Dynamic Memory Allocation
    demonstrateMemoryAllocation();

    // Demonstrate Pointers and References
    demonstratePointersAndReferences();

    // Demonstrate Pointers vs References
    pointersVsReferences();

    // Demonstrate Runtime Polymorphism using Pointers and References
    demonstratePolymorphism();

    return 0;
}
