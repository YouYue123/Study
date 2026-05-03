#include <bits/stdc++.h>
using namespace std;

// 2104. Sum of Subarray Ranges [M]
// LeetCode sum-of-subarray-ranges

class Solution {
public:
    long long contrib(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n, -1);
        vector<long long> right(n, n);
        stack<int> monoSt;
        for(int i = 0; i < n; i ++) {
            while(!monoSt.empty() && nums[monoSt.top()] < nums[i]) {
                right[monoSt.top()] = i;
                monoSt.pop();
            }
            if(!monoSt.empty()) left[i] = monoSt.top();
            monoSt.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i ++) {
            ans += (i - left[i]) * (right[i] - i) * nums[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans = contrib(nums);
        for(int i = 0; i < nums.size(); i ++) nums[i] = -nums[i];
        ans += contrib(nums);
        return ans;
    }
};