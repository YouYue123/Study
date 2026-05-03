// 3552. Grid Teleportation Traversal [M]
// LeetCode grid-teleportation-traversal

struct Node {
    int i, j, step;
    Node(int i, int j, int step) : i(i), j(j), step(step) {}
};

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<char, vector<pair<int, int>>> teleDict;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = matrix[i][j];
                if (isalpha(c)) {
                    teleDict[c].emplace_back(i, j);
                }
            }
        }
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<Node> q;
        q.emplace_back(0, 0, 0);
        dist[0][0] = 0;
        
        vector<int> di = {-1, 0, 1, 0};
        vector<int> dj = {0, 1, 0, -1};
        
        while (!q.empty()) {
            Node cur = q.front();
            q.pop_front();
            int i = cur.i, j = cur.j, step = cur.step;            
            if (i == m - 1 && j == n - 1) return step;
            if (step > dist[i][j]) continue;
            char c = matrix[i][j];
            if (isalpha(c)) {
                for (auto& [ni, nj] : teleDict[c]) {
                    if (dist[ni][nj] > step) {
                        dist[ni][nj] = step;
                        q.emplace_front(ni, nj, step);
                    }
                }
                teleDict.erase(c);
            }
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && 
                    matrix[ni][nj] != '#' && dist[ni][nj] > step + 1) {
                    dist[ni][nj] = step + 1;
                    q.emplace_back(ni, nj, step + 1);
                }
            }
        }
        return -1; 
    }
};