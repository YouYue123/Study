#include <bits/stdc++.h>
using namespace std;

// 2065. Maximum Path Quality of a Graph [H]
// LeetCode maximum-path-quality-of-a-graph

struct Edge {
    int to;
    int time;
};
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<Edge>> g(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], time = e[2];
            g[u].emplace_back(v, time);
            g[v].emplace_back(u, time);
        }
        vector<int> visit(n, 0);
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, int i, int time, int sum) -> void{
            if(time < 0) return;
            if(i == 0) ans = max(ans, sum);
            for(auto nxt : g[i]) {
                int nxt_sum = visit[nxt.to] != 0 ? sum : sum + values[nxt.to];
                int nxt_time = time - nxt.time;
                visit[nxt.to] += 1;
                dfs(nxt.to, nxt_time, nxt_sum);
                visit[nxt.to] -= 1;
            }
        };
        visit[0] += 1;
        dfs(0, maxTime, values[0]);
        return ans;
    }
};