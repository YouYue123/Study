#include <bits/stdc++.h>
using namespace std;

// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph [M]
// LeetCode count-unreachable-pairs-of-nodes-in-an-undirected-graph

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector visit(n, false);
        unordered_map<int, vector<int>> g;
        for(auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        auto dfs = [&] (this auto&& dfs, int i) {
            if(visit[i]) return 0;
            visit[i] = true;
            int ans = 1;
            // cout << i << endl;
            for(int nxt : g[i]) {
                ans += dfs(nxt);
            }
            return ans;
        };
        vector<int> cnts;
        int total = 0;
        for(int i = 0; i < n; i ++) {
            if(!visit[i]) {
                int cnt = dfs(i);
                cnts.push_back(cnt);
                total += cnt;
            }
        }
        long long ans = 0;
        for(long long cnt : cnts) {
        //    cout << cnt << endl;
           total -= cnt;
           ans += total * cnt;
        }
        return ans;
    }
};