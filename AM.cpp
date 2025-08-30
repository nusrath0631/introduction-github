#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    // Graph as adjacency list
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w}); // undirected
    }

    // Distance and parent arrays
    vector<long long> dist(n+1, INF);
    vector<int> parent(n+1, -1);

    // Min-heap for Dijkstra
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // If no path to n
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }

    // Reconstruct path
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    // Print path
    for (int v : path) {
        cout << v << " ";
    }

    return 0;
}

