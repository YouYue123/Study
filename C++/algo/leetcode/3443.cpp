#include <bits/stdc++.h>
using namespace std;

// 3443. Maximum Manhattan Distance After K Changes [M]
// LeetCode maximum-manhattan-distance-after-k-changes

class Solution {
public:
    int maxDistance(string s, int k) {
        // NWSE
        // deltaY = 0, deltaX = 0
        // NSWWEW
        // NNWWWW
        const vector<pair<char, char>> comb = {
            {'N', 'E'}, {'N', 'W'},
            {'S', 'E'}, {'S', 'W'}
        };
        int ans = INT_MIN;
        for (const auto& [dir1, dir2] : comb) {
            int temp = 0;
            int tempK = k;
            for(char c : s) {
                if(c == dir1 || c == dir2) {
                    temp += 1;
                } else if(tempK > 0) {
                    tempK-= 1;
                    temp += 1;
                } else {
                    temp -=1;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};