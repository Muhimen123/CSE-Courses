/*
Create a class Printer with overloaded print methods. One method should print a
string, another should print a string with a specified number of copies (defaulting to 1),
and another should print a string with a specified prefix and number of copies (defaulting
to 1).
*/

#include <bits/stdc++.h>
using namespace std;

class Printer {
    public:
    // void print(string s) {
    //     cout << s << endl;
    // }

    void print(string s, int n = 1) {
        for(int i = 0; i < n; i++) {
            cout << s << endl;
        }
    }

    void print(string s, string prefix, int n = 1) {
        for(int i = 0; i < n; i++) {
            cout << prefix << s << endl;
        }
    }
};

int main() {
    Printer p;
    p.print("Hello");
    p.print("Hello", 3);
    p.print("Hello", "World", 3);
    return 0;
}

// NOTE: 
// Lines 13-15 were comment out because the first print and second print is essentially the same
// How? 
// default value of n is 1, so it will only print once that is exacty what the first print does
// If we keep the first print, the computer will throw an error


// ALTERNATIVE:
// If we want to keep the first print, we can omit the default value of n in the second print