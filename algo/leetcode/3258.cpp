#include <bits/stdc++.h>
using namespace std;

// 3258. Count Substrings That Satisfy K-Constraint I [E]
// LeetCode count-substrings-that-satisfy-k-constraint-i

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count0 = 0;
        int count1 = 0;
        int left = 0, right = 0;
        int ans = 0;
        while(right < s.size()) {
            count0 += s[right] == '0';
            count1 += s[right] == '1';
            while(count0 > k && count1 > k) {
                count0 -= s[left] == '0';
                count1 -= s[left] == '1';
                left += 1;
            }
            // cout << left << " " << right << endl;
            ans += right - left + 1;
            right += 1;
        }
        return ans;
    }
};