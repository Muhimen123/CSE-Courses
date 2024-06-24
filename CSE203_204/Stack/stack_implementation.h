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
        while(iter != NULL) {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    void reverse_print_stack() {
        if(is_empty()) return;
        stack<int> tempStack;
        Node *iter = head;
        while(iter != nullptr) {
            tempStack.push(iter->data);
            iter = iter->next;
        }
        while(!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
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
                if(iter->next == nullptr) break;
                prev = iter;
                iter = iter->next;
            }
            prev->next = nullptr;
            delete iter;
        }
    }
};