#include <iostream>
#include <string>
using namespace std;

int find_pattern(string text, string pattern) {
    int pos = text.find(pattern);
    if (pos != string::npos) {
        return pos;
    } else {
        return -1;
    }
}
void Pattern_at_the_beginning() {
    int result = find_pattern("I am a student of DSA ", "I");
    if (result == 0) {  
        cout << "Pattern_at_the_beginning: Passed" << endl;
    } else {
        cout << "Pattern_at_the_beginning: Failed" << endl;
    }
}
void Pattern_at_the_End() {
    int result = find_pattern("I am a student of DSA ", "DSA");
    if (result == 18) {  
        cout << "Pattern_at_the_End: Passed" << endl;
    } else {
        cout << "Pattern_at_the_End: Failed" << endl;
    }
}
void Pattern_not_present() {
    int result = find_pattern("I am a student of DSA ", "XYZ");
    if (result == -1) {  
        cout << "Pattern_not_present: Passed" << endl;
    } else {
        cout << "Pattern_not_present: Failed" << endl;
    }
}
void Empty_pattern() {
    int result = find_pattern("I am a student of DSA ", "");
    if (result == 0) {  
        cout << "Empty_pattern: Passed" << endl;
    } else {
        cout << "Empty_pattern: Failed" << endl;
    }
}

int main() {
    // Calling all the test cases
    Pattern_at_the_beginning();
   Pattern_at_the_End();
    Pattern_not_present();
    Empty_pattern();
    
    return 0;
}