// Rakshya Kafle
// Matrix Multiplication - High Precision
// Occc-C++

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Function to read matrix from file
bool readMatrix(string filename, int& rows, int& cols, vector<vector<double>>& matrix) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    // Read dimensions first
    if (!(inFile >> rows >> cols)) return false;

    matrix.assign(rows, vector<double>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(inFile >> matrix[i][j])) return false;
        }
    }

    inFile.close();
    return true;
}

int main() {
    string file1, file2;
    int r1, c1, r2, c2;
    vector<vector<double>> mat1, mat2;

    cout << "Enter the filename for the first matrix (Matrix A): ";
    cin >> file1;
    cout << "Enter the filename for the second matrix (Matrix B): ";
    cin >> file2;

    if (!readMatrix(file1, r1, c1, mat1) || !readMatrix(file2, r2, c2, mat2)) {
        cout << "Error: Could not read files. Ensure they start with 'rows cols'." << endl;
        return 1;
    }

    // Multiplication Rule: Columns of A must equal Rows of B
    if (c1 != r2) {
        cout << "\nError: Dimension mismatch! Cols of A (" << c1
            << ") must match Rows of B (" << r2 << ")." << endl;
        return 1;
    }

    // Initialize result matrix with zeros
    vector<vector<double>> result(r1, vector<double>(c2, 0.0));

    // Matrix Multiplication Logic
    // 
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Displaying the result with standard spacing
    cout << "\nResulting Matrix (" << r1 << "x" << c2 << "):" << endl;
    for (const auto& row : result) {
        for (double val : row) {
            cout << setw(12) << val << " ";
        }
        cout << endl;
    }

    // THE QUIZ ANSWER
    // Lower left corner is the last row (r1-1) and the first column (0)
    cout << "\n" << string(45, '-') << endl;
    cout << "QUIZ ANSWER (Lower Left Corner):" << endl;
    cout << setprecision(15) << result[r1 - 1][0] << endl;
    cout << string(45, '-') << endl;

    return 0;
}