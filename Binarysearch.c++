//Write a program to search a given element in a set of N numbers using Binary search (i) with recursion (ii) without recursion. 

#include <iostream>
using namespace std;

// Binary search with recursion
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is smaller, search in the left half
        else if (arr[mid] > target) {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
        // If the target is larger, search in the right half
        else {
            return binarySearchRecursive(arr, mid + 1, right, target);
        }
    }
    return -1;  // Element not found
}

// Binary search without recursion
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is smaller, search in the left half
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is larger, search in the right half
        else {
            left = mid + 1;
        }
    }
    return -1;  // Element not found
}

int main() {
    int n, target, choice;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> target;

    cout << "Choose the search method:\n";
    cout << "1. Binary Search (Recursive)\n";
    cout << "2. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int result;
    if (choice == 1) {
        result = binarySearchRecursive(arr, 0, n - 1, target);
    } else if (choice == 2) {
        result = binarySearchIterative(arr, n, target);
    } else {
        cout << "Invalid choice!\n";
        return 0;
    }

    if (result == -1) {
        cout << "Element not found in the array.\n";
    } else {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}
