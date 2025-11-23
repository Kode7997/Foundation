// Dijkstra's algorithm for shortest path in a graph
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to, weight;
};

vector<int> dijkstra(int n, vector<vector<Edge>>& graph, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& e : graph[u]) {
            if (dist[e.to] > dist[u] + e.weight) {
                dist[e.to] = dist[u] + e.weight;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n);
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({0, 7});
    graph[3].push_back({2, 6});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});
    vector<int> dist = dijkstra(n, graph, 0);
    for (int d : dist) cout << d << " ";
    cout << endl;
    return 0;
}
