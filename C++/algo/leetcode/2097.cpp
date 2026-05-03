#include <bits/stdc++.h>
using namespace std;

// 2097. Valid Arrangement of Pairs [H]
// LeetCode valid-arrangement-of-pairs

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> degree;
        int start_candidate = -1;
        for(auto& p : pairs) {
            int start = p[0], end = p[1];
            g[start].push_back(end);
            degree[end] -= 1;
            degree[start] += 1;
        }
        for(auto& p : pairs) {
            if(degree[p[0]] > 0) {
                start_candidate = p[0];
                break;
            }
        }
        if(start_candidate == -1) start_candidate = pairs[0][0];
        vector<int> path;
        vector<vector<int>> ans;
        auto dfs = [&] (this auto&& dfs, int cur, int prev) -> void {
            while(!g[cur].empty()) {
                int nxt = g[cur].back();
                g[cur].pop_back();
                dfs(nxt, cur);
            }
            if(prev != -1) ans.push_back({ prev, cur });
        };
        dfs(start_candidate, -1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};