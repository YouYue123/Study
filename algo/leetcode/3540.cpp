#include <bits/stdc++.h>
using namespace std;

// 3540. Minimum Time to Visit All Houses [M]
// LeetCode minimum-time-to-visit-all-houses

class Solution {
public:
    long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
        int n = forward.size();
        // 正向前缀和：fPresum[i] 表示从 0 正向移动到 i-1 的总时间
        vector<long long> fPresum(n + 1, 0);
        // 反向前缀和：bPresum[i] 表示从 0 反向移动到 (n - i) % n 的总时间
        vector<long long> bPresum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            fPresum[i] = fPresum[i - 1] + forward[i - 1];
            // backward[i % n] 是因为 backward 的索引是当前点的编号
            // 例如，bPresum[1] = backward[0], bPresum[2] = backward[0] + backward[n-1], ...
            bPresum[i] = bPresum[i - 1] + backward[i % n];
        }
        long long ans = 0;
        int prev = 0;
        for (int cur : queries) {
            if (cur > prev) {
                // 正向移动：fPresum[cur] - fPresum[prev]
                // 反向移动：bPresum[n] - bPresum[cur] + bPresum[prev]
                ans += min(
                    fPresum[cur] - fPresum[prev],
                    bPresum[n] - bPresum[cur] + bPresum[prev]
                );
            } else {
                // 反向移动：bPresum[prev] - bPresum[cur]
                // 正向移动：fPresum[n] - fPresum[prev] + fPresum[cur]
                ans += min(
                    bPresum[prev] - bPresum[cur],
                    fPresum[n] - fPresum[prev] + fPresum[cur]
                );
            }
            prev = cur;
        }
        return ans;
    }
};