#include <bits/stdc++.h>
using namespace std;

// 1512. Number of Good Pairs [E]
// LeetCode number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for(int num  : nums) {
            ans += cnt[num];
            cnt[num] += 1;
        }
        return ans;
    }
};