#include <bits/stdc++.h>
using namespace std;

// 55. Jump Game [M]
// LeetCode jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur_max = 0;
        for(int i = 0; i < n; i ++) {
            if(cur_max < i) break;
            cur_max = max(cur_max, i + nums[i]);
        }
        return cur_max >= n - 1;
    }
};