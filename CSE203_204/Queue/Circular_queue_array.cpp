#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int size;
    int capacity;
    int *arr;
    int front;
    int rear;

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[cap];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool is_empty() {
        return !size;
    }

    bool is_full() {
        if(capacity == size) return true;
        return false;
    }

    void enqueue(int value) {
        if(is_full()) {
            cout << "Full" << endl;
            return;
        }

        if(is_empty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;

    } 

    void dequeue() {
        if(is_empty()) {
            cout << "Empty" << endl;
            return;
        } 
        if(front == rear) {
            front = -1;
            rear = -1;
            size--;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int Front() {
        if(is_empty()) return -1; // sake of simplicity
        return arr[front];
    }

    int back() {
        if(is_empty()) return -1; // sake of simplicity
        return arr[rear];
    }

    int Size() {
        return size;
    }

    void print() {
        if(!is_empty()) {
            int iter = front;
            while(true) {
                cout << arr[iter] << " "; 
                iter = (iter + 1) % capacity;
                if(iter == ((rear + 1) % capacity)) break;
            }
        }
        cout << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the capacity of the circular queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int choice;
    do {
        cout << "\nCircular Queue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Back\n";
        cout << "5. Size\n";
        cout << "6. Print\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            }
            case 2: {
                cq.dequeue();
                break;
            }
            case 3: {
                int front = cq.Front();
                if (front == -1) {
                    cout << "Circular queue is empty\n";
                } else {
                    cout << "Front element: " << front << endl;
                }
                break;
            }
            case 4: {
                int back = cq.back();
                if (back == -1) {
                    cout << "Circular queue is empty\n";
                } else {
                    cout << "Back element: " << back << endl;
                }
                break;
            }
            case 5: {
                int size = cq.Size();
                cout << "Size of the circular queue: " << size << endl;
                break;
            }
            case 6: {
                cout << "Elements in the circular queue: ";
                cq.print();
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}