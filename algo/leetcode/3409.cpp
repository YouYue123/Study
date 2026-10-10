#include <bits/stdc++.h>
using namespace std;

// 3409. Longest Subsequence With Decreasing Adjacent Difference [M]
// LeetCode longest-subsequence-with-decreasing-adjacent-difference

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int dict[10000][300] = {};
        for(int num : nums) {
            int prevMax = 0;
            int tmp[300] = {};
            for(int d = 299; d >= 0; d --) {
                int ht = num + d, lt = num - d;
                if(ht <= 300) prevMax = max(prevMax, dict[ht][d]);
                if(lt >= 1) prevMax = max(prevMax, dict[lt][d]);
                tmp[d] = max(
                    tmp[d],
                    prevMax + 1
                );
            }
            for(int d = 0; d < 300; d ++) {
                dict[num][d] = max(dict[num][d], tmp[d]);
                ans = max(ans, dict[num][d]);
            }
        }
        return ans;
    }
};