//Write a program that prints a table indicating the number of occurrences of each alphabet in the text entered as command line arguments

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to count occurrences of each alphabet in the text
void countOccurrences(int argc, char* argv[]) {
    int alphabetCount[26] = {0};  // Array to store count of each alphabet (A-Z)

    // Traverse through command line arguments
    for (int i = 1; i < argc; ++i) {
        string text = argv[i];

        // Traverse each character in the text
        for (char ch : text) {
            if (isalpha(ch)) {
                // Convert to lowercase and count the occurrence
                ch = tolower(ch);
                alphabetCount[ch - 'a']++;
            }
        }
    }

    // Print the table of occurrences
    cout << "Alphabet\tOccurrences" << endl;
    for (int i = 0; i < 26; ++i) {
        cout << char('a' + i) << "\t\t" << alphabetCount[i] << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide some text as command line arguments." << endl;
        return 1;
    }

    countOccurrences(argc, argv);

    return 0;
}
