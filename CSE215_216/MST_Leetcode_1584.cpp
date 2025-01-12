#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

class DSU {

private:
    int par[N];
    int Size[N];

public:
    DSU() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            Size[i] = 1;
        }
    };

    int find_set(int v) {
        if(v == par[v]) return v;
        return par[v] = find_set(par[v]);
    }

    void union_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);

        if(Size[u] > Size[v]) swap(u, v);
        par[v] = u;
        Size[u] += Size[v];
    }
};

class solve {
    private:
    vector<vector<int>> points;
    vector<vector<int>> edges; 
    public:

    solve() {}
    solve(vector<vector<int>> &pnt) {
        this->points = pnt;

        this->point_to_graph();
        long long ans = this->MSTCOST();
        cout << ans << "\n";
    }

    int manhattan_distance(vector<int> p1, vector<int> p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    vector<vector<int>> point_to_graph() {
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int md = manhattan_distance(points[i], points[j]);
                edges.push_back({md, i, j});
            }
        }

        return edges;
    }

    long long MSTCOST() {
        long long cost = 0;
        sort(edges.begin(), edges.end());

        DSU dsu;

        for(auto edge: edges) {
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(dsu.find_set(u) == dsu.find_set(v)) continue;

            cost += w;
            dsu.union_set(u, v);
        }

        return cost;

    }

};

int main() {
    return 0;
}