#include <bits/stdc++.h>
using namespace std;

// 2271. Maximum White Tiles Covered by a Carpet [M]
// LeetCode maximum-white-tiles-covered-by-a-carpet

#define ll long long

// 获取当前区间的权重值（如果有第三个元素则使用，否则默认为1）
#define cost(x) ((intervals[x].size() > 2) ? intervals[x][2] : 1)
class Solution {
public:
// 从左向右滑动窗口，查找最大权重和
    ll slide(vector<vector<int>>& intervals, int k) {
        sort(intervals.begin(), intervals.end());  // 按区间起点排序
        ll currentWeightSum = 0, maxWeightSum = 0, totalIntervals = intervals.size(), partialWeight;

        for (int left = 0, right = 0; left < totalIntervals; ++left) {
            int intervalStart = intervals[left][0];
            int intervalEnd = intervals[left][1];
            int windowRightBound = intervalStart + k - 1;

            partialWeight = 0;

            // 将完全落入窗口的区间计入 currentWeightSum
            while (right < totalIntervals && intervals[right][1] <= windowRightBound) {
                currentWeightSum += 1LL * cost(right) * (intervals[right][1] - intervals[right][0] + 1);
                ++right;
            }

            // 若存在与窗口部分重叠的区间，计算其重叠部分贡献
            if (right < totalIntervals) {
                partialWeight = 1LL * max(0, windowRightBound - intervals[right][0] + 1) * cost(right);
            }

            maxWeightSum = max(maxWeightSum, currentWeightSum + partialWeight);

            // 移除当前左端区间对 currentWeightSum 的影响
            currentWeightSum -= 1LL * (intervalEnd - intervalStart + 1) * cost(left);
        }

        return maxWeightSum;
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        return slide(tiles, carpetLen);
    }
};