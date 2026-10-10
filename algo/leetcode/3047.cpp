#include <bits/stdc++.h>
using namespace std;

// 3047. Find the Largest Area of Square Inside Two Rectangles [M]
// LeetCode find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        // 左下角取最大值，右上角取最小值 求交集
        int n = bottomLeft.size();
        long long ans = 0;
        for(int i = 0; i < n; i ++) {
            auto& bi = bottomLeft[i], ti = topRight[i];
            int bi_x = bi[0], bi_y = bi[1];
            int ti_x = ti[0], ti_y = ti[1];
            for(int j = i + 1; j < n; j ++) {
                auto& bj = bottomLeft[j], tj = topRight[j];
                int bj_x = bj[0], bj_y = bj[1];
                int tj_x = tj[0], tj_y = tj[1];
                int overlap_bl_x = max(bi_x, bj_x);
                int overlap_bl_y = max(bi_y, bj_y);
                int overlap_tr_x = min(ti_x, tj_x);
                int overlap_tr_y = min(ti_y, tj_y);
                // if(overlap_bl_x < overlap_tr_x && overlap_bl_y < overlap_tr_y) {
                int w = overlap_tr_x - overlap_bl_x;
                int h = overlap_tr_y - overlap_bl_y;
                // cout << w << " " << h << endl;
                long long side = min(w, h);
                ans = max(side, ans);
                // }
            }
        }
        return ans * ans;
    }
};