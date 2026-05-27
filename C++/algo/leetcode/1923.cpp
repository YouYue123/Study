#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll constexpr INF = 0x3f3f3f3f;
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
class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        auto is_valid = [&] (int len) -> bool {
            unordered_map<ll, int> cnt;
            for(auto& path : paths) {
                if(path.size() < len) return false;
                unordered_set<ll> seen;
                auto r1 = Rolling_Hash_Window<131, (ll)1e9 + 7, vector<int>>(len);
                auto r2 = Rolling_Hash_Window<13331, (ll)1e9 + 9, vector<int>>(len);
                r1.setup(path);
                r2.setup(path);
                ll cur = r1.h << 32 | r2.h;
                seen.insert(cur);
                cnt[cur] += 1;
                for(int i = len ; i < path.size(); i ++) {
                    r1.roll(path, i);
                    r2.roll(path, i);
                    cur = r1.h << 32 | r2.h;
                    if(!seen.contains(cur)) {
                        seen.insert(cur);
                        cnt[cur] += 1;
                    }
                }
            }
            for(auto& [hash_val, freq] : cnt) {
                if(freq == m) return true;
            }
            return false;
        };
        int min_len = INF;
        for(auto& path : paths) {
            min_len = min(min_len, (int)path.size());
        }
        int left = 0, right = min_len + 1;
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