#include <bits/stdc++.h>
using namespace std;

// 3346. Maximum Frequency of an Element After Performing Operations I [M]
// LeetCode maximum-frequency-of-an-element-after-performing-operations-i

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> diff;
        for(int x : nums) {
            cnt[x] += 1;
            diff[x];
            diff[x - k] += 1;
            diff[x + k + 1] -= 1;
        }
        int sum = 0, ans = 0;
        for(auto& [x, d] : diff) {
            sum += d;
            ans = max(ans, cnt[x] + min(sum - cnt[x], numOperations));
        }
        return ans;
    }
};