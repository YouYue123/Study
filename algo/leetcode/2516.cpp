#include <bits/stdc++.h>
using namespace std;

// 2516. Take K of Each Character From Left and Right [M]
// LeetCode take-k-of-each-character-from-left-and-right

class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> dict;
        for(char c : s) dict[c] += 1;
        if(dict['a'] < k || dict['b'] < k|| dict['c'] < k) return -1;
        if(dict['a'] == k && dict['b'] == k && dict['c'] == k) return k * 3;

        int left = 0, right = 0;
        int ans = INT_MAX;
        while(right < s.size()) {
            dict[s[right]] -= 1;
            while(dict[s[right]] < k) {
                dict[s[left]] += 1;
                left += 1;
            }
            if(left <= right) {
                // cout << left << " " << right << endl;
                int curSize = right - left + 1;
                ans = min(ans, (int)s.size() - curSize);
            }
            right += 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};