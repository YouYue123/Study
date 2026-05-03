// 2008. Maximum Earnings From Taxi [M]
// LeetCode maximum-earnings-from-taxi

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int m = rides.size();
        vector memo(m, -1LL);
        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if(i == m) return 0LL;
            if(memo[i] != -1) return memo[i];
            auto& ride = rides[i];
            long long s = ride[0], e = ride[1], t = ride[2];
            long long ans = dfs(i + 1);
            int left = i + 1, right = m - 1, idx = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(rides[mid][0] >= e) {
                    right = mid - 1;
                    idx = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(idx != -1) ans = max(ans, dfs(idx) + e - s + t);
            ans = max(ans, e - s + t);
            return memo[i] = ans;
        };
        return dfs(0);
    }
};