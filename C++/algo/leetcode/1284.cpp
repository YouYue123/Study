#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 0x3f3f3f3f;
struct Item {
    int state;
    int step;
};
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int t_state = 0;
        auto get_pos = [&] (int i, int j) {
            return i * n + j;
        };
        auto explain_state = [&] (int state) {
            for(int i = 0; i < m; i ++) {
                for(int j = 0; j < n; j ++) {
                    int pos = get_pos(i, j);
                    if((state & (1 << pos))) {
                        cout << 1 << " ";
                    } else {
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        };
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
        // unordered_map<int, int> visit;
        // auto dfs = [&] (this auto&& dfs, int cur_state, int level) {
        //     // cout << "explain state: " << cur_state << endl;
        //     // cout << "level: " << level << endl;
        //     // explain_state(cur_state);
        //     if(cur_state == t_state) return 0;
        //     if(visit.contains(cur_state) && visit[cur_state] <= level) return INF;
        //     visit[cur_state] = level;
        //     int ans = INF;
        //     for(int i = 0; i < m; i ++) {
        //         for(int j = 0; j < n; j ++) {
        //             int pos = get_pos(i, j);
        //             int nxt_state = cur_state ^ (1 << pos);
        //             for(auto& dir : dirs) {
        //                 int nxt_i = i + dir.first, nxt_j = j + dir.second;
        //                 if(nxt_i < 0 || nxt_i >= m || nxt_j < 0 || nxt_j >= n) continue;
        //                 int nxt_pos = get_pos(nxt_i, nxt_j);
        //                 nxt_state ^= (1 << nxt_pos);
        //             }
        //             ans = min(ans, 1 + dfs(nxt_state, level + 1));
        //         }
        //     }
        //     return ans;
        // };
        int init_state = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int pos = get_pos(i, j);
                // cout << pos << endl;
                if(mat[i][j] == 1) init_state ^= (1 << pos);
            }
        }
        queue<Item> q;
        q.emplace(init_state, 0);
        unordered_set<int> visit;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur.state == t_state) return cur.step;
            for(int i = 0; i < m; i ++) {
                for(int j = 0; j < n; j ++) {
                    int pos = get_pos(i, j);
                    int nxt_state = cur.state ^ (1 << pos);
                    for(auto& dir : dirs) {
                        int nxt_i = i + dir.first, nxt_j = j + dir.second;
                        if(nxt_i < 0 || nxt_i >= m || nxt_j < 0 || nxt_j >= n) continue;
                        int nxt_pos = get_pos(nxt_i, nxt_j);
                        nxt_state ^= (1 << nxt_pos);
                    }
                    if(visit.contains(nxt_state)) continue;
                    visit.insert(nxt_state);
                    q.emplace(nxt_state, cur.step + 1);
                }
            }
        }
        // cout << "init_state: "  << init_state << endl;
        // int ans = dfs(init_state, 0);
        return -1;
    }
};