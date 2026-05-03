#include <bits/stdc++.h>
using namespace std;

// 217. Contains Duplicate [E]
// LeetCode contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> dict;
        for(auto num : nums) {
            if(dict.contains(num)) return true;
            dict[num] = true;
        }
        return false;
    }
};