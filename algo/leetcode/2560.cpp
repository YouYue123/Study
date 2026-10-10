#include <bits/stdc++.h>
using namespace std;

// 2560. House Robber IV [M]
// LeetCode house-robber-iv

class Solution {
public:
    int dfs(int i, vector<int>& nums, int cap, vector<int>& memo) {
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int rob = 0;
        int notRob = 0;
        if(nums[i] <= cap) {
            rob = 1 + dfs(i + 2, nums, cap, memo);
        } else {
            notRob = dfs(i + 1, nums, cap, memo);
        }
        return memo[i] = max(rob, notRob);
    }
    int minCapability(vector<int>& nums, int k) {
        auto isValid = [&] (int x) {
            vector<int> memo(nums.size(), -1);
            int cnt = dfs(0, nums, x, memo);
            return cnt >= k;
        };
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end()) + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};