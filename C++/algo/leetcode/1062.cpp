#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
concept Rolling_Hash_Seq = requires(T& s, int i) {
    { s[i] } -> convertible_to<ll>;
};
template<ll BASE, ll MOD, Rolling_Hash_Seq T>
struct Rolling_Hash_Window {
    int len;
    ll h = 0;
    ll p = 1;

    void setup(T& s) {
        for(int i = 0 ; i < len ; i ++) {
            h = h * BASE % MOD + s[i];
            p = p * BASE % MOD;
        }
    };

    void roll (T& s, int idx) {
        h = h * BASE % MOD + s[idx];
        ll remove = p * s[idx - len] % MOD;
        h = (h - remove + MOD) % MOD;
    };
};
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int left = -1, right = n + 1;

        auto is_valid = [&] (int len) -> bool {
            auto r1 = Rolling_Hash_Window<131, (ll)1e9 + 7, string>(len);
            auto r2 = Rolling_Hash_Window<13331,(ll)1e9 + 9, string>(len);
            unordered_set<ll> seen;
            r1.setup(s);
            r2.setup(s);
            ll cur = r1.h << 32 | r2.h;
            seen.insert(cur);
            for(int i = len; i < n; i ++) {
                r1.roll(s, i);
                r2.roll(s, i);
                cur = r1.h << 32 | r2.h;
                if(seen.contains(cur)) return true;
                seen.insert(cur);
            }
            return false;
        };

        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(is_valid(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        } 
        return left;
    }
};