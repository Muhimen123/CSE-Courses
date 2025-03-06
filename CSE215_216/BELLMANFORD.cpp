// from chatgpt
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w; // Edge from u to v with weight w
};

const int INF = 1e9;

// Bellman-Ford algorithm with negative cycle detection
void bellmanFord(int V, int E, vector<Edge> &edges, int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Step 1: Relax all edges (V-1) times
    for (int i = 0; i < V - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Step 2: Check for negative weight cycle
    bool hasNegativeCycle = false;
    for (Edge e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle!\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << "\n";
        }
    }
}

int main() {
    int V = 5, E = 8;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, edges, 0);

    return 0;
}
