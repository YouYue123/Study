#include <bits/stdc++.h>
using namespace std;

// 3743. Maximize Cyclic Partition Score [H]
// LeetCode maximize-cyclic-partition-score

class Solution {
public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long memo[n][k][3];
        auto dfs = [&] (this auto&& dfs, vector<int>& newNums, int i, int cnt, int state) -> long long {
            if(i == n || cnt == k) return state == 0 ? 0 : LLONG_MIN / 2;
            if(memo[i][cnt][state] != -1) return memo[i][cnt][state];
            long long ans = dfs(newNums, i + 1, cnt, state);
            if(state == 0) {
                ans = max({
                    ans,
                    dfs(newNums, i + 1, cnt, 1) + newNums[i],
                    dfs(newNums, i + 1, cnt, 2) - newNums[i]
                });
            } else if(state == 1) {
                ans = max(
                    ans,
                    dfs(newNums, i + 1, cnt + 1, 0) - newNums[i]
                );
            } else if(state == 2) {
                ans = max(
                    ans,
                    dfs(newNums, i + 1, cnt + 1, 0) + newNums[i]
                );
            }
            return memo[i][cnt][state] = ans;
        };
        int maxI = ranges::max_element(nums) - nums.begin();
        vector<int> nums1;
        nums1.reserve(n);
        nums1.insert(nums1.end(), nums.begin() + maxI, nums.end());
        nums1.insert(nums1.end(), nums.begin(), nums.begin() + maxI);
        memset(memo, -1LL, sizeof(memo));
        long long ans = dfs(nums1, 0, 0, 0);
        vector<int> nums2;
        nums2.reserve(n);
        nums2.insert(nums2.end(), nums.begin() + maxI + 1, nums.end());
        nums2.insert(nums2.end(), nums.begin(), nums.begin() + maxI + 1);
        memset(memo, -1LL, sizeof(memo));
        ans = max(ans, dfs(nums2, 0, 0, 0));
        return ans;
    }
};