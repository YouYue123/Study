#include <bits/stdc++.h>
using namespace std;

// 3736. Minimum Moves to Equal Array Elements III [E]
// LeetCode minimum-moves-to-equal-array-elements-iii

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums) ans += maxEle - num;
        return ans;
    }
};