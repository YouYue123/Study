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