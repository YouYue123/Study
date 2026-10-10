#include <bits/stdc++.h>
using namespace std;

// 3190. Find Minimum Operations to Make All Elements Divisible by Three [E]
// LeetCode find-minimum-operations-to-make-all-elements-divisible-by-three

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            int minus = num % 3;
            int add = 3 - minus;
            ans += min(minus, add);
        }
        return ans;
    }
};