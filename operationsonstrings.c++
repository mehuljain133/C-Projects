/* Write a menu driven program to perform following operations on strings (without using
inbuilt string functions):
a) Show address of each character in string
b) Concatenate two strings.
c) Compare two strings
d) Calculate length of the string (use pointers)
e) Convert all lowercase characters to uppercase
f) Reverse the string */

#include <iostream>
using namespace std;

// Function to show address of each character in the string
void showAddresses(char* str) {
    while (*str != '\0') {
        cout << "Character: " << *str << " Address: " << (void*)str << endl;
        str++;
    }
}

// Function to concatenate two strings
void concatenateStrings(char* str1, char* str2) {
    while (*str1 != '\0') {
        str1++;
    }
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';  // Null-terminate the concatenated string
}

// Function to compare two strings
int compareStrings(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);  // If strings are identical, return 0, otherwise return non-zero value
}

// Function to calculate the length of a string using pointers
int calculateLength(char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

// Function to convert all lowercase characters to uppercase
void convertToUpper(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;  // Convert to uppercase
        }
        str++;
    }
}

// Function to reverse a string
void reverseString(char* str) {
    char* start = str;
    char* end = str;
    
    // Move end pointer to the last character
    while (*end != '\0') {
        end++;
    }
    end--;  // Now, end points to the last valid character

    // Swap characters from start and end until start and end meet
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    char str1[100], str2[100];
    int choice;

    while (true) {
        cout << "\nMenu: \n";
        cout << "1. Show address of each character in a string\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of a string\n";
        cout << "5. Convert all lowercase characters to uppercase\n";
        cout << "6. Reverse a string\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin >> str1;
                showAddresses(str1);
                break;
            case 2:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                concatenateStrings(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;
            case 3:
                cout << "Enter first string: ";
                cin >> str1;
                cout << "Enter second string: ";
                cin >> str2;
                int result = compareStrings(str1, str2);
                if (result == 0) {
                    cout << "Strings are equal." << endl;
                } else {
                    cout << "Strings are not equal. Difference: " << result << endl;
                }
                break;
            case 4:
                cout << "Enter a string: ";
                cin >> str1;
                cout << "Length of the string: " << calculateLength(str1) << endl;
                break;
            case 5:
                cout << "Enter a string: ";
                cin >> str1;
                convertToUpper(str1);
                cout << "String after conversion to uppercase: " << str1 << endl;
                break;
            case 6:
                cout << "Enter a string: ";
                cin >> str1;
                reverseString(str1);
                cout << "Reversed string: " << str1 << endl;
                break;
            case 7:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
