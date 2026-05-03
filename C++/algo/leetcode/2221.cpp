// 2221. Find Triangular Sum of an Array [M]
// LeetCode find-triangular-sum-of-an-array

const int MOD = 10;
const int MX = 1000;
const int POW2[4] = {2, 4, 8, 6};

// 计算组合数，需要计算阶乘及其逆元
int f[MX + 1]; // f[n] = n!（去掉质因子 2 和 5）
int inv_f[MX + 1]; // invF[n] = n!^-1（去掉质因子 2 和 5）
int p2[MX + 1]; // n! 中的 2 的幂次
int p5[MX + 1]; // n! 中的 5 的幂次

int qpow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 > 0) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

auto init = []() {
    f[0] = inv_f[0] = 1;
    for (int i = 1; i <= MX; i++) {
        int x = i;

        // 分离质因子 2，计算 2 的幂次
        int e2 = countr_zero((uint32_t) x);
        x >>= e2;

        // 分离质因子 5，计算 5 的幂次
        int e5 = 0;
        while (x % 5 == 0) {
            e5++;
            x /= 5;
        }

        f[i] = f[i - 1] * x % MOD;
        inv_f[i] = qpow(f[i], 3); // 欧拉定理求逆元
        p2[i] = p2[i - 1] + e2;
        p5[i] = p5[i - 1] + e5;
    }
    return 0;
}();

int comb(int n, int k) {
    int e2 = p2[n] - p2[k] - p2[n - k];
    return f[n] * inv_f[k] * inv_f[n - k] *
           (e2 ? POW2[(e2 - 1) % 4] : 1) *
           (p5[n] - p5[k] - p5[n - k] ? 5 : 1) % MOD;
}

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += comb(n - 1, i) * nums[i];
        }
        return ans % MOD;
    }
};