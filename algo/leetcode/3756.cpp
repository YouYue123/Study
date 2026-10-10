#include <bits/stdc++.h>
using namespace std;

// 3756. Concatenate Non-Zero Digits and Multiply by Sum II [M]
// LeetCode concatenate-non-zero-digits-and-multiply-by-sum-ii

int MOD = 1e9 + 7;
class Solution {
public:
    long long modMult(long long a, long long b) {
        return ((long long)(a) * b) % MOD;
    }
    long long modInverse(long long n) {
        return modPow(n, MOD - 2);
    }
    long long modPow(long long base , long long exp) {
        long long res = 1;
        base %= MOD;
        while(exp > 0) {
            if(exp % 2 == 1) res = modMult(res, base);
            base = modMult(base, base);
            exp /= 2;
        }
        return res;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = s.size();
        vector<int> idxes;
        vector<int> nonzero_digits_val;
        vector<long long> prefix_sum;
        vector<long long> prefix_val;
        long long curr_sum = 0;
        long long curr_val = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != '0') {
                idxes.push_back(i);
                nonzero_digits_val.push_back(s[i] - '0');
                curr_sum += (s[i] - '0');
                curr_val = (curr_val * 10 + (s[i] - '0')) % MOD;
                prefix_sum.push_back(curr_sum);
                prefix_val.push_back(curr_val);
            }
        }
        int m = idxes.size();
        vector<long long> pow10(m + 1);
        pow10[0] = 1;
        for(int i = 1; i <= m; i++) {
            pow10[i] = modMult(pow10[i - 1], 10);
        }
        for(auto& q : queries) {
            int l = q[0], r = q[1];
            auto it_start = lower_bound(idxes.begin(), idxes.end(), l);
            auto it_end = upper_bound(idxes.begin(), idxes.end(), r);
            int start_idx = it_start - idxes.begin();
            int end_idx = it_end - idxes.begin() - 1;
            if(start_idx > end_idx || start_idx >= m) {
                ans.push_back(0);
                continue;
            }
            long long sum = prefix_sum[end_idx];
            if(start_idx > 0) {
                sum -= prefix_sum[start_idx - 1];
            }
            long long x;
            if(start_idx == 0) {
                x = prefix_val[end_idx];
            } else {
                long long full_val = prefix_val[end_idx];
                long long prefix_val_before = prefix_val[start_idx - 1];
                int digit_count = end_idx - start_idx + 1;
                x = (full_val - prefix_val_before * pow10[digit_count] % MOD + MOD) % MOD;
            }
            ans.push_back(modMult(x, sum));
        }
        return ans;
    }
};