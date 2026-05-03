// 3905. Multi Source Flood Fill [M]
// LeetCode multi-source-flood-fill

struct Item {
    int r;
    int c;
    int color;
    bool operator < (const Item& other) const {
        return color < other.color;  
    };
};
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<Item> q;
        vector ans(n, vector(m, 0));
        sort(sources.begin(), sources.end(), [&] (auto& a, auto& b) {
            return a[2] > b[2];
        });
        for(auto& s : sources) {
            int r = s[0], c = s[1], color = s[2];
            q.emplace(r, c, color);
            ans[r][c] = color;
        }
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < n; i ++) {
                auto item = q.front();
                q.pop();
                for(auto& dir : dirs) {
                    int nr = item.r + dir.first, nc = item.c + dir.second;
                    if(nr < 0 || nr == n || nc < 0 || nc >= m) continue;
                    if(ans[nr][nc] != 0) continue;
                    ans[nr][nc] = item.color;
                    q.emplace(nr, nc, item.color);
                }
            }
        }
        return ans;
    }
};