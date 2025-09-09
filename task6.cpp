#include <iostream>
using namespace std;


int find_mode(int arr[], int size) {
    if (size == 0) {
        return -1; 
    }

    int mode = arr[0];  
    int max_count = 0;  


    for (int i = 0; i < size; ++i) {
        int count = 0; 
        
        
        for (int j = 0; j < size; ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }

    return mode;
}


void test_case_1() {
    int arr[] = {1, 2, 3, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = find_mode(arr, size);
    if (result == 3) {
        cout << "Array with unique mode: Passed" << endl;
    } else {
        cout << "Array with unique mode: Failed" << endl;
    }
}


void test_case_2() {
    int arr[] = {1, 2, 3, 3, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = find_mode(arr, size);
    if (result == 3) {  // We choose the first mode encountered
        cout << "Array with multiple modes: Passed" << endl;
    } else {
        cout << "Array with multiple modes: Failed" << endl;
    }
}


void test_case_3() {
    int arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = find_mode(arr, size);
    if (result == -1) {
        cout << "Empty array: Passed" << endl;
    } else {
        cout << "Empty array: Failed" << endl;
    }
}

int main() {
    
    test_case_1();
    test_case_2();
    test_case_3();
    
    return 0;
}
