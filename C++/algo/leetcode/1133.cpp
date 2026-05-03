#include <bits/stdc++.h>
using namespace std;

// 1133. Largest Unique Number [E]
// LeetCode largest-unique-number

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> dict;
        for(int num : nums) {
            dict[num] += 1;
        }
        for(int num : nums) {
            if (dict[num] == 1) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};