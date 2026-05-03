// 1035. Uncrossed Lines [M]
// LeetCode uncrossed-lines

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector memo(
            n,
            vector(m, -1)
        );
        auto dfs =[&] (this auto&& dfs, int i, int j) {
            if(i == n || j == m) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(nums1[i] == nums2[j]) {
                ans = dfs(i + 1, j + 1) + 1;
            } else {
                ans = max(
                    dfs(i + 1, j),
                    dfs(i, j + 1)
                );
            }
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};