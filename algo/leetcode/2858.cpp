#include <bits/stdc++.h>
using namespace std;

// 2858. Minimum Edge Reversals So Every Node Is Reachable [H]
// LeetCode minimum-edge-reversals-so-every-node-is-reachable

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> g;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].emplace_back(v, 0);
            g[v].emplace_back(u, 1);
        }
        vector<int> ans(n, 0);
        auto calc_root = [&] (this auto&& dfs, int cur, int parent) -> void {
            for(auto& [nxt, cost] : g[cur]) {
                if(nxt == parent) continue;
                dfs(nxt, cur);
                ans[cur] += ans[nxt] + cost;
            }
        };
        calc_root(0, -1);
        auto reroot = [&] (this auto&& dfs, int cur, int parent) -> void {
            for(auto& [nxt, cost] : g[cur]) {
                if(nxt == parent) continue;
                ans[nxt] = ans[cur] + (cost == 0 ? 1 : -1);
                dfs(nxt, cur);
            }
        };
        reroot(0, -1);
        return ans;
    }
};