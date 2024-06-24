#include <bits/stdc++.h>
#include "Queue_implementation.h"
using namespace std;


int main() {
    int n;
    cin >> n;
    QueueString q;
    string st = "1";
    q.push_back(st);
    for(int i = 1; i <= n; i++) {
        string binary = q.front(); q.pop_front();
        cout << i << ": " << binary << endl;
        q.push_back(binary + "0");
        q.push_back(binary + "1");
    } 
}