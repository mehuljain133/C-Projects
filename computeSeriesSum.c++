//Write a program to compute the sum of the first n terms of the following series: S = 1 - 1 / (2 ^ 2) + 1 / (3 ^ 3) - ... 1 / (n ^ n)

#include <iostream>
#include <cmath>

using namespace std;

// Function to compute the sum of the series
double computeSeriesSum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        double term = 1.0 / pow(i, i);  // Calculate the i-th term
        if (i % 2 == 0) {
            sum -= term;  // Subtract for even indices
        } else {
            sum += term;  // Add for odd indices
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    double result = computeSeriesSum(n);
    cout << "Sum of the series for n = " << n << " is: " << result << endl;

    return 0;
}
