#include <bits/stdc++.h>
using namespace std;

// 3219. Minimum Cost for Cutting Cake II [H]
// LeetCode minimum-cost-for-cutting-cake-ii

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater());
        sort(verticalCut.begin(), verticalCut.end(), greater());
        long long ans = 0;
        int hCnt = 1, vCnt = 1;
        int h = 0, v = 0;
        while(h < horizontalCut.size() && v < verticalCut.size()) {
            if(horizontalCut[h] > verticalCut[v]) {
                ans += horizontalCut[h] * vCnt;
                hCnt += 1;
                h += 1;
            } else {
                ans += verticalCut[v] * hCnt;
                vCnt += 1;
                v += 1;
            }
        }
        while(h < horizontalCut.size()) {
            ans += horizontalCut[h] * vCnt;
            h += 1;
        }
        while(v < verticalCut.size()) {
            ans += verticalCut[v] * hCnt;
            v += 1;
        }
        return ans;
    }
};