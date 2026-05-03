// 499. The Maze III [H]
// LeetCode the-maze-iii

struct Node {
    int dist;
    string path;
    int r, c;
    // C++20 自动生成比较逻辑：先比距离，距离相同比字符串字典序
    auto operator<=>(const Node& other) const {
        if (auto cmp = dist <=> other.dist; cmp != 0) return cmp;
        return path <=> other.path;
    }
    // priority_queue 需要 > 来构建小顶堆
    bool operator>(const Node& other) const { return (*this <=> other) > 0; }
};

class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int rows = maze.size(), cols = maze[0].size();
        // 存储到达每个点 [r, c] 的 {最短距离, 最小字典序路径}
        vector dists(rows, vector(cols, pair{numeric_limits<int>::max(), ""s}));
        
        priority_queue<Node, vector<Node>, greater<>> pq;
        
        // 初始化起点
        pq.emplace(0, "", ball[0], ball[1]);
        dists[ball[0]][ball[1]] = {0, ""};

        // 方向定义（按 d, l, r, u 顺序其实没关系，因为 Node 内部有字典序比较）
        const vector<tuple<int, int, char>> dirs = {
            {1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}, {-1, 0, 'u'}
        };

        while (!pq.empty()) {
            auto [d, p, r, c] = pq.top();
            pq.pop();

            if (pair{d, p} > dists[r][c]) continue;
            if (r == hole[0] && c == hole[1]) return p;

            for (const auto& [dr, dc, stepChar] : dirs) {
                int nr = r, nc = c, stepCount = 0;

                // 物理模拟：球会一直滚动直到撞墙或掉进洞里
                while (nr + dr >= 0 && nr + dr < rows && nc + dc >= 0 && nc + dc < cols 
                       && maze[nr + dr][nc + dc] == 0) {
                    nr += dr;
                    nc += dc;
                    stepCount++;
                    if (nr == hole[0] && nc == hole[1]) break;
                }

                int totalDist = d + stepCount;
                string totalPath = p + stepChar;
                
                // 入队前判断：距离更短，或者距离相等但字典序更小
                if (stepCount > 0) {
                    if (pair{totalDist, totalPath} < dists[nr][nc]) {
                        dists[nr][nc] = {totalDist, totalPath};
                        pq.emplace(totalDist, totalPath, nr, nc);
                    }
                }
            }
        }

        return "impossible";
    }
};