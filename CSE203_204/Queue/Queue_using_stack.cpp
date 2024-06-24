#include <bits/stdc++.h>
#include "../Stack/stack_implementation.h"

using namespace std;

class Queue
{
private:
    Stack s1;
    Stack s2;

public:
    void push_back(int value) {
        while(!s1.is_empty()) {
            int tp = s1.top();
            s2.push(tp);
            s1.pop();
        }

        s1.push(value);
        
        while(!s2.is_empty()) {
            int tp = s2.top();
            s1.push(tp);
            s2.pop();
        }
    }

    void pop_front() {
        s1.pop();
    }

    void print() {
        s1.reverse_print_stack();
    }
};

int main()
{
    Queue queue;
    int choice, value;

    do {
        cout << "Queue Menu:" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Print queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                queue.push_back(value);
                break;
            case 2:
                queue.pop_front();
                break;
            case 3:
                cout << "Queue: ";
                queue.print();
                cout << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}