#include <bits/stdc++.h>
using namespace std;

// 1750. Minimum Length of String After Deleting Similar Ends [M]
// LeetCode minimum-length-of-string-after-deleting-similar-ends

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right && s[left] == s[right]) {
            char cur = s[left];
            while(left <= right && s[left] == cur) left += 1;
            while(left <= right && s[right] == cur) right -= 1;
        }
        return right - left + 1;
    }
};