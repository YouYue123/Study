#include <bits/stdc++.h>
using namespace std;

// 1297. Maximum Number of Occurrences of a Substring [M]
// LeetCode maximum-number-of-occurrences-of-a-substring

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int left = 0, right = 0;
        int uniqCount = 0;
        unordered_map<char, int> dict;
        int ans = 0;
        unordered_map<string, int> count;
        while(right < s.size()) {
            dict[s[right]] += 1;
            if(dict[s[right]] == 1) uniqCount += 1;
            while(uniqCount > maxLetters || right - left + 1 > minSize) {
                dict[s[left]] -= 1;
                if(dict[s[left]] == 0) uniqCount -= 1;
                left += 1;
            }
            if(right - left + 1 >= minSize) {
                string subs = s.substr(left, right - left + 1);
                // cout << subs << endl;
                count[subs] += 1;
                ans = max(ans, count[subs]);
            }
            right += 1;
        }
        return ans;
    }
};