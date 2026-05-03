// 3872. Longest Arithmetic Sequence After Changing At Most One Element [M]
// LeetCode longest-arithmetic-sequence-after-changing-at-most-one-element

class Solution {
    vector<int> calc(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = 1;
        pre[1] = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i - 2] + nums[i] == nums[i - 1] * 2) { // 三个数等差
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = 2;
            }
        }
        return pre;
    }

public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = calc(nums);
        int ans = ranges::max(pre) + 1;
        if (ans >= n) { // 整个数组是等差的，或者修改端点元素后是等差的
            return n;
        }

        ranges::reverse(nums);
        vector<int> suf = calc(nums);
        ranges::reverse(suf);
        ranges::reverse(nums);
        // 注意 max(pre) == max(suf)，无需重复计算

        for (int i = 1; i < n - 1; i++) {
            // 把 nums[i] 改成 d2 / 2
            int d2 = nums[i + 1] - nums[i - 1];
            if (d2 % 2) { // d2 / 2 必须是整数
                continue;
            }

            bool ok_left = i > 1 && nums[i - 1] - nums[i - 2] == d2 / 2;
            bool ok_right = i + 2 < n && nums[i + 2] - nums[i + 1] == d2 / 2;

            if (ok_left && ok_right) {
                ans = max(ans, pre[i - 1] + 1 + suf[i + 1]);
            } else if (ok_left) {
                ans = max(ans, pre[i - 1] + 2);
            } else if (ok_right) {
                ans = max(ans, suf[i + 1] + 2);
            }
        }

        return ans;
    }
};