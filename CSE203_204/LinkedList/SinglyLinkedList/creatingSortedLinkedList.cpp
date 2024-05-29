#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

class SinglyLinkedListSorted {
    private:
    Node *head;

    public:

    SinglyLinkedListSorted() {
        head = nullptr;
    }

    void insert_list(int value) {
        Node *new_node = new Node;
        new_node->next = nullptr;
        new_node->data = value;
        if(head == nullptr) {
            head = new_node;
        }
        else {
            if(head->data > value) {
                insert_first(value);
            } else {
                Node *iter = head;
                Node *prev;
                while(iter != NULL) {
                    prev = iter;
                    if(iter->data > value) break;
                    iter = iter->next;
                }

                new_node->next = iter;
                prev->next = new_node;

            }
        }
    }

    void insert_first(int value) {
        Node *new_node = new Node;
        new_node->next = nullptr;
        new_node->data = value;

        new_node->next = head;
        head = new_node;
    }

    void print_list() {
        Node *iter = head;
        while(iter != NULL) {
            cout << iter->data << " ";
            iter = iter->next;
        }
    }
};

int main() {
    SinglyLinkedListSorted list;
    list.insert_list(50);
    list.insert_list(15);
    list.insert_list(50);
    list.insert_list(100);
    list.insert_list(150);
    list.print_list();
    return 0;
}