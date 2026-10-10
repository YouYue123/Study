#include <bits/stdc++.h>
using namespace std;

// 2943. Maximize Area of Square Hole in Grid [M]
// LeetCode maximize-area-of-square-hole-in-grid

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto getMaxConsec = [&] (vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int maxCnt = 1, curCnt = 1;
            for(int i = 1; i < bars.size(); i ++) {
                if(bars[i] != bars[i - 1] + 1) {
                    curCnt = 1;
                } else {
                    curCnt += 1;
                }
                maxCnt = max(maxCnt, curCnt);
            }  
            return maxCnt;
        };
        int h = getMaxConsec(hBars);
        int v = getMaxConsec(vBars);
        int maxLen = min(h + 1, v + 1);
        return maxLen * maxLen;
    }
};