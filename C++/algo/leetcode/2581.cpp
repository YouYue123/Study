// 2581. Count Number of Possible Root Nodes [H]
// LeetCode count-number-of-possible-root-nodes

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> g;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        set<pair<int, int>> guess_dict;
        for(auto& guess : guesses) {
            int u = guess[0], v = guess[1];
            guess_dict.emplace(u, v);
        }
        vector<int> dp(n, 0);
        auto calc_root = [&] (this auto&& dfs, int cur, int parent) -> void {
            for(auto nxt : g[cur]) {
                if(nxt == parent) continue;
                if(guess_dict.contains(make_pair(cur, nxt))) dp[0] += 1;
                dfs(nxt, cur);
            }
        };
        calc_root(0, -1);
        int ans = 0;
        auto reroot = [&] (this auto&& dfs, int cur, int parent) -> void {
            for(auto nxt : g[cur]) {
                if(nxt == parent) continue;
                int delta = 0;
                bool is_cur_valid_guess = guess_dict.contains(make_pair(cur, nxt));
                bool is_nxt_valid_guess = guess_dict.contains(make_pair(nxt, cur));
                if(is_cur_valid_guess) delta -= 1;
                if(is_nxt_valid_guess) delta += 1;
                dp[nxt] = dp[cur] + delta;
                dfs(nxt, cur);
            }
            // if(dp[cur] >= k) ans += 1;
        };
        reroot(0, -1);
        for(int i = 0; i < n; i ++) {
            if(dp[i] >= k) ans += 1;
        }
        return ans;
    }
};