#include <bits/stdc++.h>
using namespace std;

// 2958. Length of Longest Subarray With at Most K Frequency [M]
// LeetCode length-of-longest-subarray-with-at-most-k-frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int left = 0, right = 0;
        int ans = 0;
        while(right < nums.size()) {
            dict[nums[right]] += 1;
            while(dict[nums[right]] > k) {
                dict[nums[left]] -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};