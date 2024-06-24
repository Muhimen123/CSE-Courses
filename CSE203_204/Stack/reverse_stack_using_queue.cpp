#include <bits/stdc++.h>
using namespace std;


struct NodeQueue
{
    int value;
    NodeQueue *next;
    NodeQueue *prev;
};

class Queue
{
private:
    NodeQueue *head;
    NodeQueue *tail;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool is_empty() {
        if(head == nullptr and tail == nullptr) return true;
        return false;
    }

    void push_back(int value) {
        NodeQueue *new_node = new NodeQueue;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if(head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void print() {
        NodeQueue *iter = head;
        while(iter != NULL) {
            cout << iter->value<< " ";
            iter = iter->next;
        }
        cout << endl;
    }

    int front() {
        if(!is_empty()) {
            return head->value;
        } else {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    void pop_front() {
        if(is_empty()) {
            cout << "Queue is empty" << endl;
        }
        else if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } 
        else {
            NodeQueue *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
        }
    }

};

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

int main() {
    Stack st;
    Queue q;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(520);
    st.print_stack();
    while(!st.is_empty()) {
        int tp = st.top();
        q.push_back(tp);
        st.pop();
    }
    while(!q.is_empty()) {
        int tp = q.front();
        st.push(tp);
        q.pop_front();
    }

    st.print_stack();
    return 0;
}
