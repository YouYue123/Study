// 465. Optimal Account Balancing [H]
// LeetCode optimal-account-balancing

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> accounts;
        vector<int> g;
        for(auto& t : transactions) {
            int from = t[0], to = t[1], amount = t[2];
            accounts[from] -= amount;
            accounts[to] += amount;
        }
        for(auto& [idx, amount] : accounts) {
            if(amount != 0) g.push_back(amount);
        }
        int n = g.size();
        vector memo(1 << n, -1);
        auto dfs = [&] (this auto&& dfs, int mask) {
            if(mask == 0) return 0;
            if(memo[mask] != -1) return memo[mask];
            int ans = 0;
            int balance = 0;
            for(int i = 0; i < n; i ++) {
                int curMask = 1 << i;
                if(mask & curMask) {
                    balance += g[i];
                    ans = max(ans, dfs(mask ^ curMask));
                }
            }
            return memo[mask] = ans + (balance == 0 ? 1 : 0);
        };
        return n - dfs((1 << n) - 1);
    }
};