// 40. Combination Sum II [M]
// LeetCode combination-sum-ii

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, vector<int>& cur, int start) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(target < 0) return;
        for(int i = start; i < candidates.size(); i ++) {
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates,target, cur, 0);
        return ans;
    }
};