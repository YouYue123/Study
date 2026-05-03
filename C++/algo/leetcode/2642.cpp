#include <bits/stdc++.h>
using namespace std;

// 2642. Design Graph With Shortest Path Calculator [H]
// LeetCode design-graph-with-shortest-path-calculator

int constexpr INF = 0x3f3f3f3f;
struct Edge {
    int to;
    int cost;
};
struct Node {
    int id;
    int cost;
    bool operator >(const Node& other) const {
        return cost > other.cost;
    }
};
class Graph {
private:
    int n;
    vector<vector<Edge>> g;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.resize(n);
        for(auto& e : edges) {
            int from = e[0], to = e[1], cost = e[2];
            g[from].emplace_back(to, cost);
        }
    }
    
    void addEdge(vector<int> edge) {
        int from = edge[0], to = edge[1], cost = edge[2];
        g[from].emplace_back(to, cost);
    }
    
    int shortestPath(int node1, int node2) {
        vector dist(n, INF);
        priority_queue<Node, vector<Node>, greater<>> pq;
        pq.emplace(node1, 0);
        dist[node1] = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.id == node2) break;
            if(dist[cur.id] < cur.cost) continue;
            for(auto& nxt : g[cur.id]) {
                int nxt_id = nxt.to;
                int nxt_cost = cur.cost + nxt.cost;
                if(dist[nxt_id] <= nxt_cost) continue;
                dist[nxt_id] = nxt_cost;
                pq.emplace(nxt_id, nxt_cost);
            }
        }
        // cout << dist[node2] << endl;
        return dist[node2] == INF ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */