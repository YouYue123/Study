#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T>
concept RollingHashSeq = requires(T& s, int i) {
    { s[i] } -> convertible_to<long long>;
};

template<ll BASE, ll MOD, RollingHashSeq T>
struct Rolling_Hash_Window {
    int len;
    ll h = 0;
    ll p = 1;
    void setup(T& s) {
        for(int i = 0; i < len; i ++) {
            h = (h * BASE % MOD + s[i]) % MOD;
            p = p * BASE % MOD;
        }
    }
    void roll(T& s, int idx) {
        h = (h * BASE % MOD + s[idx]) % MOD;
        ll remove = (p * (s[idx - len])) % MOD;
        h = (h - remove + MOD) % MOD;
    }
};
struct Ans {
    bool ok;
    int start_idx;
};
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        auto is_valid = [&] (int len) -> Ans {
            if(len == 0) return { true, 0 };
            unordered_set<ll> seen;
            auto r1 = Rolling_Hash_Window<131, (ll)1e9 + 7, string> (len);
            auto r2 = Rolling_Hash_Window<13331, (ll)1e9 + 9, string> (len);    
            r1.setup(s);
            r2.setup(s);
            ll cur = r1.h << 32 | r2.h;
            seen.insert(cur);
            for(int i = len ; i < n; i ++) {
                r1.roll(s, i);
                r2.roll(s, i);
                cur = r1.h << 32 | r2.h;
                if(seen.contains(cur)) return { true, i - len + 1};
                seen.insert(cur);
            }
            return { false, -1 };
        };
        int start_idx = 0;
        int left = -1, right = n + 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            auto ans = is_valid(mid);
            if(ans.ok) {
                start_idx = ans.start_idx;
                left = mid;
            } else {
                right = mid;
            }
        }
        return s.substr(start_idx, left);
    }
};