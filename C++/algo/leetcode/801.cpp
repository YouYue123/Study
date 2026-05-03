// 801. Minimum Swaps To Make Sequences Increasing [H]
// LeetCode minimum-swaps-to-make-sequences-increasing

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector memo(n, vector(2, -1));
        auto dfs = [&] (this auto&& dfs, int i, int state) {
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            int ans = INT_MAX / 2;
            if(state == 0) {
                if(nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) { // can continue
                    ans = dfs(i + 1, 0);
                }
                if(nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) { // can swap
                    ans = min(ans, dfs(i + 1, 1) + 1);
                }
            } else {
                if(nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {// can continue
                    ans = dfs(i + 1, 0);
                }
                if(nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) { // can swap
                    ans = min(ans, dfs(i + 1, 1) + 1);
                }
            }
            return memo[i][state] = ans;
        };
        return min(dfs(1,0), dfs(1, 1) + 1);
    }
};