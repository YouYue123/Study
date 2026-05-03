// 718. Maximum Length of Repeated Subarray [M]
// LeetCode maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector memo(
            m,
            vector(n, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j) -> int{
            if(i >= m || j >= n) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(nums1[i] == nums2[j]) {
                ans = max(ans, dfs(i + 1, j + 1) + 1);
            } 
            return memo[i][j] = ans;
        };
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) ans = max(ans, dfs(i, j));
        }
        return ans;
    }
};