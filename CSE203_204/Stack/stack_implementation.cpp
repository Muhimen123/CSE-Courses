#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *head;

public:
    Stack() {
        head = nullptr;
    }

    bool is_empty() {
        if(head == nullptr) return true;
        return false;
    }

    void push(int value) {
        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;

        if(is_empty()) {
            head = new_node;
        } else {
            Node *iter = head;
            while(true) {
                if(iter->next == nullptr) break;
                iter = iter->next;
            }

            iter->next = new_node;
        }
    }

    void print_stack() {
        if(is_empty()) return;
        Node *iter = head;
        while(true) {
            cout << iter->data << " ";
            iter = iter->next;
            if(iter->next == nullptr) {
                cout << iter->data;
                break;
            }
        }
        cout << endl;
    }

    int top() {
        if(is_empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            Node *iter = head;
            while(true) {
                if(iter->next == nullptr) break;
                iter = iter->next;
            }

            return iter->data;
        }
    }

    void pop() {
        if(is_empty()) {
            cout << "Stack is empty" << endl;
        } 
        else if(head->next == nullptr) {
            head = nullptr;
        } 
        else {
            Node *iter = head;
            Node *prev;
            while(true) {
                prev = iter;
                if(iter->next == nullptr) break;
                iter = iter->next;
            }
            prev->next = nullptr;
            delete iter;
        }
    }
};

int main()
{

    Stack st;
    while(true) {
        cout << "Menu: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Print" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Top" << endl;
        cout << "5. Pop" << endl;

        int choice;
        cin >> choice;

        if(choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            st.push(value);
        } else if(choice == 2) {
            st.print_stack();
        } else if(choice == 3) {
            break;
        } else if(choice == 4) {
            int value = st.top();
            cout << value << endl;
        } else if(choice == 5) {
            st.pop();
        }
    }
    return 0;
}