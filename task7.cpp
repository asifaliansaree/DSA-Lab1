#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Naive multiplication
void naiveMultiply(int n, int A[][8], int B[][8], int C[][8]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Add matrices
void add(int n, int A[][8], int B[][8], int C[][8]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Subtract matrices
void subtract(int n, int A[][8], int B[][8], int C[][8]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen multiplication (recursive)
void strassenMultiply(int n, int A[][8], int B[][8], int C[][8]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[8][8], A12[8][8], A21[8][8], A22[8][8];
    int B11[8][8], B12[8][8], B21[8][8], B22[8][8];
    int M1[8][8], M2[8][8], M3[8][8], M4[8][8], M5[8][8], M6[8][8], M7[8][8];
    int T1[8][8], T2[8][8];

    // Split into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Strassen's 7 multiplications
    add(newSize, A11, A22, T1);
    add(newSize, B11, B22, T2);
    strassenMultiply(newSize, T1, T2, M1);

    add(newSize, A21, A22, T1);
    strassenMultiply(newSize, T1, B11, M2);

    subtract(newSize, B12, B22, T1);
    strassenMultiply(newSize, A11, T1, M3);

    subtract(newSize, B21, B11, T1);
    strassenMultiply(newSize, A22, T1, M4);

    add(newSize, A11, A12, T1);
    strassenMultiply(newSize, T1, B22, M5);

    subtract(newSize, A21, A11, T1);
    add(newSize, B11, B12, T2);
    strassenMultiply(newSize, T1, T2, M6);

    subtract(newSize, A12, A22, T1);
    add(newSize, B21, B22, T2);
    strassenMultiply(newSize, T1, T2, M7);

    // Compute C11, C12, C21, C22
    int C11[8][8], C12[8][8], C21[8][8], C22[8][8];

    add(newSize, M1, M4, T1);
    subtract(newSize, T1, M5, T2);
    add(newSize, T2, M7, C11);

    add(newSize, M3, M5, C12);
    add(newSize, M2, M4, C21);

    add(newSize, M1, M3, T1);
    subtract(newSize, T1, M2, T2);
    add(newSize, T2, M6, C22);

    // Combine into result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Print matrix
void printMatrix(int n, int M[][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

// -------- Test Cases --------
void testCase2x2() {
    int A[8][8] = {{1, 2}, {3, 4}};
    int B[8][8] = {{5, 6}, {7, 8}};
    int C1[8][8], C2[8][8];

    cout << "2x2 Naive Multiplication:\n";
    naiveMultiply(2, A, B, C1);
    printMatrix(2, C1);

    cout << "2x2 Strassen Multiplication:\n";
    strassenMultiply(2, A, B, C2);
    printMatrix(2, C2);
}

void testCase4x4() {
    int A[8][8] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int B[8][8] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    int C1[8][8], C2[8][8];

    cout << "4x4 Naive Multiplication:\n";
    naiveMultiply(4, A, B, C1);
    printMatrix(4, C1);

    cout << "4x4 Strassen Multiplication:\n";
    strassenMultiply(4, A, B, C2);
    printMatrix(4, C2);
}

void testCaseRandom() {
    int n = 4;
    int A[8][8], B[8][8], C1[8][8], C2[8][8];

    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    cout << "Random Matrix A:\n";
    printMatrix(n, A);

    cout << "Random Matrix B:\n";
    printMatrix(n, B);

    naiveMultiply(n, A, B, C1);
    strassenMultiply(n, A, B, C2);

    cout << "Naive Multiplication Result:\n";
    printMatrix(n, C1);

    cout << "Strassen Multiplication Result:\n";
    printMatrix(n, C2);
}

int main() {
    testCase2x2();
    cout << "-------------------------\n";
    testCase4x4();
    cout << "-------------------------\n";
    testCaseRandom();
    return 0;
}
