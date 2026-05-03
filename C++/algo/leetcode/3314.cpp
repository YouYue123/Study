#include <bits/stdc++.h>
using namespace std;

// 3314. Construct the Minimum Bitwise Array I [E]
// LeetCode construct-the-minimum-bitwise-array-i

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums) {
            int cur = -1;
            if(num % 2 == 0) {
                ans.push_back(-1);
            }  else {
                int t = ~num;
                ans.push_back(num ^ ((t & -t) >> 1));
            }
        }
        return ans;
    }
};