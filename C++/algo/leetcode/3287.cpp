// 3287. Find the Maximum Sequence Value of Array [H]
// LeetCode find-the-maximum-sequence-value-of-array

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        const int MX = 1 << 7;
        int n = nums.size();
        vector<array<int, MX>> suf(n - k + 1);
        vector<array<int, MX>> f(k + 1);
        f[0][0] = true;
        for (int i = n - 1; i >= k; i--) {
            int v = nums[i];
            // 注意当 i 比较大的时候，循环次数应和 i 有关，因为更大的 j，对应的 f[j] 全为 false
            for (int j = min(k - 1, n - 1 - i); j >= 0; j--) {
                for (int x = 0; x < MX; x++) {
                    if (f[j][x]) {
                        f[j + 1][x | v] = true;
                    }
                }
            }
            if (i <= n - k) {
                suf[i] = f[k];
            }
        }

        int ans = 0;
        f = vector<array<int, MX>>(k + 1);
        f[0][0] = true;
        for (int i = 0; i < n - k; i++) {
            int v = nums[i];
            for (int j = min(k - 1, i); j >= 0; j--) {
                for (int x = 0; x < MX; x++) {
                    if (f[j][x]) {
                        f[j + 1][x | v] = true;
                    }
                }
            }
            if (i < k - 1) {
                continue;
            }
            // 这里 f[k] 就是 pre[i]
            for (int x = 0; x < MX; x++) {
                if (f[k][x]) {
                    for (int y = 0; y < MX; y++) {
                        if (suf[i + 1][y]) {
                            ans = max(ans, x ^ y);
                        }
                    }
                }
            }
            if (ans == MX - 1) {
                return ans;
            }
        }
        return ans;
    }
};