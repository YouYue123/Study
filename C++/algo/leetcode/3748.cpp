#include <bits/stdc++.h>
using namespace std;

// 3748. Count Stable Subarrays [H]
// LeetCode count-stable-subarrays

class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // 找递增段
        vector<int> left; // 递增段的左端点
        vector<long long> s = {0}; // 递增子数组个数的前缀和
        int start = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (i == n - 1 || x > nums[i + 1]) {
                // 找到了一个递增段 [start, i]
                left.push_back(start);
                long long m = i - start + 1;
                // 长为 m 的子数组中有 m*(m+1)/2 个递增子数组
                // 计算 m*(m+1)/2 的前缀和
                s.push_back(s.back() + m * (m + 1) / 2);
                start = i + 1; // 下一个递增段的左端点
            }
        }

        vector<long long> ans;
        ans.reserve(queries.size()); // 预分配空间
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int i = ranges::upper_bound(left, l) - left.begin(); // 左端点严格大于 l 的第一个区间
            int j = ranges::upper_bound(left, r) - left.begin() - 1; // 包含 r 的最后一个区间

            // l 和 r 在同一个区间
            if (i > j) {
                long long m = r - l + 1;
                ans.push_back(m * (m + 1) / 2);
                continue;
            }

            // l 和 r 在不同区间
            // 分成三段 [l, left[i]) + [left[i], left[j]) + [left[j], r]
            // 中间那段的子数组个数用前缀和计算
            long long m = left[i] - l;
            long long m2 = r - left[j] + 1;
            ans.push_back(m * (m + 1) / 2 + (s[j] - s[i]) + m2 * (m2 + 1) / 2);
        }
        return ans;
    }
};