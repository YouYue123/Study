#include <bits/stdc++.h>
using namespace std;

// 864. Shortest Path to Get All Keys [H]
// LeetCode shortest-path-to-get-all-keys

struct Node {
    int x;
    int y;
    int keyMask;
    int step;
};
class Solution {
public:
    bool isKey(char c) {
        if(c == '.' || c == '#' || c == '@') return false;
        return tolower(c) == c;
    }
    bool isLock(char c) {
        if(c == '.' || c == '#' || c == '@') return false;
        return tolower(c) != c;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startX = -1, startY = -1;
        queue<Node> q;
        int keyMask = -1, lockMask = -1;
        vector<pair<int, int>> keys;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == '.' || grid[i][j] == '#') continue;
                if(grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                } else {
                    if(isKey(grid[i][j])) {
                        keys.emplace_back(i, j);
                    }
                }
            }
        }
        unordered_map<int, unordered_map<int, int>> keyIdxDict;
        unordered_map<char, int> keyCharDict;
        for(int i = 0; i < keys.size(); i ++) {
            auto& p = keys[i];
            keyIdxDict[p.first][p.second] = i;
            keyCharDict[grid[p.first][p.second]] = i;
        }
        int fullKeyMask = (1 << keys.size()) - 1;
        q.emplace(startX, startY, 0, 0);
        vector<pair<int, int>> dirs = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(
                n,
                vector<bool>(
                    (1 << keys.size()),
                    false
                )
            )
        );
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int cx = cur.x;
            int cy = cur.y;
            int cStep = cur.step;
            int cKeyMask = cur.keyMask;
            if(visited[cx][cy][cKeyMask]) continue;
            visited[cx][cy][cKeyMask] = true;
            if(isLock(grid[cx][cy])) {
                char lock = grid[cx][cy];
                int requiredKeyMask = 1 << keyCharDict[tolower(lock)];
                // cout << "Lock required: " << requiredKeyMask << endl;
                if((cKeyMask & requiredKeyMask) == 0) continue;
            }
            int nKeyMask = cKeyMask;
            if(isKey(grid[cx][cy])) {
                nKeyMask |= 1 << keyIdxDict[cx][cy];
            }
            // cout << cx << " " << cy << " " << cStep << " " << nKeyMask << endl;
            if(nKeyMask == fullKeyMask) return cStep;
            for(int i = 0; i < 4; i ++) {
                int nx = cx + dirs[i].first;
                int ny = cy + dirs[i].second;
                if(nx < 0 || nx == m || ny < 0 || ny == n) continue;
                if(grid[nx][ny] == '#') continue;
                q.emplace(nx, ny, nKeyMask, cStep + 1);
            }
        }
        return -1;
    }
};