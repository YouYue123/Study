#include <bits/stdc++.h>
using namespace std;

// 2067. Number of Equal Count Substrings [M]
// LeetCode number-of-equal-count-substrings

class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int ans = 0;
        int maxUniq = unordered_set(s.begin(), s.end()).size();
        for(int uniq = 1; uniq <= maxUniq; uniq ++) {
            vector<int> dict(26, 0);
            int windowSize = count * uniq;
            if(windowSize > s.size()) break;
            int uniqCount = 0;
            int left = 0, right = 0;
            while(right < s.size()) {
                dict[s[right] - 'a'] += 1;
                if(dict[s[right] - 'a'] == count) uniqCount += 1;
                if(right - left + 1 > windowSize) {
                    dict[s[left] - 'a'] -= 1;
                    if(dict[s[left] - 'a'] == count - 1) uniqCount -= 1;
                    left += 1;
                }
                if(uniqCount == uniq) ans += 1;
                right += 1;
            }
        } 
        return ans;
    }
};