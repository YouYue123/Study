// 47. Permutations II [M]
// LeetCode permutations-ii

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        auto dfs = [&] (this auto&& dfs, vector<int>& tmp, int state) {
            if(tmp.size() == n) {
                ans.push_back(tmp);
                return;
            }
            int prev = -INF;
            for(int i = 0; i < n; i ++) {
                if(state & (1 << i)) continue;
                if(i > 0 && nums[i] == prev) continue;
                prev = nums[i];
                tmp.push_back(nums[i]);
                dfs(tmp, state | (1 << i));
                tmp.pop_back();
            }
        };
        vector<int> tmp;
        dfs(tmp, 0);
        return ans;
    }
};