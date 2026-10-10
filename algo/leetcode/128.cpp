#include <bits/stdc++.h>
using namespace std;

// 128. Longest Consecutive Sequence [M]
// LeetCode longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict;
        for(int num : nums) {
            dict.insert(num);
        }
        int ans = 0;
        for(int num : dict) {
            if(!dict.contains(num - 1)) {
                // cout << num << endl;
                int cur = num;
                while(dict.contains(cur)) {
                    cur += 1;
                }
                ans = max(
                    ans,
                    cur - num
                );
            }
        }
        return ans;
    }
};