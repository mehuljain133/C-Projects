//Write a program to merge two ordered arrays to get a single ordered array.

#include <iostream>
using namespace std;

// Function to merge two ordered arrays into a single ordered array
void mergeArrays(int* arr1, int size1, int* arr2, int size2, int* mergedArr) {
    int i = 0, j = 0, k = 0;

    // Merge the arrays while both arrays have elements
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // If any elements remain in the first array
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // If any elements remain in the second array
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    // Input size and elements for the first array
    cout << "Enter the size of the first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter the elements of the first ordered array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // Input size and elements for the second array
    cout << "Enter the size of the second array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter the elements of the second ordered array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    // Create a merged array to store the result
    int mergedArr[size1 + size2];

    // Call the merge function
    mergeArrays(arr1, size1, arr2, size2, mergedArr);

    // Output the merged ordered array
    cout << "Merged ordered array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
