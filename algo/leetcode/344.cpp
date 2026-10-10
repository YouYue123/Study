#include <bits/stdc++.h>
using namespace std;

// 344. Reverse String [E]
// LeetCode reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            swap(s[left], s[right]);
            left += 1;
            right -= 1;
        }
    }
};