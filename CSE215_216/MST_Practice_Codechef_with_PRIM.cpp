#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/vortex/Development/debug.h"
#else
#define debug(x...)
#endif

#define el '\n'
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SIC_PARVIS_MAGNA ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FileIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define yes cout << "Yes" << el
#define no cout << "No" << el
#define Yes cout << "YES" << el
#define No cout << "NO" << el

int main() {
    SIC_PARVIS_MAGNA;
    ll n, m;
    cin >> n >> m;

    using pii = pair<int, int>;
    vector<vector<pii>> graph(n+1);
    vector<bool> visited(n+1, false);

    ll u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 1});

    ll cost = 0;
    while(pq.size()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if(visited[vertex]) continue;
        cost += weight;

        visited[vertex] = true;
        for(auto child: graph[vertex]) {
            if(!visited[child.first])
            pq.push({child.second, child.first});
        }
    }

    cout << cost << el;

    return 0;
}