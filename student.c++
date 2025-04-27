// Create a class Student containing fields for Roll No., Name, Class, Year and TotalMarks. Write a program to store 5 objects of Student class in a file. Retrieve these recordsfrom file and display them.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student class definition
class Student {
private:
    int rollNo;
    string name;
    string studentClass;
    int year;
    float totalMarks;

public:
    // Constructor to initialize student attributes
    Student(int r = 0, string n = "", string c = "", int y = 0, float t = 0.0)
        : rollNo(r), name(n), studentClass(c), year(y), totalMarks(t) {}

    // Function to input student data
    void inputStudentData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();  // To clear the input buffer

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Class: ";
        getline(cin, studentClass);

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    // Function to display student data
    void displayStudentData() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "------------------------" << endl;
    }

    // Function to write student data to a file
    void writeToFile(ofstream& outFile) const {
        outFile.write(reinterpret_cast<const char*>(&rollNo), sizeof(rollNo));
        outFile.write(name.c_str(), name.size() + 1);
        outFile.write(studentClass.c_str(), studentClass.size() + 1);
        outFile.write(reinterpret_cast<const char*>(&year), sizeof(year));
        outFile.write(reinterpret_cast<const char*>(&totalMarks), sizeof(totalMarks));
    }

    // Function to read student data from a file
    void readFromFile(ifstream& inFile) {
        char buffer[100];

        inFile.read(reinterpret_cast<char*>(&rollNo), sizeof(rollNo));
        inFile.getline(buffer, sizeof(buffer), '\0');
        name = string(buffer);

        inFile.getline(buffer, sizeof(buffer), '\0');
        studentClass = string(buffer);

        inFile.read(reinterpret_cast<char*>(&year), sizeof(year));
        inFile.read(reinterpret_cast<char*>(&totalMarks), sizeof(totalMarks));
    }
};

int main() {
    Student students[5];

    // Input data for 5 students
    cout << "Enter details for 5 students:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << endl;
        students[i].inputStudentData();
    }

    // Store student data in a file
    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        students[i].writeToFile(outFile);
    }
    outFile.close();

    // Retrieve and display student data from the file
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return 1;
    }

    cout << "\nRetrieved Student Data from file:\n";
    Student tempStudent;
    for (int i = 0; i < 5; i++) {
        tempStudent.readFromFile(inFile);
        tempStudent.displayStudentData();
    }

    inFile.close();
    return 0;
}
