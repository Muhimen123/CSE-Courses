// https://www.codechef.com/learn/course/college-design-analysis-algorithms/CPDAA26/problems/DAA140

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

const int N = 3e5;
ll par[N];
ll Size[N];

void make_set(int i) {
    par[i] = i;
    Size[i] = 1;
} 

ll find_set(int i) {
    if(i == par[i]) return i;
    return par[i] = find_set(par[i]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);

    if(u == v) return;

    if(Size[u] > Size[v]) swap(u, v);

    par[v] = u;
    Size[u] += Size[v];
}

int main() {
    SIC_PARVIS_MAGNA;
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> edges;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    for(int i = 0; i <= n; i++) make_set(i);

    sort(all(edges));
    ll cost = 0;
    for(auto edge: edges) {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];
        if(find_set(u) == find_set(v)) continue;
        
        cost += w;
        union_set(u, v);
    }

    cout << cost << el;



    return 0;
}