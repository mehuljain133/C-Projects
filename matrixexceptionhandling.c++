/* Create Matrix class. Write a menu-driven program to perform following Matrix
operations
Rewrite Matrix class with exception handling. Exceptions should be thrown by 
the functions if matrices passed to them are incompatible and handled by main() function. */

#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** mat;

public:
    // Constructor to initialize matrix dimensions
    Matrix(int r, int c) : rows(r), cols(c) {
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }
    }

    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    // Function to input matrix elements
    void inputMatrix() {
        cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix
    void displayMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Matrix addition
    Matrix add(const Matrix& m) const {
        if (this->rows != m.rows || this->cols != m.cols) {
            throw runtime_error("Matrix dimensions must match for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = this->mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix multiply(const Matrix& m) const {
        if (this->cols != m.rows) {
            throw runtime_error("Number of columns of the first matrix must equal the number of rows of the second matrix for multiplication.");
        }

        Matrix result(this->rows, m.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < this->cols; k++) {
                    result.mat[i][j] += this->mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }

    // Matrix transpose
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }

    // Function to get the number of rows
    int getRows() const {
        return rows;
    }

    // Function to get the number of columns
    int getCols() const {
        return cols;
    }
};

int main() {
    int rows1, cols1, rows2, cols2, choice;

    // Input for first matrix
    cout << "Enter rows and columns for Matrix 1: ";
    cin >> rows1 >> cols1;
    Matrix m1(rows1, cols1);
    m1.inputMatrix();

    // Input for second matrix
    cout << "Enter rows and columns for Matrix 2: ";
    cin >> rows2 >> cols2;
    Matrix m2(rows2, cols2);
    m2.inputMatrix();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display Matrix 1\n";
        cout << "2. Display Matrix 2\n";
        cout << "3. Add Matrices\n";
        cout << "4. Multiply Matrices\n";
        cout << "5. Transpose Matrix 1\n";
        cout << "6. Transpose Matrix 2\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Matrix 1:\n";
                    m1.displayMatrix();
                    break;
                case 2:
                    cout << "Matrix 2:\n";
                    m2.displayMatrix();
                    break;
                case 3:
                    cout << "Adding Matrices...\n";
                    {
                        Matrix result = m1.add(m2);
                        cout << "Result of Matrix 1 + Matrix 2:\n";
                        result.displayMatrix();
                    }
                    break;
                case 4:
                    cout << "Multiplying Matrices...\n";
                    {
                        Matrix result = m1.multiply(m2);
                        cout << "Result of Matrix 1 * Matrix 2:\n";
                        result.displayMatrix();
                    }
                    break;
                case 5:
                    cout << "Transpose of Matrix 1:\n";
                    {
                        Matrix result = m1.transpose();
                        result.displayMatrix();
                    }
                    break;
                case 6:
                    cout << "Transpose of Matrix 2:\n";
                    {
                        Matrix result = m2.transpose();
                        result.displayMatrix();
                    }
                    break;
                case 7:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
