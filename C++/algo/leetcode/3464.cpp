#include <bits/stdc++.h>
using namespace std;

// 3464. Maximize the Distance Between Points on a Square [H]
// LeetCode maximize-the-distance-between-points-on-a-square

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> dist;
        long long totalDist = 4LL * side;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            long long d = 0;
            if (x == 0) d = y;
            else if (y == side) d = 1LL * side + x;
            else if (x == side) d = 2LL * side + (side - y);
            else if (y == 0) d = 3LL * side + (side - x);
            dist.push_back(d);
        }
        sort(dist.begin(), dist.end());

        // 展开为两倍长度处理环形
        for (int i = 0; i < n; ++i) dist.push_back(dist[i] + totalDist);

        auto isValid = [&](long long mid) -> bool {
            if (mid == 0) return true;
            
            // f[i] 表示从 i 开始往后跳，最多能选多少个点
            // next_pos[i] 表示从 i 开始跳 k 步后到达的点索引
            vector<int> f(2 * n + 1, 0);
            vector<int> jump(2 * n + 1, 2 * n); 
            
            int r = 0;
            for (int i = 0; i < 2 * n; ++i) {
                while (r < 2 * n && dist[r] < dist[i] + mid) {
                    r++;
                }
                jump[i] = r; // 从 i 出发，下一个合法的点至少是 r
            }

            // 使用倍增思想或者直接找从 i 开始跳 k 个点后的位置
            // 这里为了直观，我们记录从每个点开始跳 k 次后的位置
            for (int i = 0; i < n; ++i) {
                int curr = i;
                int count = 0;
                // 贪心跳 k-1 次
                for (int step = 0; step < k - 1; ++step) {
                    if (curr >= i + n) break;
                    curr = jump[curr];
                    if (curr >= i + n) break;
                    count++;
                }
                // 检查第 k 个点（即跳了 k-1 步后的那个点）与起点 i 的环绕距离
                if (count == k - 1 && curr < i + n && (dist[i] + totalDist - dist[curr]) >= mid) {
                    return true;
                }
            }
            return false;
        };
        int ans = 0;
        long long left = 0, right = totalDist / k;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isValid(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};