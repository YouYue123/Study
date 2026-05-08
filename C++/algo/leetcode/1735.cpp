#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
    static const int MOD = 1e9 + 7;
    // MAXN 需要覆盖 (最大指数 + 最大 n - 1)。
    // n 最大 10^4，k 最大 10^4 (其质因子指数总和很小)，15000 足够。
    static const int MAXN = 15000; 
    ll fact[MAXN], invFact[MAXN];
    // 快速幂：用于计算费马小定理下的乘法逆元
    ll quick_pow(ll a, ll k) {
        ll ans = 1;
        while (k > 0) {
            if (k & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            k /= 2;
        }
        return ans;
    }
    // 预处理：通过 O(N) 时间复杂度计算所有阶乘及其逆元
    void precompute() {
        if(fact[0] != 0) return;
        fact[0] = 1;
        for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
        // 关键点：利用费马小定理 inv(a) = a^(MOD-2)
        invFact[MAXN - 1] = quick_pow(fact[MAXN - 1], MOD - 2);
        // 逆推所有逆元：invFact[i] = invFact[i+1] * (i+1)
        for (int i = MAXN - 2; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    // O(1) 获取组合数
    // C(n, r), choosing r items from total n
    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        precompute();
        vector<int> ans;
        for (auto& q : queries) {
            int n = q[0], k = q[1];
            ll cur_ans = 1;
            // --- 对 k 进行质因数分解 ---
            for (int i = 2; i * i <= k; i++) {
                if (k % i == 0) {
                    int cnt = 0;
                    while (k % i == 0) { 
                        cnt++;
                        k /= i; 
                    }
                    // 将 cnt 个相同的质因子 i 放入 n 个不同的盒子
                    cur_ans = cur_ans * nCr(cnt + n - 1, n - 1) % MOD;
                }
            }
            // 如果最后还剩下一个质数（temp_k > 1）
            if (k > 1) {
                // 此时 cnt = 1，公式为 nCr(1 + n - 1, n - 1) = nCr(n, n - 1) = n
                cur_ans = cur_ans * n % MOD;
            }
            ans.push_back(cur_ans);
        }
        return ans;
    }
};