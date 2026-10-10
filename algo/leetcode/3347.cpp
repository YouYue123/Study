#include <bits/stdc++.h>
using namespace std;

// 3347. Maximum Frequency of an Element After Performing Operations II [H]
// LeetCode maximum-frequency-of-an-element-after-performing-operations-ii

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> diff;
        for(int num : nums) {
            cnt[num] += 1;
            diff[num];
            diff[num - k] += 1;
            diff[num + k + 1] -= 1;
        }
        int ans = 0;
        int sumDiff = 0;
        for(auto & [num, d] : diff) {
            sumDiff += d;
            ans = max(ans, cnt[num] + min(sumDiff - cnt[num], numOperations));
        }
        return ans;
    }
};