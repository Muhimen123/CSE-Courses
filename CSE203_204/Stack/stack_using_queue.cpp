#include <bits/stdc++.h>
#include "../Queue/Queue_implementation.h"
using namespace std;

class Stack
{
private:
    Queue q1;
    Queue q2;

public:
    void push_back(int value) {
        q2.push_back(value);
        while(!q1.is_empty()) {
            int tp = q1.front();
            q1.pop_front();
            q2.push_back(tp);
        }

        swap(q1, q2);
        // Queue tmp;
        // tmp = q1;
        // q1 = q2;
        // q2 = tmp;
    } 

    void pop() {
        q1.pop_front();
    }

    void print_stack() {
        q1.reverse_print();
    }
};

int main()
{
    Stack stack;
    int choice, value;

    do {
        cout << "Stack Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Print Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push_back(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Stack: ";
                stack.print_stack();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}