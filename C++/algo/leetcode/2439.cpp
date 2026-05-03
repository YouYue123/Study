#include <bits/stdc++.h>
using namespace std;

// 2439. Minimize Maximum of Array [M]
// LeetCode minimize-maximum-of-array

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        auto isValid = [&](long long x) {
            long long extra = 0;
            for(int i = nums.size() - 1; i > 0; i --) {
                extra = max(0LL, (long long)nums[i] + extra - x);
            }
            return (long long)nums[0] + extra <= x;
        };
        long long left = *min_element(nums.begin(), nums.end());
        long long right = *max_element(nums.begin(), nums.end()) + 1;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};