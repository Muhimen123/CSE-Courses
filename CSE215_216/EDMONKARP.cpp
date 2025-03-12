#include <bits/stdc++.h>
using namespace std;

const int V = 6;
int source, sink;

bool bfs(int graph[V][V], int parent[]) {
    queue<int> q;
    q.push(source);

    parent[source] = -1;

    vector<bool> vis = vector<bool>(V, false);
    vis[source] = true;

    while(q.size()) {
        int i = q.front();
        q.pop();

        for(int j = 0; j < V; j++) {
            if(i == j) continue;
            if(graph[i][j] != 0 and !vis[j]) {
                vis[j] = true;
                q.push(j);
                parent[j] = i;
            }
        }
    }

    return vis[sink];
}

int edmon(int graph[V][V], int src, int snk) {
    source = src;
    sink = snk;

    int res[V][V];

    for(int i = 0; i < V; i++)
    for(int j = 0; j < V; j++)
        res[i][j] = graph[i][j];

    int parent[V];
    int max_flow = 0;

    while(bfs(res, parent)) {
        int u;
        int cur_max = 1e8;

        for(int v = sink; v != source; v = parent[v]) {
            u = parent[v];
            cur_max = min(cur_max, graph[u][v]);
        }

        for(int v = sink; v != source; v = parent[v]) {
            u = parent[v];

            res[u][v] -= cur_max;
            res[v][u] += cur_max;
        }
        max_flow += cur_max;
    }
    return max_flow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    source = 0;
    sink = V - 1;

    int ans = edmon(graph, source, sink);
    cout << ans << endl;
    return 0;
}