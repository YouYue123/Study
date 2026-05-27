#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Rolling_Hash_Window {
    ll B;
    ll MOD;
    ll len;
    ll h = 0; // the hash
    ll p = 1; // B ^ x
    void setup(vector<int>& nums) {
        for(int i = 0; i < len; i ++) { 
            h = (h * B % MOD + nums[i]) % MOD;
            p = p * B % MOD;
        }
    }
    void roll (vector<int>& nums, int idx) {
        h = (h * B % MOD + nums[idx]) % MOD;
        h = (h - p * nums[idx - len] % MOD + MOD) % MOD;
    }
};