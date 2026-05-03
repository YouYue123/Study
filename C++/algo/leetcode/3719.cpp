#include <bits/stdc++.h>
using namespace std;

// 3719. Longest Balanced Subarray I [M]
// LeetCode longest-balanced-subarray-i

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int left = 0; left < n; left ++) {
            int oddCnt = 0, evenCnt = 0;
            unordered_map<int, int> freq;
            freq[nums[left]] += 1;
            if(nums[left] % 2 == 0) evenCnt += 1;
            else oddCnt += 1;
            for(int right = left + 1; right < n; right ++) {
                freq[nums[right]] += 1;
                if(freq[nums[right]] == 1) {
                    if(nums[right] % 2 == 0) evenCnt += 1;
                    else oddCnt += 1;
                }
                if(oddCnt == evenCnt) {
                    ans = max(ans, right - left + 1);
                }
            }
        }
        return ans;
    }
};