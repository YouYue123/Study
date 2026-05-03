// 960. Delete Columns to Make Sorted III [H]
// LeetCode delete-columns-to-make-sorted-iii

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector memo(
            n, -1
        );
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i >= n) return 0;
            int ans = 1;
            if(memo[i] != -1) return memo[i];
            for(int j = i + 1; j < n; j ++) {
                bool sorted = true;
                for(auto& s : strs) {
                    if(s[j] < s[i]) {
                        sorted = false;
                        break;
                    }
                }
                if(sorted) ans = max(ans, 1 + dfs(j));
            }
            return memo[i] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, dfs(i));
        }
        return n - ans;
    }
};