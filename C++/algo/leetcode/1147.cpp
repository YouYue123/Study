#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll BASE_1 = 131, MOD_1 = 1e9 + 7;
ll BASE_2 = 13331, MOD_2 = 1e9 + 9;
ll modPow(ll base, ll exp, ll mod)
{
    ll ans = 1;
    while (exp) {
        if (exp % 2 == 1) ans = (ans * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return ans;
}

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int left = 0, right = n - 1;
        int ans = 1;
        ll f_h1 = 0, f_h2 = 0;
        ll b_h1 = 0, b_h2 = 0, cnt = 0;
        while(left < right) {
            f_h1 = (f_h1 * BASE_1 % MOD_1 + text[left]) % MOD_1;
            f_h2 = (f_h2 * BASE_2 % MOD_2 + text[left]) % MOD_2;
            ll f_hash = f_h1 << 32 | f_h2;

            b_h1 = (b_h1 + modPow(BASE_1, cnt, MOD_1) * text[right]) % MOD_1;
            b_h2 = (b_h2 + modPow(BASE_2, cnt, MOD_2) * text[right]) % MOD_2;
            ll b_hash = b_h1 << 32 | b_h2;
            cnt += 1;

            if(f_hash == b_hash) {
                ans += 2;
                f_h1 = 0;
                f_h2 = 0;
                b_h1 = 0;
                b_h2 = 0;
                cnt = 0;
                if(left == right - 1) {
                    ans -= 1;
                }
            }
            left += 1;
            right -= 1;
        } 
        // cout << "cnt: " << cnt << endl;
        // cout << left << " " << right << endl;
        return ans;
    }
};