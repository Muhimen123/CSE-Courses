#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n);

    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<vector<pair<int, int>>> MST;
    vector<bool> visited(n, false);
    int cost = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<>> pq;

    pq.push({0, 0}); // starting with 0 node

    while(pq.size()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;
        cost += weight;

        for(auto v: graph[u]) {
            pq.push({v.second, v.first});
        }
    }

}