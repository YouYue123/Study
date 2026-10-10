#include <bits/stdc++.h>
using namespace std;

// 349. Intersection of Two Arrays [E]
// LeetCode intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> dict;
        for(int num : nums1) dict.insert(num);
        unordered_set<int> ans;
        for(int num : nums2) {
            if(dict.contains(num)) {
                ans.insert(num);
            }
        }
        return vector(ans.begin(), ans.end());
    }
};