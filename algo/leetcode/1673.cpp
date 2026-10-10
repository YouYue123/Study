#include <bits/stdc++.h>
using namespace std;

// 1673. Find the Most Competitive Subsequence [M]
// LeetCode find-the-most-competitive-subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> monoSt;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++) {
            int remaining = nums.size() - i;
            while(!monoSt.empty() && monoSt.top() > nums[i] && remaining + monoSt.size() > k) {
                monoSt.pop();
            }
            monoSt.push(nums[i]);
        }
        while(!monoSt.empty()) {
            ans.push_back(monoSt.top());
            monoSt.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > k) ans.pop_back();
        return ans;
    }
};