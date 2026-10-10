#include <bits/stdc++.h>
using namespace std;

// 1091. Shortest Path in Binary Matrix [M]
// LeetCode shortest-path-in-binary-matrix

struct Node {
    int x;
    int y;
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        auto hash = [&] (int x, int y) {
            return x * n + y;
        };
        queue<Node> q;
        unordered_set<int> visited;
        if(grid[0][0] == 0) {
            visited.insert(hash(0, 0));
            q.emplace(0, 0);
        }
        int dist = 1;
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                // cout << cur.x << " " << cur.y << endl;
                if(cur.x == n - 1 && cur.y == n - 1) {
                    return dist;
                }
                q.pop();
                for(auto& dir : dirs) {
                    int nx = cur.x + dir.first, ny = cur.y + dir.second;
                    int hash_val = hash(nx, ny);
                    // cout << nx << " " << ny << endl;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(grid[nx][ny] == 1 || visited.contains(hash_val)) continue;
                    visited.insert(hash_val);
                    q.emplace(nx, ny);
                }
            }
            dist += 1;
        }

        return -1;
    }
};