// 77. Combinations [M]
// LeetCode combinations

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&] (this auto&& dfs, int i) {
            if(tmp.size() == k) {
                ans.push_back(tmp);
                return;
            }
            for(int j = i + 1; j <= n; j ++) {
                tmp.push_back(j);
                dfs(j);
                tmp.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};