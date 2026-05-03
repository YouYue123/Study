#include <bits/stdc++.h>
using namespace std;

// 1589. Maximum Sum Obtained of Any Permutation [M]
// LeetCode maximum-sum-obtained-of-any-permutation

int MOD = 1e9 + 7;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> diff(nums.size() + 1, 0);
        for(auto& r: requests) {
            diff[r[0]] += 1;
            diff[r[1] + 1] -= 1;
        }
        int cur = 0;
        vector<int> cnt;
        for(int i = 0; i < nums.size(); i ++) {
            cur += diff[i];
            cnt.push_back(cur);
        }
        sort(cnt.begin(), cnt.end(), greater<>());
        sort(nums.begin(), nums.end(), greater<>());
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            ans = ((long long)ans + ((long long)nums[i] * cnt[i]) % MOD) % MOD;
        }
        return ans;
    }
};