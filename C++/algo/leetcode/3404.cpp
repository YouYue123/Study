#include <bits/stdc++.h>
using namespace std;

// 3404. Count Special Subsequences [M]
// LeetCode count-special-subsequences

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        // nums[p] * nums[r] == nums[q] * nums[s]
        // nums[p] / nums[q] == nums[s] / nums[r]
        unordered_map<int, unordered_map<int, int>> dict;  
        long long ans = 0;
        for(int q = 2; q < nums.size() - 3; q ++) {
            for(int p = 0; p < q - 1; p ++) {
                int gcd = __gcd(nums[p], nums[q]);
                int pNum = nums[p] / gcd;
                int qNum = nums[q] / gcd;
                dict[pNum][qNum] += 1;
            }
            int rNum = nums[q + 2];
            for(int s = q + 4; s < nums.size(); s ++) {
                int gcd = __gcd(nums[s], rNum);
                int sNum = nums[s] / gcd;
                ans += dict[sNum][rNum / gcd];
            }
        }
        return ans;
    }
};