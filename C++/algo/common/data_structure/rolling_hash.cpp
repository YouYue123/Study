#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<ll BASE, ll MOD>
struct Rolling_Hash_Window {
    ll len;
    ll h = 0; // the hash
    ll p = 1; // B ^ x
    void setup(vector<int>& nums) {
        for(int i = 0; i < len; i ++) { 
            h = (h * BASE % MOD + nums[i]) % MOD;
            p = p * BASE % MOD;
        }
    }
    void roll (vector<int>& nums, int idx) {
        h = (h * BASE % MOD + nums[idx]) % MOD;
        h = (h - p * nums[idx - len] % MOD + MOD) % MOD;
    }
};