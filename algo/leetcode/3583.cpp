#include <bits/stdc++.h>
using namespace std;

// 3583. Count Special Triplets [M]
// LeetCode count-special-triplets

int MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long long> pre;
        unordered_map<int, long long> post;
        for(int num : nums)  post[num] += 1;
        long long ans = 0;
        for(int num : nums) {
            post[num] -= 1;
            int target = num * 2;
            ans = (ans + pre[target] * post[target] % MOD) % MOD;
            pre[num] += 1;
        }
        return ans;
    }
};