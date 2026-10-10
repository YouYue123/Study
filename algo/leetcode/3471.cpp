#include <bits/stdc++.h>
using namespace std;

// 3471. Find the Largest Almost Missing Integer [E]
// LeetCode find-the-largest-almost-missing-integer

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int start = 0;
        int end = k - 1;
        unordered_map<int, int> dict;
        while(end < nums.size()) {
            set<int> cur;
            for (int i = start; i <= end; i ++) {
                cur.insert(nums[i]);
            }
            for(auto item : cur) {
                dict[item] += 1;
            }
            start += 1;
            end += 1;
        }
        int ans = -1;
        for(auto num:nums) {
            if(dict[num] == 1) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
};