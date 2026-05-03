#include <bits/stdc++.h>
using namespace std;

// 3910. Count Connected Subgraphs with Even Node Sum [H]
// LeetCode count-connected-subgraphs-with-even-node-sum

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> g;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        unordered_set<int> seen;
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, int mask, int sum) {
            if(seen.contains(mask)) return;
            seen.insert(mask);
            if(sum == 0) ans += 1;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) { // 找到子图已有的节点
                    for (int nxt : g[i]) {
                        if (!((mask >> nxt) & 1)) { // 邻居不在子图中
                            dfs(mask | (1 << nxt), sum ^ nums[nxt]);
                        }
                    }
                }
            }
            return;
        };
        for(int i = 0; i < n; i ++) {
            dfs(1 << i, nums[i]);
        }
        return ans;
    }
};