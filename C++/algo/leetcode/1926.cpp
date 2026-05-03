#include <bits/stdc++.h>
using namespace std;

// 1926. Nearest Exit from Entrance in Maze [M]
// LeetCode nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        unordered_map<int, unordered_map<int, bool>> visited;
        int m = maze.size(), n = maze[0].size();
        cout << m << " " << n << endl;
        q.push(entrance);
        int step = 0;
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i ++) {
                auto cur = q.front();
                q.pop();
                int x = cur[0], y = cur[1];
                // cout << "want to visit: " << x << " " << y << endl;
                // cout << maze[x][y] << endl;
                if(maze[x][y] == '+') continue;
                if(visited[x][y]) continue;
                visited[x][y] = true;
                // cout << "actual visit: " << x << " " << y << endl;
                if(x - 1 < 0 || y - 1 < 0 || x + 1 == m || y  + 1 == n) {
                    if(x != entrance[0] || y != entrance[1]) return step;
                }
                // cout << y+ 1 << endl;
                if(x + 1 < m) q.push({ x + 1, y });
                if(x - 1 >= 0) q.push({ x - 1, y });
                if(y + 1 < n) q.push({ x, y + 1 });
                if(y - 1 >= 0) q.push({ x, y - 1 });
            }
            step += 1;
        }
        return -1;
    }
};