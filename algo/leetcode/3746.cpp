#include <bits/stdc++.h>
using namespace std;

// 3746. Minimum String Length After Balanced Removals [M]
// LeetCode minimum-string-length-after-balanced-removals

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        // auto isValid = [&] (int mid) {
        //     int cntZero = 0;
            
        //     for(char c : s) {
        //         if(c == )
        //     }
        // };
        int ans = 0;
        for(char c : s) {
            ans += c == 'a' ? 1 : -1; 
        }
        return abs(ans);
    }
};