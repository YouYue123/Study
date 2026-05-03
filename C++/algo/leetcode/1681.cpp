// 1681. Minimum Incompatibility [H]
// LeetCode minimum-incompatibility

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int constexpr INF = 0x3f3f3f3f;

class Solution {
    int n, group_size;
    int memo[1 << 16]; // 针对 n 最大为 16 的情况

public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        n = nums.size();
        group_size = n / k;
        sort(nums.begin(), nums.end());
        
        // 预判：如果有任何数字出现次数超过 k，由于每组只能放一个，必然无法完成
        vector<int> count(20, 0);
        for(int x : nums) if(++count[x] > k) return -1;

        fill(memo, memo + (1 << n), -1);

        // mask: 当前剩余未选数字的状态
        auto dfs = [&](auto& self, int mask) -> int {
            if (mask == 0) return 0;
            if (memo[mask] != -1) return memo[mask];

            int res = INF;
            // 策略：找到 mask 中最低位的 1，强制让它作为当前组的起点
            // 这样可以避免 [组A, 组B] 和 [组B, 组A] 的重复搜索
            int first = __builtin_ctz(mask);
            
            // 接下来在剩余的 bits 中选出 group_size - 1 个不同的数组成一组
            // 这里使用一个子 DFS 来枚举所有包含 'first' 的合法子集
            auto find_subsets = [&](auto& self_sub, int current_mask, int last_idx, int count, int min_val, int max_val) {
                if (count == group_size) {
                    int next_res = self(self, mask ^ current_mask);
                    if (next_res != INF) {
                        res = min(res, (max_val - min_val) + next_res);
                    }
                    return;
                }

                for (int i = last_idx + 1; i < n; ++i) {
                    // 必须在 mask 中，且不能与上一个选入的数字相同（因为已排序，相同数字相邻）
                    if ((mask & (1 << i)) && nums[i] != nums[last_idx]) {
                        self_sub(self_sub, current_mask | (1 << i), i, count + 1, min_val, nums[i]);
                    }
                }
            };

            // 从第 first 个元素开始，构建一个大小为 group_size 的合法组
            find_subsets(find_subsets, 1 << first, first, 1, nums[first], nums[first]);

            return memo[mask] = res;
        };

        int result = dfs(dfs, (1 << n) - 1);
        return result >= INF ? -1 : result;
    }
};