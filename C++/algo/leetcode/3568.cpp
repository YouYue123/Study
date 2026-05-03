// 3568. Minimum Moves to Clean the Classroom [M]
// LeetCode minimum-moves-to-clean-the-classroom

struct Node {
    int x;
    int y;
    int step;
    int energy;
    int mask;
    Node(int x, int y, int step, int energy, int mask)
        : x(x), y(y), step(step), energy(energy), mask(mask) {}
};
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        queue<Node> q;
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(classroom[i][j] == 'L') {
                    litters.emplace_back(i, j);
                }
                if(classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }
        int L = litters.size();
        int fullMask = (L == 0 ? 0 : (1 << L) - 1);
        // coor to bit index
        vector<vector<int>> litterIndex(m, vector<int>(n, -1));
        for(int i = 0; i < L; i ++) {
            auto& p = litters[i];
            litterIndex[p.first][p.second] = i;
        }
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>> (
                    energy + 1,
                    vector<bool>(1 << L, false)
                )
            )
        );
        int initMask = 0;
        q.emplace(startX, startY, 0, energy, initMask);
        visited[startX][startY][energy][initMask] = true;
        int dirs[4][2] = {{-1, 0}, {1,0}, {0,-1}, {0, 1}};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if(cur.mask == fullMask) return cur.step;
            int cx = cur.x;
            int cy = cur.y;
            int cenergy = cur.energy;
            int cmask = cur.mask;
            int cstep = cur.step;
            if(classroom[cx][cy] == 'R') {
                cenergy = energy;
                if(!visited[cx][cy][cenergy][cmask]) {
                    visited[cx][cy][cenergy][cmask] = true;
                    q.emplace(cx, cy, cstep, cenergy, cmask);
                }
            }
            if(cenergy == 0) continue;
            for(int d = 0; d < 4; d ++) {
                int nx = cx + dirs[d][0];
                int ny = cy + dirs[d][1];
                int nenergy = cenergy - 1;
                int nmask = cmask;
                int nstep = cstep + 1;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(classroom[nx][ny] == 'X') continue;
                if(classroom[nx][ny] == 'L') {
                    int idx = litterIndex[nx][ny];
                    if(idx >= 0) {
                        nmask |= (1 << idx);
                    }
                }
                if(nenergy < 0) continue;
                if(!visited[nx][ny][nenergy][nmask]) {
                    visited[nx][ny][nenergy][nmask] = true;
                    q.emplace(nx, ny, nstep, nenergy, nmask);
                }
            }
        }
        return -1;
    }
};