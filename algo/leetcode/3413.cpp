#include <bits/stdc++.h>
using namespace std;

// 3413. Maximum Coins From K Consecutive Bags [M]
// LeetCode maximum-coins-from-k-consecutive-bags

#define ll long long

// 获取当前区间的权重值（如果有第三个元素则使用，否则默认为1）
#define cost(x) ((intervals[x].size() > 2) ? intervals[x][2] : 1)

class Solution {
public:
    // 从左向右滑动窗口，查找最大权重和
    ll slide(vector<vector<int>>& intervals, int k) {
        sort(intervals.begin(), intervals.end());  // 按区间起点排序
        ll cur = 0, ans = 0, n = intervals.size();
        int left = 0, right = 0;
        while(left < n) {
            int start = intervals[left][0];
            int end = intervals[left][1];
            int rightBound = start + k - 1;
            int partial = 0;
            // 将完全落入窗口的区间计入
            while (right < n && intervals[right][1] <= rightBound) {
                cur += 1LL * cost(right) * (intervals[right][1] - intervals[right][0] + 1);
                ++right;
            }
            // 若存在与窗口部分重叠的区间，计算其重叠部分贡献
            if (right < n) {
                partial = 1LL * max(0, rightBound - intervals[right][0] + 1) * cost(right);
            }
            ans = max(ans, cur + partial);
            // 移除当前左端区间的影响
            cur -= 1LL * (end - start + 1) * cost(left);
            left += 1;
        }
        return ans;
    }

    // 从右向左滑动窗口，查找最大权重和
    ll reverseSlide(vector<vector<int>>& intervals, int k) {
        sort(intervals.begin(), intervals.end());  // 按区间起点排序
        ll cur = 0, ans = 0, n = intervals.size();
        int right = n - 1, left = n - 1;
        while(right >= 0) {
            int start = intervals[right][0];
            int end = intervals[right][1];
            int leftBound = end - k + 1;
            int partial = 0;
            // 将完全落入窗口的区间计入
            while (left >= 0 && leftBound <= intervals[left][0]) {
                cur += 1LL * cost(left) * (intervals[left][1] - intervals[left][0] + 1);
                --left;
            }
            // 若存在与窗口部分重叠的区间，计算其重叠部分贡献
            if (left >= 0) {
                partial = 1LL * max(0, intervals[left][1] - leftBound + 1) * cost(left);
            }
            ans = max(ans, cur + partial);
            // 移除当前右端区间的影响
            cur -= 1LL * (end - start + 1) * cost(right);
            right -= 1;
        }
        return ans;
    }

    // 计算滑动窗口 k 范围内可获得的最大权重和（正向或反向）
    ll maximumCoins(vector<vector<int>>& coins, int k) {
        return max(slide(coins, k), reverseSlide(coins, k));
    }
};
