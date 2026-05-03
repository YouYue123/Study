#include <bits/stdc++.h>
using namespace std;

// 3878. Count Good Subarrays [H]
// LeetCode count-good-subarrays

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        vector<pair<int, int>> or_left; // (子数组或值，最小左端点)
        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            last[x] = i;

            // 计算以 i 为右端点的子数组或值
            for (auto& [or_val, _] : or_left) {
                or_val |= x; // **根据题目修改**
            }
            // x 单独一个数作为子数组
            or_left.emplace_back(x, i);

            // 原地去重（相同或值只保留最左边的）
            // 原理见力扣 26. 删除有序数组中的重复项
            int m = 1;
            for (int j = 1; j < or_left.size(); j++) {
                if (or_left[j].first != or_left[j - 1].first) {
                    or_left[m++] = or_left[j];
                }
            }
            or_left.resize(m);

            for (int k = 0; k < or_left.size(); k++) {
                auto [or_val, left] = or_left[k];
                int right = k + 1 < or_left.size() ? or_left[k + 1].second - 1 : i;
                // 对于左端点在 [left, right]，右端点为 i 的子数组，OR 值都是 or_val
                auto it = last.find(or_val);
                if (it != last.end() && it->second >= left) {
                    ans += min(right, it->second) - left + 1;
                }
            }
        }

        return ans;
    }
};