#include <iostream>
using namespace std;

int Indices(int arr[], int size, int key, int Indices[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            Indices[count] = i;
            count++;
        }
    }
    return count;  
}

void TestCaseEmpty(){
    int array[] = {};
  int size = 0;
    int key = 9;
    int indices[] ={}; 
    int count = Indices(array , size , key , indices  );
    int sizee = sizeof(indices) / sizeof(indices[0]);
    if(sizee == 0 ){
        cout << "test case 1 passes" << endl;
    }
    else {cout << "test case 1 failed"; }
}


void TestCaseNo(){
    int array[] = {1, 2, 3, 4, 5, 6, };
  int size = 6;
    int key = 9;
   int indices[6] ; 
    int count = Indices(array , size , key , indices  );
    if(count == 0 ){
        cout << "test case 2 passes" << endl;
    }
      else {cout << "test case 2 failed"; }
}

void TestCaseMultiple(){
      int array[] = {1, 2, 3, 3 ,5 , 6, 6, 6 };
    int size = 8;
    int key = 6;
    int indices[8] ; 
    int count = Indices(array , size , key , indices  );
    if(count != 0 && count != 1 ){
        cout << "test case 3 passes" << endl;
    }  else {cout << "test case 3 failed"; }
    
}

int main() {
 
  TestCaseEmpty();
  TestCaseNo();
  TestCaseMultiple();

    return 0;
}