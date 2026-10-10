#include <bits/stdc++.h>
using namespace std;

// 1765. Map of Highest Peak [M]
// LeetCode map-of-highest-peak

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int x;
    int y;
    int val;
};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        vector ans(m, vector(n, INF));
        vector visitd(m, vector(n, false));
        queue<Node> q;

        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(isWater[i][j] == 1) {
                    q.emplace(i, j, 0);
                    visitd[i][j] = true;
                }
            }
        }
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            ans[cur.x][cur.y] = cur.val;
            for(auto& d : dirs) {
                int nx = cur.x + d.first, ny = cur.y + d.second;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(visitd[nx][ny]) continue;
                visitd[nx][ny] = true;
                q.emplace(nx, ny, cur.val + 1);
            }
        }
        return ans;
    }
};