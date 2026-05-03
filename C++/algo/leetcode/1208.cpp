#include <bits/stdc++.h>
using namespace std;

// 1208. Get Equal Substrings Within Budget [M]
// LeetCode get-equal-substrings-within-budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int curCost = 0;
        int ans = 0;
        while(right < s.size()) {
            curCost += abs(s[right] - t[right]);
            while(curCost > maxCost) {
                curCost -= abs(s[left] - t[left]);
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};