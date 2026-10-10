#include <bits/stdc++.h>
using namespace std;

// 1887. Reduction Operations to Make the Array Elements Equal [M]
// LeetCode reduction-operations-to-make-the-array-elements-equal

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int cnt = 0;
        int ans = 0;
        for(int i = 1; i < n ; i ++) {
            if(nums[i] != prev)  {
                prev = nums[i];
                cnt += 1;
            }
            ans += cnt;
        }
        return ans;
    }
};