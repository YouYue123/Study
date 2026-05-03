#include <bits/stdc++.h>
using namespace std;

// 3469. Find Minimum Cost to Remove Array Elements [M]
// LeetCode find-minimum-cost-to-remove-array-elements

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return *max_element(nums.begin(), nums.end());
        // j [i ..., n - 1]
        vector memo(n, vector(n , -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == n - 1) return max(nums[i], nums[j]);
            if(i == n) return nums[j];
            if(memo[i][j] != -1) return memo[i][j]; 
            int ans = INF;
            // Remove i, i + 1
            ans = min(ans, dfs(i + 2, j) + max(nums[i], nums[i + 1]));
            // Remove j, i
            ans = min(ans, dfs(i + 2, i + 1) + max(nums[j], nums[i]));
            // Remove j, i + 1
            ans = min(ans, dfs(i + 2, i) + max(nums[j], nums[i + 1]));
            return memo[i][j] = ans;
        };

        return dfs(1, 0);
    }
};