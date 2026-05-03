#include <bits/stdc++.h>
using namespace std;

// 78. Subsets [M]
// LeetCode subsets

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int pos, vector<int>& cur) {
        ans.push_back(cur);
        if(nums.size() == pos) return;
        for(int i = pos; i < nums.size(); i ++) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, 0, temp);
        return ans;
    }
};