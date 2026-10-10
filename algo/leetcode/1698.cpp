#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll BASE_1 = 131, MOD_1 = 1e9 + 7;
ll BASE_2 = 13331, MOD_2 = 1e9 + 9;
class Solution {
public:
    int countDistinct(string s) {
        int n = s.size();
        vector mod_pow_base1(501, 1LL);
        vector mod_pow_base2(501, 1LL);
        for(int i = 1; i <= 500; i ++) {
            mod_pow_base1[i] = mod_pow_base1[i - 1] * BASE_1 % MOD_1;
            mod_pow_base2[i] = mod_pow_base2[i - 1] * BASE_2 % MOD_2;
        }
        unordered_set<ll> hash_set;
        vector pre_1(n + 1, 0LL);
        vector pre_2(n + 1, 0LL);
        for(int i = 0; i < n; i ++) {
            pre_1[i + 1] = (pre_1[i] * BASE_1 % MOD_1 + s[i]) % MOD_1;
            pre_2[i + 1] = (pre_2[i] * BASE_2 % MOD_2 + s[i]) % MOD_2;
        }
        auto get_hash = [&] (int l, int r) {
            int len = r - l + 1;
            ll h_1 = (pre_1[r + 1] - pre_1[l] * mod_pow_base1[len] % MOD_1 + MOD_1) % MOD_1;
            ll h_2 = (pre_2[r + 1] - pre_2[l] * mod_pow_base2[len] % MOD_2 + MOD_2) % MOD_2;
            return h_1 << 32 | h_2;
        };
        for(int i = 0; i < n; i ++) {
            for(int j = i; j < n; j ++) {
                auto hash_val = get_hash(i, j);
                hash_set.insert(hash_val);
            }
        }
        return hash_set.size();
    }
};