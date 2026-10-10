#include <bits/stdc++.h>
using namespace std;

// 3201. Find the Maximum Length of Valid Subsequence I [M]
// LeetCode find-the-maximum-length-of-valid-subsequence-i

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for(auto& p: patterns) {
            int cnt = 0;
            for(int num : nums) {
                if (num % 2 == p[cnt % 2]) cnt += 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};