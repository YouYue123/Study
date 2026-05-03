#include <bits/stdc++.h>
using namespace std;

// 1980. Find Unique Binary String [M]
// LeetCode find-unique-binary-string

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        //cantour diagnal
        int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; i ++) {
            if(nums[i][i] == '0') ans += '1';
            else ans += '0';
        }
        return ans;
    }
};