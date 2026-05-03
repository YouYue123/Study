// 944. Delete Columns to Make Sorted [E]
// LeetCode delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 1; j < n; j ++) {
                if(strs[j][i] < strs[j - 1][i]) {
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
     }
};