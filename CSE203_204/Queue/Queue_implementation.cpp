#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class Queue
{
private:
    Node *head;
    Node *tail;

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

    void enqueue(int value) {
        Node *new_node = new Node;
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
        Node *iter = head;
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

    void dequeue() {
        if(is_empty()) {
            cout << "Queue is empty" << endl;
        }
        else if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } 
        else {
            Node *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
        }
    }

};

int main()
{
    Queue q;
    while(true) {
        cout << "Menu: " << endl;
        cout << "1. Enque" << endl;
        cout << "2. Print" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Front" << endl;
        cout << "5. Dequeue" << endl;

        int choice;
        cin >> choice;

        if(choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        } else if(choice == 2) {
            q.print();
        } else if(choice == 3) {
            break;
        } else if(choice == 4) {
            int value = q.front();
            cout << value << endl;
        } else if(choice == 5) {
            q.dequeue();
        }
    }
    return 0;
}