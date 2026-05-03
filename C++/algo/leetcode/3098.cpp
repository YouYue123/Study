#include <bits/stdc++.h>
using namespace std;

// 3098. Find the Sum of Subsequence Powers [H]
// LeetCode find-the-sum-of-subsequence-powers

int MOD = 1e9 + 7;
int INF = 0x3f3f3f3f;
class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // (i, len, power) -> cnt
        unordered_map<int, long long> dict[n][k + 1];
        for(int i = 0; i < n; i ++) {
            dict[i][1][INF] = 1;
            for(int j = 0;  j < i; j ++) {
                int curP = nums[i] - nums[j]; 
                for(int len = 1; len < k; len ++) {
                    for(auto& [power, cnt] : dict[j][len]) {
                        int newP = min(curP, power);
                        dict[i][len + 1][newP] = (dict[i][len + 1][newP] + cnt) % MOD;
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i ++) {
            for(auto& [power, cnt] : dict[i][k]) {
                ans = (ans + (power * cnt) % MOD) % MOD;
            }
        }
        return ans;
    }
};