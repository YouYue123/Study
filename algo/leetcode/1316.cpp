#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll BASE_1 = 131, MOD_1 = 1e9 + 7;
ll BASE_2 = 13331, MOD_2 = 1e9 + 9;
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        vector base_1_mod_pow(2001, 1);
        vector base_2_mod_pow(2001, 1);
        for(int i = 1; i < base_1_mod_pow.size(); i ++) {
            base_1_mod_pow[i] = (base_1_mod_pow[i - 1] * BASE_1) % MOD_1;
            base_2_mod_pow[i] = (base_2_mod_pow[i - 1] * BASE_2) % MOD_2;
        }
        vector<ll> pref_1(n + 1, 0);
        vector<ll> pref_2(n + 1, 0);
        for(int i = 0; i < n; i ++) {
            pref_1[i + 1] = (pref_1[i] * BASE_1 + text[i]) % MOD_1;
            pref_2[i + 1] = (pref_2[i] * BASE_2 + text[i]) % MOD_2;
        }
        auto get_hash = [&] (int l, int r) -> ll {
            int len = r - l + 1;
            ll h1 = (pref_1[r + 1] - pref_1[l] * base_1_mod_pow[len] % MOD_1 + MOD_1) % MOD_1;
            ll h2 = (pref_2[r + 1] - pref_2[l] * base_2_mod_pow[len] % MOD_2 + MOD_2) % MOD_2;
            return h1 << 32 | h2;
        };

        unordered_set<int> seen;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i; j < n; j ++) {
                int len = j - i + 1;
                ll hash_val = get_hash(i, j);
                if(j + len < n) {
                    ll hash_val = get_hash(i, j);
                    ll another_hash_val = get_hash(j + 1, j + len);
                    if(another_hash_val == hash_val && !seen.contains(hash_val)) {
                        seen.insert(hash_val);
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};