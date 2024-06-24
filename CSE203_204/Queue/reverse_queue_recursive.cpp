#include <bits/stdc++.h>
#include "Queue_implementation.h"
using namespace std;

void reverse_queue(Queue &q) {
    if(q.is_empty()) return;
    else {
        int top = q.front();
        q.pop_front();

        reverse_queue(q);

        q.push_back(top);
    }
}

int main() {
    Queue q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(25);
    q.push_back(4);
    q.print();
    reverse_queue(q);
    q.print();
    return 0;
}