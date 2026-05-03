// 3553. Minimum Weighted Subgraph With the Required Paths II [H]
// LeetCode minimum-weighted-subgraph-with-the-required-paths-ii

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        int LOG = 17;
        vector<vector<int>> parent(LOG, vector<int>(n, -1));
        vector<int> depth(n, 0);
        vector<int> dist(n, 0);
        stack<int> st;
        st.push(0);
        parent[0][0] = -1;
        while (!st.empty()) {
            int u = st.top(); 
            st.pop();
            for (auto &pr : adj[u]) {
                int v = pr.first, w = pr.second;
                if (v == parent[0][u]) continue;
                parent[0][v] = u;
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + w;
                st.push(v);
            }
        }
        
        for (int k = 1; k < LOG; ++k) {
            for (int u = 0; u < n; ++u) {
                int p = parent[k-1][u];
                parent[k][u] = (p < 0 ? -1 : parent[k-1][p]);
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; ++k) {
                if (diff & (1 << k)) u = parent[k][u]; 
            }
            if (u == v) return u;
            for (int k = LOG-1; k >= 0; --k) {
                if (parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            return parent[0][u];
        };

        auto getDist = [&](int u, int v) {
            int a = lca(u, v);
            return dist[u] + dist[v] - 2 * dist[a];
        };

        vector<int> answer;
        answer.reserve(queries.size());
        for (auto &q : queries) {
            int u = q[0], v = q[1], w = q[2];
            int duv = getDist(u, v);
            int dvw = getDist(v, w);
            int duw = getDist(u, w);
            // cout << duv << " " << dvw << " " << duw << endl;
            answer.push_back((duv + dvw + duw) / 2);
        }
        return answer;
    }
};
