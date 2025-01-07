#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int parent[N];
int Size[N];

void make_set(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]); // Path Compression
}

void unions_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(Size[a] < Size[b]) swap(a, b); // Union by Size
        parent[b] = a;
        Size[a] += Size[b];
    }
}



int main() {
    int n, e;
    for(int i = 0; i < n; i++) make_set(i);

    int u, v;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        unions_set(u, v);
    }

    return 0;
}