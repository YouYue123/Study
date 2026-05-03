// 1187. Make Array Strictly Increasing [H]
// LeetCode make-array-strictly-increasing

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        unordered_map<int, unordered_map<int, int>> memo;
        auto dfs = [&] (this auto&& dfs, int i, int pre) {
            if(i < 0) return 0;
            if(memo.contains(i) && memo[i].contains(pre)) return memo[i][pre];
            int ans = INT_MAX / 2;
            if(arr1[i] < pre) ans = dfs(i - 1, arr1[i]);
            auto idx = lower_bound(arr2.begin(), arr2.end(), pre) - arr2.begin() - 1;
            if(idx >= 0) {
                ans = min(ans, dfs(i - 1, arr2[idx]) + 1);
            }
            return memo[i][pre] = ans;
        };
        int ans = dfs(n - 1, INT_MAX);
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};