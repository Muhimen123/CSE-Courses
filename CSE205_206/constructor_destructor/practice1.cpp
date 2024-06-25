/*
Create a class named 'Rectangle' with two private data members- length and
breadth and a function to calculate the area which is 'length*breadth'.
• The class has constructor (no parameter) - values of both length and
breadth are assigned zero.
• Create a Getter and Setter functions for setting and getting length and
breadth.

Now, create objects of the 'Rectangle' class print their areas.
*/

#include <bits/stdc++.h>
using namespace std;

class Rectangle {
    int length, breadth;

    public:
    Rectangle() {
        length = 0;
        breadth = 0;
    }

    void setter(int l, int b) {
        length = l;
        breadth = b;
    }

    int getlength() {
        return length;
    }

    int getbreadth() {
        return breadth;
    }

    int area() {
        return length * breadth;
    }
};

int main() {
    Rectangle r1;
    r1.setter(5, 10);
    cout << "Area of rectangle 1: " << r1.area() << endl;
    return 0;
}