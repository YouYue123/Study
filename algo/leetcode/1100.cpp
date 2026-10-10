#include <bits/stdc++.h>
using namespace std;

// 1100. Find K-Length Substrings With No Repeated Characters [M]
// LeetCode find-k-length-substrings-with-no-repeated-characters

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int left = 0, right = 0;
        int ans = 0;
        int repeatCount = 0;
        unordered_map<char, int> dict;
        while(right < s.size()) {
            dict[s[right]] += 1;
            if(dict[s[right]] > 1) repeatCount += 1;
            if(right - left + 1 > k) {
                dict[s[left]] -= 1;
                if(dict[s[left]] >= 1) repeatCount -= 1;
                left += 1;
            }
            if(repeatCount == 0 && right - left + 1 == k) {
                ans += 1;
            } 
            right += 1;
        }
        return ans;
    }
};