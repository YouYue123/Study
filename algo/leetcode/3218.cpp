#include <bits/stdc++.h>
using namespace std;

// 3218. Minimum Cost for Cutting Cake I [M]
// LeetCode minimum-cost-for-cutting-cake-i

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        long long ans = 0;
        int hCnt = 0, vCnt = 0; // i 指向当前最小的水平切割，j 指向当前最小的垂直切割
        // 2. 只要还有没切过的线，就继续循环
        while(hCnt < m - 1 || vCnt < n - 1) {
            // 如果垂直切完了 (j == n-1)
            // 或者：水平还没切完，且当前水平切割代价小于垂直切割代价
            if(vCnt == n - 1 || (hCnt <  m - 1 && horizontalCut[hCnt] < verticalCut[vCnt])) {
                //【水平切割】
                // 贪心逻辑：先切便宜的。
                // 此时水平线 i 会穿过所有“还未处理”的垂直区域。
                // 剩余的垂直切割线有 (n-1 - j) 条，说明当前垂直方向被分成了 (n - j) 块。
                ans += horizontalCut[hCnt] * (n - vCnt);
                hCnt ++;
            } else {
                //【垂直切割】
                // 此时垂直线 j 会穿过所有“还未处理”的水平区域。
                // 剩余的水平切割线有 (m-1 - i) 条，说明当前水平方向被分成了 (m - i) 块。
                ans += verticalCut[vCnt] * (m - hCnt);
                vCnt ++;
            }
        }
        return ans;
    }
};