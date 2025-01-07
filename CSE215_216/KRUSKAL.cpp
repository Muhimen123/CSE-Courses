#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int parent[N];
int Size[N];

void make_set(int i) {
    parent[i] = i;
    Size[i] = i;
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(v);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;

    if(Size[u] < Size[v]) swap(u, v);
    parent[v] = u;
    Size[v] += Size[u];
}

int main() {

    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;

    int u, v, w;
    for(int i = 0; i < e; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());
    int min_cost = 0;

    // Kruskl's part
    vector<vector<int>> MST_edges;
    for(auto edge: edges) {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(find_set(u) == find_set(v)) continue;
        min_cost += w;
        union_set(u, w);
        MST_edges.push_back(edge);
    }

    cout << "MST Cost: " << min_cost << endl;

}