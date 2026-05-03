#include <bits/stdc++.h>
using namespace std;

// 3533. Concatenated Divisibility [H]
// LeetCode concatenated-divisibility

class Solution {
public:
    int modPow(int a, int e, int m) {
        long long res = 1, x = a % m;
        while (e) {
            if (e & 1) res = (res * x) % m;
            x = (x * x) % m;
            e >>= 1;
        }
        return (int)res;
    }

    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        int n = nums.size();
        int full = (1 << n) - 1;

        vector<int> len(n), tenMod(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i], L = 0;
            do {
                L++;
                x /= 10;
            } while (x);
            len[i] = L;
            tenMod[i] = modPow(10, L, k);
        }

        vector<int> pow10Mask(1 << n, 0);
        pow10Mask[0] = 1 % k;
        for (int mask = 1; mask <= full; mask++) {
            int i = __builtin_ctz(mask);
            pow10Mask[mask] =
                int((long long)pow10Mask[mask ^ (1 << i)] * tenMod[i] % k);
        }

        // Memoization cache: mask -> remainder -> bool
        vector<vector<int>> memo(1 << n, vector<int>(k, -1));

        // Top-down DP function
        function<bool(int, int)> dp = [&](int mask, int rem) -> bool {
            if (mask == 0) return rem == 0;
            if (memo[mask][rem] != -1) return memo[mask][rem];

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    int prev = mask ^ (1 << i);
                    int prevRem = int((k + rem - (long long)(nums[i] % k) * pow10Mask[prev] % k) % k);
                    if (dp(prev, prevRem)) {
                        memo[mask][rem] = 1;
                        return true;
                    }
                }
            }
            memo[mask][rem] = 0;
            return false;
        };

        // Check if a valid solution exists
        if (!dp(full, 0)) return {};

        // Reconstruct the solution
        vector<pair<int, int>> order;
        for (int i = 0; i < n; i++) order.emplace_back(nums[i], i);
        sort(order.begin(), order.end());

        vector<int> ans;
        ans.reserve(n);
        int used = 0, curRem = 0;

        for (int step = 0; step < n; step++) {
            for (auto [val, i] : order) {
                if (used & (1 << i)) continue;
                int nxtRem = int(((long long)curRem * tenMod[i] + val % k) % k);
                int remMask = full ^ (used | (1 << i));
                int need = int((k - (long long)nxtRem * pow10Mask[remMask] % k) % k);
                if (dp(remMask, need)) {
                    ans.push_back(val);
                    used |= (1 << i);
                    curRem = nxtRem;
                    break;
                }
            }
        }

        return ans;
    }
};