#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int par[N];
int Size[N];

void make_set(int i) {
    par[i] = i;
    Size[i] = i;
}

int find_set(int i) {
    if(i == par[i]) return i;
    return par[i] = find_set(par[i]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);

    if(Size[u] > Size[v]) swap(u, v);
    par[v] = u;
    Size[u] += Size[v];
}

int main() {
    int n, m;
    cin >> n >> m;

    using vvi = vector<vector<int>>;
    vvi edges;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    vector<vvi> allMST;

    int mst_cost = 0;
    // First get the normal MST
    vvi mst;

    for(int i = 0; i <= n; i++) make_set(i);
    for(auto edge: edges) {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(find_set(u) == find_set(v)) continue;
        union_set(u, v);
        mst.push_back({u, v, w});
        mst_cost += w;
    }

    allMST.push_back(mst);

    // Generate all possible edge subsequenecs O(n^2) 
    for(int i = 1; i < (1 << m); i++) {
        vector<vector<int>> tmp_edges;

        // tmp_edges is just a sub sequence of all the edges
        for(int j = 0; j < m; j++) {
            if(i & (1 << j)) tmp_edges.push_back(edges[j]);
        }
        
        mst.clear();
        int tmp_cost = 0;

        for(int i = 0; i <= n; i++) make_set(i);
        vector<bool> visited(n+1, false);
        visited[0] = true;

        // Generated MST for the specific sub sequence

        //O(nlogn)
        for(auto edge: tmp_edges) {
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(find_set(u) == find_set(v)) continue;
            union_set(u, v);
            visited[u] = true;
            visited[v] = true;
            mst.push_back({u, v, w});
            tmp_cost += w;
        }

        if(count(visited.begin(), visited.end(), false)) continue;
        if(tmp_cost != mst_cost) continue;
        
        // If the MST created from the sub sequence has all the nodes visited and have the same cost, then it is a valid MST
        allMST.push_back(mst);
    }

    cout << allMST.size() << endl;

    return 0;
}

// Total Complexity: O(n^2 + nlogn)