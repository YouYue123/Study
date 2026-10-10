#include <bits/stdc++.h>
using namespace std;

// 90. Subsets II [M]
// LeetCode subsets-ii

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int>& cur, int start) {
        ans.push_back(cur);
        for(int i = start; i < nums.size(); i ++) {
            if(i > start && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            dfs(nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, cur, 0);
        return ans;
    }
};