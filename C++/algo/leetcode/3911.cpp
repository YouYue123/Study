#include <bits/stdc++.h>
using namespace std;

// 3911. K-th Smallest Remaining Even Integer in Subarray Queries [H]
// LeetCode k-th-smallest-remaining-even-integer-in-subarray-queries

class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        // 记录所有偶数的下标
        vector<int> even_pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even_pos.push_back(i);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size()); // 预分配空间

        for (auto& q : queries) {
            // 计算询问对应的 even_pos 子数组
            int li = ranges::lower_bound(even_pos, q[0]) - even_pos.begin();
            int ri = ranges::upper_bound(even_pos, q[1]) - even_pos.begin();
            int k = q[2];

            int left = -1, right = ri - li;
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                (nums[even_pos[li + mid]] / 2 - 1 - mid >= k ? right : left) = mid;
            }
            ans.push_back((right + k) * 2); // 推导过程见 1539 题解
        }

        return ans;
    }
};