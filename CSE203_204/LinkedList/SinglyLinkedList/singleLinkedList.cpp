#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void createList(int n)
    {

        for(int i = 0; i < n; i++) {
            int value;
            cout << "Enter element number " << i+1 << ": ";
            cin >> value;

            if(i == 0) {
                insertFirst(value);
            } else {
                insertLast(value);
            }
        }

    }

    void insertFirst(int val)
    {
        // Two cases are possible 
        // The list is empty
        // The list is not empty


        Node *new_node = new Node;
        new_node->data = val;
        new_node->next = nullptr;

        // The list is empty
        if(head == nullptr) {
            head = new_node;
        }

        // List is not empty
        else {
            new_node->next = head;
            head = new_node;
        }

    }

    void insertLast(int val)
    {
        Node *new_node = new Node;
        new_node->data = val;
        new_node->next = nullptr;

        Node *iter = head;
        
        // Iterate to the last position of the linked list
        while(iter->next != nullptr) {
            iter = iter->next;
        }

        iter->next = new_node;
    }

    void insertAt(int pos, int val)
    {
        // val: 54 52 123 50 1
        // pos:  1  2   3  4 5
        // inserting at position 3  means the new array will be
        // val: 54 52 520 123 50 1
        // pos:  1  2   3   3  4 5

        Node *new_node = new Node;
        new_node->data = val;
        new_node->next = nullptr;

        if(pos == 1) {
            // 1 is the beginning of the list
            insertFirst(val);
        } 
        else {
            Node *iter = head;
            for(int i = 2; i < pos; i++) {
                iter = iter->next;
                if(iter->next == nullptr) {
                    // we have reached the end of the list but haven't found the position
                    break;
                }
            }

            new_node->next = iter->next;
            iter->next = new_node;
        }
    }

    void deleteFirst()
    {
        // List is empty, we don't have to do anything
        if(head == nullptr) return;

        Node *temp = head;
        head = head->next;

        delete temp;
    }

    void deleteLast()
    {
        Node *iter = head;
        Node *prev;
        while(iter->next != nullptr) {
            prev = iter;
            iter = iter->next;
        }
        prev->next = nullptr;
        delete iter;
    }

    void deleteAt(int pos)
    {
        if(pos == 1) {
            deleteFirst();
        } else {
            bool okay = true;
            Node *iter = head;
            Node *prev;
            for(int i = 1; i < pos; i++) {
                prev = iter;
                iter = iter->next;
                if(iter->next == nullptr and i != pos - 1) {
                    okay = false;
                    break;
                }
            }

            // okay false means we haven't found the index we were looking for. So we won't conduct any delete operation
            if(!okay) {
                return;
            } else {
                prev->next = iter->next;
                delete iter;
            }

        }
    }

    void printList()
    {
        Node *iter = head;
        cout << "List: ";
        while(iter != NULL) {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    int search(int val)
    {
        Node *iter = head;
        int pos = 1;
        while(iter != NULL) {
            if(iter->data == val) {
                return pos;
            }
            iter = iter->next;
            pos++;
        }

        return 0;
    }

    void freeTheList()
    {
        Node *iter = head;
        Node *prev;
        while(iter != NULL) {
            prev = iter;
            iter = iter->next;
            delete prev;
        }
        delete prev;
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
