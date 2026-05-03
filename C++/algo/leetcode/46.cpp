// 46. Permutations [M]
// LeetCode permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        auto dfs = [&] (this auto&& dfs, vector<int> tmp, int state) {
            if(tmp.size() == n) {
                ans.push_back(tmp);
                return;
            }
            for(int j = 0; j < n; j ++) {
                if(state & (1 << j)) continue;
                tmp.push_back(nums[j]);
                dfs(tmp, state | (1 << j));
                tmp.pop_back();
            }
        };
        vector<int> tmp;
        dfs(tmp, 0);
        return ans;
    }
};