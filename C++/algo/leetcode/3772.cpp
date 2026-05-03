#include <bits/stdc++.h>
using namespace std;

// 3772. Maximum Subgraph Score in a Tree [H]
// LeetCode maximum-subgraph-score-in-a-tree

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        unordered_map<int, vector<int>> g;
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> vals(n);
        for(int i = 0; i < n; i ++) vals[i] = good[i] == 1 ? 1 : -1;
        vector<int> down(n);
        auto dfs1 = [&] (this auto&& dfs, int i, int fa) -> int {
            down[i] = vals[i];
            for(int ni : g[i]) {
                if(ni == fa) continue;
                   int childScore = dfs(ni, i);
                   down[i] += max(0, childScore);
            }
            return down[i];
        };
        dfs1(0, -1);
        vector<int> up(n);
        vector<int> ans(n);
        auto dfs2 = [&] (this auto&& dfs, int i, int fa) -> void {
            ans[i] = down[i] + max(0, up[i]);
            int childContrib = 0;
            for(int ni : g[i]) {
                if(ni == fa) continue;
                childContrib += max(0, down[ni]);
            }
            for(int ni : g[i]) {
                if(ni == fa) continue;
                int otherContrib = childContrib - max(0, down[ni]);
                int best = vals[i] + max(0, up[i]) + otherContrib;
                up[ni] = best;
                dfs(ni, i);
            }
        };
        dfs2(0, -1);
     
        return ans;
    }
};