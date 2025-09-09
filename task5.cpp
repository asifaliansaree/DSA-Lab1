#include <iostream>
using namespace std;

void generatePascalsTriangle(int n) {
    if (n <= 0) {
        cout << "No rows to print.\n";
        return;
    }

    int triangle[100][100] = {0}; 

    for (int i = 0; i < n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }

     
        for (int space = 0; space < n - i - 1; space++) {
            cout << "  ";  
        }

 
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << "   "; 
        }
        cout << "\n";
    }
}

int main() {
    cout << "Pascal's Triangle with n=8:\n";
    generatePascalsTriangle(8);
    return 0;
}