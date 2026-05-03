#include <bits/stdc++.h>
using namespace std;

// 2841. Maximum Sum of Almost Unique Subarray [M]
// LeetCode maximum-sum-of-almost-unique-subarray

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int left = 0, right = 0;
        int distincCount = 0;
        unordered_map<int, int> count;
        long long sum = 0;
        long long ans = 0;
    
        while(right < nums.size()) {
            count[nums[right]] += 1;
            if(count[nums[right]] == 1) distincCount += 1;
            sum += nums[right];
            if(right - left + 1 > k) {
                count[nums[left]] -= 1;
                sum -= nums[left];
                if(count[nums[left]] == 0) distincCount -= 1;
                left += 1;
            }
            if(right - left + 1 == k && distincCount >= m) {
                ans = max(ans, sum);
            } 
            // cout << distincCount << endl;
            // cout << left << " " << right << endl;
            // cout << ans << endl;
            right += 1;
        }
        return ans;
    }
};