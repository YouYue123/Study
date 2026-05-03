#include <bits/stdc++.h>
using namespace std;

// 2215. Find the Difference of Two Arrays [E]
// LeetCode find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(), nums1.end());
        unordered_set<int>set2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2, vector<int>());
        for(int num : set1) {
            if(!set2.contains(num)) ans[0].push_back(num);
        }
        for(int num : set2) {
            if(!set1.contains(num)) ans[1].push_back(num);
        }
        return ans;
    }
};