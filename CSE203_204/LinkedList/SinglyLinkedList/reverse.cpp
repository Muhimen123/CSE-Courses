#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class LinkedList
{
    Node* head = nullptr;
    public:
    LinkedList() {
        head = nullptr;
    }

    void reverse() {
        Node* curr = head;
        Node* prev = NULL;
        Node *next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void push(int value) {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = nullptr;

        if(head == nullptr) {
            head = new_node;
            return;
        }

        Node *iter = head;
        while(iter->next != nullptr) {
            iter = iter->next;
        }
        iter->next = new_node;
    }

    void print() {
        Node *iter = head;
        while(iter != NULL) {
            cout << iter->value << " ";
            iter = iter->next;
        }
        cout << endl;
    }

};



int main() {
    LinkedList list;
    list.push(5);
    list.push(10);
    list.push(41);
    list.push(5);
    list.push(7);

    list.print();
    list.reverse();
    list.print();
}