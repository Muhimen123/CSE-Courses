#define pii pair<ll, ll>
const ll INF = 1e17;
vector<vector<pii>> graph;
vector<ll> dist;

void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty()) {
        ll v = pq.top().second;
        ll d_v = pq.top().first;
        pq.pop();

        if(dist[v] < d_v) continue;

        for(auto u: graph[v]) {
            ll to = u.first;
            ll len = u.second;

            if(dist[to] > dist[v] + len) {
                dist[to] = dist[v] + len;
                pq.push({dist[to], to});
            }
        }
    }
}
