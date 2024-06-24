#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class Deque
{
private:
    Node *head;
    Node *tail;

public:
    Deque()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool is_empty() {
        if(head == nullptr and tail == nullptr) return true;
        return false;
    }

    void push_back(int value) {
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
            Node *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
        }
    }

    void push_front(int value) {
        if(head == nullptr) {
            push_back(value);
        } else {
            Node *new_node = new Node;
            new_node->value = value;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void pop_back() {
        if(is_empty()) {
            cout << "Deque is empty" << endl;
        } else if(head == tail) {
            pop_front();
        } else {
            Node *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            tmp->prev = nullptr;
            delete tmp;
        }
    }

    void back() {
        if(is_empty()) {
            cout << "Deque is empty" << endl;
        } else {
            cout << tail->value << endl;
        }
    }
};

int main()
{
    Deque q;
    while(true) {
        cout << "Menu: " << endl;
        cout << "1. Push back" << endl;
        cout << "2. Print" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Front" << endl;
        cout << "5. Pop front" << endl;
        cout << "6. Push front" << endl;
        cout << "7. Pop Back" << endl;
        cout << "8. Back" << endl;

        int choice;
        cin >> choice;

        if(choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            q.push_back(value);
        } else if(choice == 2) {
            q.print();
        } else if(choice == 3) {
            break;
        } else if(choice == 4) {
            int value = q.front();
            cout << value << endl;
        } else if(choice == 5) {
            q.pop_front();
        } else if(choice == 6) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            q.push_front(value);
        } else if(choice == 7) {
            q.pop_back();
        } else if(choice == 8) {
            q.back();
        }
    }
    return 0;
}