#include <bits/stdc++.h>
using namespace std;

// 1027. Longest Arithmetic Subsequence [M]
// LeetCode longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1; 
        int maxEle = *max_element(nums.begin(), nums.end());
        for(int diff = -maxEle; diff <= maxEle; diff ++) {
            unordered_map<int, int> f;
            for(int num : nums) {
                if(f.contains(num - diff)) f[num] = f[num - diff] + 1;
                else f[num] = 1;
                ans = max(ans, f[num]);
            }
        }
        return ans;
    }
};