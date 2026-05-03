// 1129. Shortest Path with Alternating Colors [M]
// LeetCode shortest-path-with-alternating-colors

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int id;
    // 0 for red, 1 for blue
    int color;
    int dist;
};
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector r_g(n, vector<int>());
        vector b_g(n, vector<int>());
        for(auto& e : redEdges) {
            int u = e[0] , v = e[1];
            r_g[u].push_back(v);
        }
        for(auto& e : blueEdges) {
            int u = e[0], v = e[1];
            b_g[u].push_back(v);
        }
        vector visit(n, vector(2, false));
        queue<Node> q;
        q.emplace(0, 0, 0);
        q.emplace(0, 1, 0);
        visit[0][0] = true;
        visit[0][1] = true;
        vector ans(n, -1);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(ans[cur.id] == -1) ans[cur.id] = cur.dist;
            auto& g = cur.color == 0 ? b_g : r_g;
            for(int nxt_id : g[cur.id]) {
                int nxt_dist = cur.dist + 1;
                int nxt_color = cur.color ^ 1;
                if(visit[nxt_id][nxt_color]) continue;
                visit[nxt_id][nxt_color] = true;
                q.emplace(nxt_id, nxt_color, nxt_dist);
            }
        }
        return ans;
    }
};