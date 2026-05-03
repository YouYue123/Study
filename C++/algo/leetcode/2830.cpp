// 2830. Maximize the Profit as the Salesman [M]
// LeetCode maximize-the-profit-as-the-salesman

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(), offers.end());
        vector memo(m, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == m) return 0;
            if(memo[i] != -1) return memo[i];
            auto& offer = offers[i];
            int ans = dfs(i + 1);
            int left = i + 1, right = m - 1, idx = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(offers[mid][0] > offer[1]) {
                    right = mid - 1;
                    idx = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(idx != -1) ans = max(ans, dfs(idx) + offer[2]);
            ans = max(ans, offer[2]);
            return memo[i] = ans;
        };
        return dfs(0);
    }
};