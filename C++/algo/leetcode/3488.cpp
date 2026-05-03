#include <bits/stdc++.h>
using namespace std;

// 3488. Closest Equal Element Queries [M]
// LeetCode closest-equal-element-queries

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < nums.size(); i++) dict[nums[i]].push_back(i);
        for (auto& [val, indices] : dict) {
            int first = indices.front();
            indices.insert(indices.begin(), indices.back() - nums.size()); 
            indices.push_back(first + nums.size());
        }
        
        for(int q : queries) {
            int target = nums[q];
            auto& indices = dict[target];
            if (indices.size() == 3) {
                ans.push_back(-1);
                continue;
            }
            auto pos = lower_bound(indices.begin(), indices.end(), q) - indices.begin();
            int left_dist = q - indices[pos-1];
            int right_dist = indices[pos+1] - q;
            ans.push_back(min(left_dist, right_dist));
        }
        
        return ans;
    }
};