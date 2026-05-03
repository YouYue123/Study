#include <bits/stdc++.h>
using namespace std;

// 3176. Find the Maximum Length of a Good Subsequence I [M]
// LeetCode find-the-maximum-length-of-a-good-subsequence-i

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(n, vector(k + 1, vector(n, -1)));
        unordered_map<int, int> valToIdx;
        for(int i = 0; i < n; i ++) valToIdx[nums[i]] = i;
        auto dfs  = [&] (this auto&& dfs, int i, int cnt, int prev) {
            if(i == n) return 0;
            int idx = valToIdx[prev];
            // cout << i << " " << cnt << " " << idx << endl;
            if(memo[i][cnt][idx] != -1) return memo[i][cnt][idx];
            int ans = dfs(i + 1, cnt, prev);
            if(nums[i] != prev) {
                if(cnt < k) {
                    ans = max(ans, dfs(i + 1, cnt + 1, nums[i]) + 1);
                }
            } else {
                ans = max(ans, dfs(i + 1, cnt, nums[i]) + 1);
            }
            return memo[i][cnt][idx] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i ++)  ans = max(ans, 1 + dfs(i + 1, 0, nums[i]));
        return ans;
    }
};