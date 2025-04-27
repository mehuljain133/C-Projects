// Write a program to remove the duplicates from an array

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to remove duplicates from an array
vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_set<int> uniqueElements;
    vector<int> result;

    // Traverse through the array
    for (int num : arr) {
        // If the element is not already in the set, add it to result
        if (uniqueElements.find(num) == uniqueElements.end()) {
            uniqueElements.insert(num);
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = removeDuplicates(arr);

    cout << "Array after removing duplicates: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
