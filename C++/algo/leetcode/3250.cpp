#include <bits/stdc++.h>
using namespace std;

// 3250. Find the Count of Monotonic Pairs I [H]
// LeetCode find-the-count-of-monotonic-pairs-i

int MOD = 1e9 + 7;
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, vector(51, -1));
        auto dfs = [&] (this auto&& dfs, int i, int prev1) {
            if(i == n) return 1;
            if(memo[i][prev1] != -1) return memo[i][prev1];
            long long ans = 0;
            int a = prev1, b = nums[i] - a;
            int prev2 = i == 0 ? 50 : nums[i - 1] - prev1;
            while(b > prev2) {
                a += 1;
                b -= 1;
            }
            while(b >= 0) {
                ans = (ans + dfs(i + 1, a)) % MOD;
                a += 1;
                b -= 1;
            }
            return memo[i][prev1] = ans;
        };

        return dfs(0, 0);
    }
};