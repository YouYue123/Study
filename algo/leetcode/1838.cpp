#include <bits/stdc++.h>
using namespace std;

// 1838. Frequency of the Most Frequent Element [M]
// LeetCode frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int ans = 0;
        long sum = 0;
        while(right < nums.size()) {
            long target = nums[right];
            sum += target;
            while((right - left + 1) * target - sum > k) {
                sum -= nums[left];
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};