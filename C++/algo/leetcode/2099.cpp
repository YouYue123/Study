#include <bits/stdc++.h>
using namespace std;

// 2099. Find Subsequence of Length K With the Largest Sum [E]
// LeetCode find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if(nums.size() < k) return {};
        vector<pair<int, int>> pairs;
        for(int i = 0; i < nums.size(); i ++) {
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end(), greater<>());
        sort(pairs.begin(), pairs.begin() + k, [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second < p2.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i ++) {
            ans.push_back(pairs[i].first);
        }
        return ans;
    }
};