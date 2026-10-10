#include <bits/stdc++.h>
using namespace std;

// 2461. Maximum Sum of Distinct Subarrays With Length K [M]
// LeetCode maximum-sum-of-distinct-subarrays-with-length-k

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0, right = 0;
        long long sum = 0;
        long long ans = 0;
        int distincCount = 0;
        unordered_map<int, int> count;
        while(right < nums.size()) {
            sum += nums[right];
            count[nums[right]] += 1;
            if(count[nums[right]] == 1) distincCount += 1;
            if(right - left + 1 > k) {
                sum -= nums[left];
                count[nums[left]] -= 1;
                if(count[nums[left]] == 0) distincCount -= 1;
                left += 1;
            }
            if(right - left + 1 == k && distincCount == k) {
                ans = max(ans, sum);
            }
            right += 1;
        }
        return ans;
    }
};