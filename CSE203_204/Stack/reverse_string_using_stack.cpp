#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
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

    char top() {
        if(is_empty()) {
            cout << "Stack is empty" << endl;
            return 0;
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

int main() {
    char str[10];
    scanf("%s", str);
    printf("Initial String: %s\n", str);
    Stack st;
    for(int i = 0; i < strlen(str); i++) {
        st.push(str[i]);
    }
    int index = 0;
    while(!st.is_empty()) {
        str[index++] = st.top();
        st.pop();
    }
    printf("Reverse String: %s", str);
    return 0;
}