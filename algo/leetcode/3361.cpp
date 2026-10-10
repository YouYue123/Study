#include <bits/stdc++.h>
using namespace std;

// 3361. Shift Distance Between Two Strings [M]
// LeetCode shift-distance-between-two-strings

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        for(int i = 0; i < s.size(); i ++) {
            int next = s[i] - 'a', prev = s[i] - 'a';
            long long nextCnt = 0, prevCnt = 0;
            while(next !=  t[i] - 'a') {
                nextCnt += nextCost[next];
                next = (next + 1) % 26;
            }
            while(prev != t[i] - 'a') {
                prevCnt += previousCost[prev];
                prev = (prev + 26 - 1) % 26;
            }
            // cout << nextCnt << " " << prevCnt << endl;
            ans += min(nextCnt, prevCnt);
        }
        return ans;
    }
};