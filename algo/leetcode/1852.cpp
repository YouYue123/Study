#include <bits/stdc++.h>
using namespace std;

// 1852. Distinct Numbers in Each Subarray [M]
// LeetCode distinct-numbers-in-each-subarray

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        int left = 0, right = 0;
        int distinctCount = 0;
        unordered_map<int, int> dict;
        while(right < nums.size()) {
            dict[nums[right]] += 1;
            if(dict[nums[right]] == 1) distinctCount += 1;
            if(right - left + 1 > k) {
                dict[nums[left]] -= 1;
                if(dict[nums[left]] == 0) distinctCount -= 1;
                left += 1;
            }
            if(right - left + 1 == k) ans.push_back(distinctCount);
            right += 1;
        }
        return ans;
    }
};