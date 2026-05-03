#include <bits/stdc++.h>
using namespace std;

// 1658. Minimum Operations to Reduce X to Zero [M]
// LeetCode minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum  = 0;
        for(int num : nums) sum += num;
        int target = sum - x;
        if(target < 0) return -1;
        int left = 0, right = 0;
        int ans = INT_MAX;
        sum = 0;
        // cout << target << endl;
        while(right < nums.size()) {
            sum += nums[right];
            while(sum > target) {
                sum -= nums[left];
                left += 1;
            }
            if(sum == target) {
                int amount = right - left + 1;
                ans = min(ans, (int)nums.size() - amount);
            }
            right += 1;
        }
        return ans == INT_MAX ? - 1: ans;
    }
};