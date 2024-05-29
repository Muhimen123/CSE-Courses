#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void createList(int n)
    {
        for(int i = 0; i < n; i++) {
            int val;
            cout << "Enter list element " << i+1 << ": ";
            cin >> val;

            if(i == 0) insertFirst(val);
            else insertLast(val);
        }
    }

    void insertFirst(int val)
    {
        Node *new_node = new Node;
        new_node->data = val;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if(head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
    }

    void insertLast(int val)
    {
        Node *new_node = new Node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
        new_node->data = val;

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertAt(int pos, int val)
    {
        if(pos == 1) insertFirst(val);
        else {
            Node *new_node = new Node;
            new_node->prev = nullptr;
            new_node->next = nullptr;
            new_node->data = val;

            Node *iter = head;
            for(int i = 2; i < pos; i++) {
                iter = iter->next;
                if(iter->next == nullptr) {
                    break;
                }
            }

            new_node->prev = iter;
            new_node->next = iter->next;
            iter->next->prev = new_node;
            iter->next = new_node;
        }
    }

    void deleteFirst()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    void deleteLast()
    {
        Node *tmp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete tmp;
    }

    void deleteAt(int pos)
    {
        if(pos == 1) deleteFirst();
        else {
            bool flag = false;
            Node *iter = head;
            for(int i = 1; i < pos; i++) {
                iter = iter->next;
                if(iter->next == nullptr and i == pos - 1) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                iter->prev->next = iter->next;
                iter->next->prev = iter->prev;
                delete iter;
            }
            else {
                deleteLast();
            }
        }
    }

    void printList()
    {
        cout << "List: ";
        Node *iter = head;
        while(iter != NULL) {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    int search(int val)
    {
    }

    void freeTheList()
    {
    }
};

int main()
{
    cout << "Enter the number of elements in the list: ";
    int n;
    cin >> n;
    cout << "Create the list\n";
    DoublyLinkedList list;
    list.createList(n);
    list.printList();
    cout << "A singly linked list is being created!\n";

    while (true)
    {
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete At\n";
        cout << "7. Search\n";
        cout << "8. Print List\n";
        cout << "9. Exit\n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the element: ";
            int val;
            cin >> val;
            list.insertFirst(val);
        }
        else if (choice == 2)
        {
            cout << "Enter the element: ";
            int val;
            cin >> val;
            list.insertLast(val);
        }
        else if (choice == 3)
        {
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            cout << "Enter the element: ";
            int val;
            cin >> val;
            list.insertAt(pos, val);
        }
        else if (choice == 4)
            list.deleteFirst();
        else if (choice == 5)
            list.deleteLast();
        else if (choice == 6)
        {
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            list.deleteAt(pos);
        }
        else if (choice == 7)
        {
            cout << "Enter the value: ";
            int val;
            cin >> val;
            int pos = list.search(val);
            if (pos == -1)
                cout << "No list exists!\n";
            else if (pos)
                cout << "Position: " << pos << "\n\n";
            else
                cout << "Item not found in the list\n";
        }
        else if (choice == 8)
            list.printList();
        else if (choice == 9)
            break;
        else
            cout << "Wrong Choice Input!!\n\n";
    }
    list.freeTheList();
    return 0;
}
