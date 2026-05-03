// 3559. Number of Ways to Assign Edge Weights II [H]
// LeetCode number-of-ways-to-assign-edge-weights-ii

constexpr int MOD = 1e9 + 7;

int modMult(int a, int b, int mod = MOD) {
    return ((long long)(a) * b) % mod;
}

int modPow(int base, int exp, int mod = MOD) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result = modMult(result, base);
        }
        exp /= 2;
        base = modMult(base, base);
    }

    return result;
}

class Solution {
public:
    int LOG = 17;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> depth;
    vector<vector<int>> up;
    void dfs(int v, int p) {
        up[0][v] = p;
        for(int w : graph[v]) {
            if(w!= p) {
                depth[w] = depth[v] + 1;
                dfs(w, v);
            }
        }
    }
    int lca(int a, int b) {
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for(int k = 0; k < LOG; k ++) {
            if(diff & (1 <<k)) a = up[k][a];
        }
        if(a == b) return a;
        for(int k = LOG - 1; k >= 0; k--) {
            if(up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        up.assign(LOG, vector<int>(n + 1, 0));
        dfs(1, 1);
        for(int k = 1; k < LOG; k ++) {
            for (int v = 1; v <= n; ++v) {
                up[k][v] = up[k - 1][up[k-1][v]];
            }
        }
        vector<int> ans;
        for(auto& q : queries) {
            int u = q[0], v = q[1];
            int w = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[w];
            if(dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(modPow(2, dist - 1));
            }
        }
        return ans;
    }
};