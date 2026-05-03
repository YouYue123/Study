// 1591. Strange Printer II [H]
// LeetCode strange-printer-ii

int constexpr INF = 0x3f3f3f3f;
struct Limit {
    int min_r = INF;
    int max_r = -INF;
    int min_c = INF;
    int max_c = -INF;
};
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size(), n = targetGrid[0].size();
        unordered_map<int, Limit> dict;
        for(int r = 0; r < m ; r ++) {
            for(int c = 0; c < n; c ++) {
                int color = targetGrid[r][c];
                // cout << "r: " << r << " c: " << c << " color: " <<color << endl;
                dict[color].min_r = min(dict[color].min_r, r);
                dict[color].max_r = max(dict[color].max_r, r);
                dict[color].min_c = min(dict[color].min_c, c);
                dict[color].max_c = max(dict[color].max_c, c);
            }
        }

        unordered_map<int, vector<int>> g;
        unordered_map<int, int> degree;
        for(auto& [color, limit] : dict) {
            // cout << color << endl;
            // cout << limit.min_r << " " << limit.max_r << endl;
            // cout << limit.min_c << " " << limit.max_c << endl;
            for(int r = limit.min_r; r <= limit.max_r; r ++) {
                for(int c = limit.min_c; c <= limit.max_c; c ++) {
                    int cur_color = targetGrid[r][c];
                    if(cur_color != color) {
                        g[color].push_back(cur_color);
                        degree[cur_color] += 1;
                    }
                }
            }
        }
        queue<int> q;
        for(auto& [color, _] : g ) {
            // cout << color << " degree: " << degree[color] << endl;
            if(degree[color] == 0) {
                q.push(color);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt += 1;
            for(auto& nxt : g[cur]) {
                degree[nxt] -= 1;
                if(degree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        return cnt == g.size();
    }
};