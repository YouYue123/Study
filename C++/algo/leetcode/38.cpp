#include <bits/stdc++.h>
using namespace std;

// 38. Count and Say [M]
// LeetCode count-and-say

class Solution {
public:
    string rle(string cur) {
        int left = 0, right = 0;
        int count = 0;
        string ans = "";
        // cout << cur << endl;
        for(int left = 0; left < cur.size();) {
            while(right < cur.size() && cur[right] == cur[left]) {
                right += 1;
            }
            ans += to_string(right - left);
            ans += cur[left];
            // cout << right << endl;
            left = right;
        }
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        return rle(countAndSay(n - 1));
    }
};