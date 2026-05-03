#include <bits/stdc++.h>
using namespace std;

// 2604. Minimum Time to Eat All Grains [H]
// LeetCode minimum-time-to-eat-all-grains

class Solution {
public:
    // 排序：首先对鸡和谷物的位置进行排序，以便按顺序处理。
    // 贪心匹配：对于每只鸡，尽可能多地吃掉未被吃掉的谷物。具体策略：
    // 当前鸡的位置hen和当前未被吃掉的第一个谷物grains[r]。
    // 如果hen在grains[r]的左边或右边，计算鸡需要移动的距离。
    // 根据时间预算t，判断鸡是否可以覆盖从hen到grains[r]及其后续的某些谷物。
     bool isValid(int t, vector<int>& hens, vector<int>& grains) {
        int n = grains.size(), cnt = 0;
        for (int hen: hens) {
            long long budget = t; // 当前鸡的时间预算
            if (hen > grains[cnt]) {
                // 鸡在谷物的右边
                if (hen - grains[cnt] > t) {
                    // 鸡无法到达最左边的谷物
                    return false;
                }
                long long diff = hen - grains[cnt];
                if (3 * diff >= budget) {
                    // 时间预算不足以覆盖往返和多余部分，只能覆盖部分谷物
                    budget = (budget - diff) / 2;
                } else {
                    // 时间预算足够覆盖往返和多余部分
                    budget = budget - 2 * diff;
                }
            }
            // 鸡可以覆盖从hen向左或向右的谷物
            while (cnt < n && grains[cnt] - hen <= budget) {
                cnt += 1; // 吃掉谷物
            }
            if (cnt == n) {
                // 所有谷物被吃掉
                return true;
            }
        }
        return false; // 仍有谷物未被吃掉
    }
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        sort(hens.begin(), hens.end());
        sort(grains.begin(), grains.end());
        int left = 0;
        int right = 2e9 + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, hens, grains)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};