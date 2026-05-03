#include <bits/stdc++.h>
using namespace std;

// 797. All Paths From Source to Target [M]
// LeetCode all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector visited(n, false);
        vector<vector<int>> ans;
        auto dfs = [&] (this auto&& dfs, int i, vector<int>& path) {
            if(i == n - 1) {
                ans.push_back(path);
                return;
            }
            for(int nxt : graph[i]) {
                // if(visited[nxt]) continue;
                // visited[nxt] = true;
                path.push_back(nxt);
                dfs(nxt, path);
                path.pop_back();
                // visited[nxt] = false;
            }
        };
        vector<int> tmp;
        tmp.push_back(0);
        dfs(0, tmp);
        return ans;
    }
};