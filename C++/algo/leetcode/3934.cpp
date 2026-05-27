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
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        auto is_valid = [&] (int x) -> bool {
            unordered_map<ll, int> cnt;
            auto r1 = Rolling_Hash_Window(131, 1e9 + 7, x);
            auto r2 = Rolling_Hash_Window(13331, 1e9 + 9, x);
            r1.setup(nums);
            r2.setup(nums);
            ll cur = r1.h << 32 | r2.h;
            cnt[cur] += 1;
            for(int i = x; i < n; i ++) {
                r1.roll(nums, i);
                r2.roll(nums, i);
                cur = r1.h << 32 | r2.h;
                cnt[cur] += 1;
            }
            for(auto& [val, freq] : cnt) {
                if(freq == 1) return true;
            }
            return false;
        };
        int left = 0, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(is_valid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};