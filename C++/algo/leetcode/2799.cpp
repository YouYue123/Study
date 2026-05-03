#include <bits/stdc++.h>
using namespace std;

// 2799. Count Complete Subarrays in an Array [M]
// LeetCode count-complete-subarrays-in-an-array

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        int target = set.size();
        unordered_map<int, int> dict;
        int left = 0, right = 0;
        int count = 0;
        int ans = 0;
        while(right < nums.size()) {
            dict[nums[right]] += 1;
            if(dict[nums[right]] == 1) count += 1;
            while(count >= target) {
                dict[nums[left]] -= 1;
                if(dict[nums[left]] == 0) count -= 1;
                left += 1; 
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
};