#include <bits/stdc++.h>
using namespace std;

// 2441. Largest Positive Integer That Exists With Its Negative [E]
// LeetCode largest-positive-integer-that-exists-with-its-negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> dict;
        for(int num : nums) {
            if(dict.contains(-num)) {
                ans = max(ans, abs(num));
            }
            dict.insert(num);
        }
        return ans == 0 ? -1 : ans;
    }
};