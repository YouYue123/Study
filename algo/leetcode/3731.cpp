#include <bits/stdc++.h>
using namespace std;

// 3731. Find Missing Elements [E]
// LeetCode find-missing-elements

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        unordered_set<int> dict(nums.begin(), nums.end());
        for(int num = minNum; num <= maxNum; num ++) {
            if(!dict.contains(num)) ans.push_back(num);
        }
        return ans;
    }
};