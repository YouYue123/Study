#include <bits/stdc++.h>
using namespace std;

// 300. Longest Increasing Subsequence [M]
// LeetCode longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> g;
        for(int num : nums) {
            auto it = lower_bound(g.begin(), g.end(), num);
            if(it == g.end()) {
                g.push_back(num);
            } else {
                *it = num;
            }
        }
        return g.size();
    }
};