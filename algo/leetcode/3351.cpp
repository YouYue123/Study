#include <bits/stdc++.h>
using namespace std;

// 3351. Sum of Good Subsequences [H]
// LeetCode sum-of-good-subsequences

int MOD = 1e9 + 7;
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        using pii = pair<long long, long long>;
        unordered_map<long long, pii> dict;
        long long ans = 0;
        for(int num : nums) {
            long long up = num + 1, down = num - 1;
            long long cnt = 0;
            long long sum = 0;
            if(dict.contains(up)) {
                cnt = (cnt + dict[up].second) % MOD;
                sum = (sum + dict[up].first) % MOD;
            }
            if(dict.contains(down)) {
                cnt = (cnt + dict[down].second) % MOD;
                sum = (sum + dict[down].first) % MOD;
            }
            long long contrib = (sum + num * (cnt + 1)) % MOD;
            dict[num].first = (dict[num].first + contrib) % MOD;
            dict[num].second = (dict[num].second + cnt + 1) % MOD;
            ans = (ans + contrib) % MOD;
        }
        return ans;
    }
};