// Copy the contents of one text file to another file, after removing all whitespaces.

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    // Open the source file in read mode
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Open the destination file in write mode
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    char ch;
    // Read each character from the input file
    while (inputFile.get(ch)) {
        // Check if the character is not a whitespace
        if (!isspace(ch)) {
            outputFile.put(ch);  // Write the character to the output file
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Contents copied to output.txt after removing all whitespaces." << endl;

    return 0;
}
