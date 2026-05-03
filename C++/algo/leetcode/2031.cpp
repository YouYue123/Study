// 2031. Count Subarrays With More Ones Than Zeros [M]
// LeetCode count-subarrays-with-more-ones-than-zeros

class Solution {
    int MOD = 1e9 + 7;
    // 树状数组用于快速统计小于当前和的个数
    vector<int> bit;
    int max_idx;

    void update(int idx, int val) {
        for (; idx <= max_idx; idx += idx & -idx) {
            bit[idx] = (bit[idx] + val) % MOD;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum = (sum + bit[idx]) % MOD;
        }
        return sum;
    }

public:
    int subarraysWithMoreOnesThanZeroes(vector<int>& nums) {
        int n = nums.size();
        max_idx = 2 * n + 1; // 前缀和范围 [-n, n]，加上偏移量后范围 [1, 2n+1]
        bit.assign(max_idx + 1, 0);
        
        int offset = n + 1;
        long long ans = 0;
        int cur_sum = 0;

        // 初始状态：前缀和为 0 已经出现过 1 次
        update(0 + offset, 1);

        for (int num : nums) {
            cur_sum += (num == 1 ? 1 : -1);
            
            // 统计之前出现的满足 prev_sum < cur_sum 的个数
            // 即查询树状数组中 [1, cur_sum + offset - 1] 的区间和
            ans = (ans + query(cur_sum + offset - 1)) % MOD;

            // 将当前前缀和存入树状数组
            update(cur_sum + offset, 1);
        }

        return (int)ans;
    }
};