#include <bits/stdc++.h>
using namespace std;

// 39. Combination Sum [M]
// LeetCode combination-sum

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int prev, int cur, vector<int>& temp) {
        if(cur >= target) {
            if(cur == target) ans.push_back(temp);
            return;
        }
        for(int i = prev; i < candidates.size(); i ++) {
            int num = candidates[i];
            temp.push_back(num);
            dfs(candidates, target, i, cur + num, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, target,0, 0, temp);
        return ans;
    }
};