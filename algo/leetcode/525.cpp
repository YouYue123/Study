#include <bits/stdc++.h>
using namespace std;

// 525. Contiguous Array [M]
// LeetCode contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int curSum = 0;
        int ans = 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            curSum += num == 0 ? -1 : 1;
            // cout << curSum << " ";
            if(dict.contains(curSum)) {
                ans = max(ans, i - dict[curSum]);
            } else {
                dict[curSum] = i;
            }
        }
        return ans;
    }
};