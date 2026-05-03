#include <bits/stdc++.h>
using namespace std;

// 992. Subarrays with K Different Integers [H]
// LeetCode subarrays-with-k-different-integers

class Solution {
public:
    long long f(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int left = 0, right = 0;
        int ans = 0, cnt = 0;
        while(right < nums.size()) {
            dict[nums[right]] += 1;
            if(dict[nums[right]] == 1)  cnt += 1;
            while(cnt >= k) {
                dict[nums[left]] -= 1;
                if(dict[nums[left]] == 0) cnt -= 1;
                left += 1;
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k + 1);
    }
};