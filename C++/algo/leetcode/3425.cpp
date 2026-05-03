// 3425. Longest Special Path [H]
// LeetCode longest-special-path



class Solution {
public:
    int ans = 0;
    int minPath = 1e9;
    vector<int> path, a;
    int par_cost[50007];
    vector<array<int, 2>> adj[50007];
    vector<int> dup[50007];

    void dfs(int u, int p, int l = 0, int len = 0, int w = 0, int depth = 0,
             int max_valid = 0) {
        len += w; 
        path.push_back(len); 
        int last = -1; 
        if (dup[a[u]].size() != 0) {
            last = max(dup[a[u]].back(), max_valid - 1);
        }
        max_valid = max(max_valid, last + 1);
        int sum = path.back() - path[max_valid];
        if (ans < sum) {
            minPath = path.size() - max_valid;
            ans = sum;
        } else if (ans == sum) {
            minPath = min(minPath, (int)path.size() - max_valid);
        }
        dup[a[u]].push_back(depth);
        for (auto [v, tw] : adj[u]) {
            if (v == p)
                continue;
            par_cost[v] = tw;
            dfs(v, u, l, len, tw, depth + 1, max_valid);
        }
        dup[a[u]].pop_back();
        path.pop_back();
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges,
                                   vector<int>& nums) {
        int n = nums.size();
        a = nums;
        for (auto c : edges) {
            adj[c[0]].push_back({c[1], c[2]});
            adj[c[1]].push_back({c[0], c[2]});
        }
        dfs(0, 0);
        return {ans, minPath};
    }
};