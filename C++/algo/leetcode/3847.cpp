#include <bits/stdc++.h>
using namespace std;

// 3847. Find the Score Difference in a Game [M]
// LeetCode find-the-score-difference-in-a-game

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int players[2] = {0, 0};
        int cur = 0;
        for(int i = 0; i < n; i ++) {
            // players[nums[i] % 2
            if(nums[i] % 2 == 1) cur ^= 1;
            if(i % 6 == 5) cur ^= 1;
            // cout << i << " " << cur << " " << endl;
            players[cur] += nums[i];
        }
        return players[0] - players[1];
    }
};