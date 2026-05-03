// 805. Split Array With Same Average [H]
// LeetCode split-array-with-same-average

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int m = n / 2;
        
        // 预剪枝：如果不存在 k 使得 (sum * k) % n == 0，直接返回 false
        bool possible = false;
        for (int k = 1; k <= n / 2; ++k) {
            if ((sum * k) % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        // sums[i] 存储长度为 i 的子集可能的所有和
        vector<unordered_set<int>> sums(m + 1);
        sums[0].insert(0);

        // 处理前半部分
        for (int i = 0; i < m; ++i) {
            for (int k = i; k >= 0; --k) {
                for (int s : sums[k]) {
                    sums[k + 1].insert(s + nums[i]);
                }
            }
        }

        // 检查前半部分是否已经满足条件
        for (int k = 1; k <= m; ++k) {
            if ((sum * k) % n == 0 && sums[k].count(sum * k / n)) return true;
        }

        // 处理后半部分并结合前半部分结果
        vector<unordered_set<int>> right_sums(n - m + 1);
        right_sums[0].insert(0);
        for (int i = m; i < n; ++i) {
            for (int k = i - m; k >= 0; --k) {
                for (int s : right_sums[k]) {
                    right_sums[k + 1].insert(s + nums[i]);
                }
            }
        }

        // 核心：在后半部分寻找互补的子集
        for (int k2 = 0; k2 <= n - m; ++k2) {
            for (int s2 : right_sums[k2]) {
                // 检查总长度 k = k1 + k2
                for (int k1 = 0; k1 <= m; ++k1) {
                    int k = k1 + k2;
                    if (k == 0 || k == n) continue; // 不能全选或不选
                    if ((sum * k) % n == 0) {
                        int target = sum * k / n;
                        if (sums[k1].count(target - s2)) return true;
                    }
                }
            }
        }

        return false;
    }
};