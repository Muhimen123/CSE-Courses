/*
Create a class named 'Rectangle' with two data members- length and breadth
and a function to calculate the area which is 'length*breadth'. The class has
three constructors which are :
1 - having no parameter - values of both length and breadth are assigned zero.
2 - having one number as parameter - both length and breadth are assigned
that number.
3 - having two numbers as parameters - the two numbers are assigned as
length and breadth respectively.

Now, create objects of the 'Rectangle' class having none, one and two
parameters and print their areas.
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

    Rectangle(int n) {
        length = n;
        breadth = n;
    }

    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    void setter(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

};

int main() {
    Rectangle r1;
    r1.setter(5, 10);
    Rectangle r2(5);
    Rectangle r3(5, 10);
    cout << "Area of rectangle 1: " << r1.area() << endl;
    cout << "Area of rectangle 2: " << r2.area() << endl;
    cout << "Area of rectangle 3: " << r3.area() << endl;
    return 0;
}