#include <bits/stdc++.h>
using namespace std;

// 567. Permutation in String [M]
// LeetCode permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> dict;
        for(char c : s1) dict[c] += 1;
        int left = 0, right = 0;
        int count = 0;
        while(right < s2.size()) {
            dict[s2[right]] -= 1;
            if(dict[s2[right]] >= 0) count += 1;
            if(right - left + 1 > s1.size()) {
                dict[s2[left]] += 1;
                if(dict[s2[left]] > 0) count -= 1;
                left += 1;
            }
            if(right - left + 1 == s1.size() && count == s1.size()) {
                return true;
            }
            right += 1;
        }
        return false;
    }
};