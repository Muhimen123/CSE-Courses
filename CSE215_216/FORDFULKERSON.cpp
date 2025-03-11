#include <bits/stdc++.h>
using namespace std;

const int V = 6;
int source;
int sink;

int bfs(int graph[V][V], int parent[]) {
    queue<int> q;
    q.push(source);


    vector<bool> vis = vector<bool>(V, false);
    vector<int> dis = vector<int>(V, 0);

    vis[source] = true;

    while(q.size()) {
        int i = q.front();
        q.pop();
        for(int j = 0; j < V; j++) {
            if(i == j) continue;

            if(graph[i][j] != 0 and !vis[j]) {
                vis[j] = true;
                dis[j] = dis[i] + 1;
                parent[j] = i;
                q.push(j);
            }
        }
    } 

    return vis[sink];
}

int fordFulkerson(int graph[V][V], int s, int t) {
    source = s;
    sink = t;

    int resGraph[V][V];
    for(int i = 0; i < V; i++)
    for(int j = 0; j < V; j++)
        resGraph[i][j] = graph[i][j];

    int parent[V];

    int max_flow = 0;

    int u;
    int ans = 0;
    while(bfs(resGraph, parent)) {
        int res_cap = 1e9;
        
        for(int v = sink; v != source; v = parent[v]) {
            u = parent[v];
            res_cap = min(res_cap, resGraph[u][v]);
        }

        for(int v = sink; v != source; v = parent[v]) {
            u = parent[v];
            resGraph[u][v] -= res_cap;
            resGraph[v][u] += res_cap;
        }
        // cerr << res_cap << " ";
        ans += res_cap;
    }

    return ans;
}

int main() {

    int graph[6][6] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    source = 0;
    sink = V - 1;

    int ans = fordFulkerson(graph, source, sink);
    cout << ans << endl;

    return 0;
}