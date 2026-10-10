#include <bits/stdc++.h>
using namespace std;

// 3. Longest Substring Without Repeating Characters [M]
// LeetCode longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<int, int> dict;
        int ans = 0;
        while(right < n) {
            dict[s[right]] += 1;
            while(dict[s[right]] > 1) {
                dict[s[left]] -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};