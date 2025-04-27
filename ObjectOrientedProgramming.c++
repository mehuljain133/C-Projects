//Object Oriented Programming: Overview of Abstraction, Encapsulation, Inheritance, and Polymorphism. Creating Classes and objects, Modifiers and Access Control, Constructors,Implementation of Inheritance (Single and multilevel), Implementation of Polymorphism(Function Overloading and Operator Overloading, Function Overriding). 

#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class (Demonstrating Abstraction)
class Shape {
public:
    // Pure virtual function for calculating area (abstract method)
    virtual double calculateArea() = 0;

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Shape() {}

    // General function to display a shape type (Abstraction)
    void displayShapeType() {
        cout << "I am a shape!" << endl;
    }
};

// Encapsulation and Inheritance Example (Single Inheritance)
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Constructor to initialize width and height
    Rectangle(double w, double h) : width(w), height(h) {}

    // Function to calculate the area of the rectangle (Override)
    double calculateArea() override {
        return width * height;
    }

    // Function to display rectangle details
    void display() {
        cout << "Rectangle: Width = " << width << ", Height = " << height << endl;
    }
};

// Inheritance Example (Multilevel Inheritance)
class ColoredRectangle : public Rectangle {
private:
    string color;

public:
    // Constructor to initialize width, height, and color
    ColoredRectangle(double w, double h, const string& c) : Rectangle(w, h), color(c) {}

    // Override the display function to include color
    void display() override {
        Rectangle::display();  // Call the base class display method
        cout << "Color: " << color << endl;
    }
};

// Polymorphism Example (Function Overloading)
class Calculator {
public:
    // Function Overloading: Adding two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function Overloading: Adding three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function Overloading: Adding two floating-point numbers
    double add(double a, double b) {
        return a + b;
    }
};

// Operator Overloading Example
class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor to initialize complex number
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Overload the '+' operator to add two complex numbers
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // Function to display the complex number
    void display() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

// Function Overriding Example
class Base {
public:
    // Virtual function to be overridden
    virtual void show() {
        cout << "Base class show function" << endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    // Override the base class show function
    void show() override {
        cout << "Derived class show function" << endl;
    }
};

int main() {
    // Demonstrating Abstraction: Using Shape class (cannot create object directly due to pure virtual function)
    Shape* shapePtr;
    Rectangle rect(5, 10);   // Create a Rectangle object
    shapePtr = &rect;
    shapePtr->displayShapeType();
    cout << "Area of Rectangle: " << shapePtr->calculateArea() << endl;

    // Demonstrating Inheritance (Single and Multilevel)
    ColoredRectangle coloredRect(4, 6, "Red");
    coloredRect.display();
    cout << "Area of Colored Rectangle: " << coloredRect.calculateArea() << endl;

    // Demonstrating Function Overloading (Polymorphism)
    Calculator calc;
    cout << "Sum of 5 and 10: " << calc.add(5, 10) << endl;
    cout << "Sum of 5, 10, and 15: " << calc.add(5, 10, 15) << endl;
    cout << "Sum of 5.5 and 10.5: " << calc.add(5.5, 10.5) << endl;

    // Demonstrating Operator Overloading
    ComplexNumber num1(3, 4), num2(1, 2);
    ComplexNumber sum = num1 + num2;  // Using overloaded operator
    cout << "Sum of complex numbers: ";
    sum.display();

    // Demonstrating Function Overriding
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;
    basePtr->show();  // Calls Derived's show() due to overriding

    return 0;
}
