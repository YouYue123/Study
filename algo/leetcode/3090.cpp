#include <bits/stdc++.h>
using namespace std;

// 3090. Maximum Length Substring With Two Occurrences [E]
// LeetCode maximum-length-substring-with-two-occurrences

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> dict;
        int left = 0, right = 0;
        int ans = 0;
        while(right < s.size()) {
            dict[s[right]] += 1;
            while(dict[s[right]] > 2) {
                dict[s[left]] -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};