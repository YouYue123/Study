#include <bits/stdc++.h>
using namespace std;

// 3191. Minimum Operations to Make Binary Array Elements Equal to One I [M]
// LeetCode minimum-operations-to-make-binary-array-elements-equal-to-one-i

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // if only 3 , possible: 111, 000
        // if only 4 ,possible: 1000, 1111, 0001
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            // for(int k = 0; k < nums.size(); k++) {
            //     cout << nums[k] << " ";
            // }
            // cout << endl;
            if(nums[i] == 0) {
                for(int j = 0; j < 3; j ++) {
                    if(i + j >= nums.size()) return -1;
                    nums[i + j] = nums[i + j] == 0 ? 1 : 0; 
                }
                ans += 1;
            }
        }
        // 100100
        // 111000
        // 111111
        return ans;
    }
};