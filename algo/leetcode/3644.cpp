#include <bits/stdc++.h>
using namespace std;

// 3644. Maximum K to Sort a Permutation [M]
// LeetCode maximum-k-to-sort-a-permutation

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 0 ; i < nums.size(); i ++) {
            int num = nums[i];
            if(num != i) {
                if(ans == INT_MIN) {
                    ans = num & i;   
                } else {
                    ans &= num & i;
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};