#include <bits/stdc++.h>
using namespace std;

// 3661. Maximum Walls Destroyed by Robots [H]
// LeetCode maximum-walls-destroyed-by-robots

struct Robot {
    int pos;
    int dist;
};
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        sort(walls.begin(), walls.end());
        vector<Robot> arr;
        int n = robots.size();
        for(int i = 0; i < n; i ++) arr.emplace_back(robots[i], distance[i]);
        sort(arr.begin(), arr.end(), [&](auto& a, auto& b) {
            return a.pos < b.pos;
        });
        vector memo(
            n,
            vector(2, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, int state) {
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            auto r = arr[i];
            int leftX = r.pos - r.dist;
            if(i > 0) {
                auto prev = arr[i - 1];
                int prevReach = prev.pos;
                if(state == 1) {
                    prevReach = prev.pos + prev.dist;
                }
                leftX = max(leftX, prevReach + 1);
            }
            int left = lower_bound(walls.begin(), walls.end(), leftX) - walls.begin();
            int cur = upper_bound(walls.begin(), walls.end(), r.pos) - walls.begin();
            int ans = dfs(i + 1, 0) + cur - left;

            int rightX = r.pos + r.dist;
            if(i + 1 < n) {
                auto nxt = arr[i + 1];
                int nxtReach = nxt.pos;
                rightX = min(rightX, nxtReach - 1);
            }
            int right = upper_bound(walls.begin(), walls.end(), rightX) - walls.begin();
            cur = lower_bound(walls.begin(), walls.end(), r.pos) - walls.begin();
            ans = max(ans, dfs(i + 1, 1) + right - cur);
            return memo[i][state] = ans;
        };
        return dfs(0, 1);
    }
};