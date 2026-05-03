// 994. Rotting Oranges [M]
// LeetCode rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1 ,0}
        };
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 2) {
                    q.emplace(i, j);
                } else if(grid[i][j] == 1) {
                    cnt += 1;
                }
            }
        }
        cout << cnt << endl;
        if(cnt == 0) return 0;
        int time = 0;
        vector visited (m, vector(n, false));
        while(!q.empty() && cnt > 0) {
            int len = q.size();
            time += 1;
            for(int i = 0; i < len; i ++) {
                auto cur = q.front();
                q.pop();
                for(auto& d : dirs) {
                    int nx = cur.first + d.first, ny = cur.second + d.second;
                    if(nx >= m || nx < 0 || ny >= n || ny < 0) continue;
                    if(grid[nx][ny] == 1 && visited[nx][ny] == false) {
                        visited[nx][ny] = true;
                        q.emplace(nx, ny);
                        cnt -= 1;
                    }
                }
            }
        }
        return cnt == 0 ? time : -1;
    }
};