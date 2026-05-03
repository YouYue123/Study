// 874. Walking Robot Simulation [M]
// LeetCode walking-robot-simulation

int constexpr INF = 0x3f3f3f3f;
using pii = pair<int, int>;
struct Coord {
    int x;
    int y;
};
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
};
class Solution {
    vector<Coord> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    Direction curDir = Direction::NORTH;
    Coord pos = {0, 0};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> obsByX;
        unordered_map<int, set<int>> obsByY;
        for(auto& obstacle : obstacles) {
            int x = obstacle[0], y = obstacle[1];
            obsByX[x].insert(y);
            obsByY[y].insert(x);
        }
      
        int ans = 0;
        for(int command : commands) {
            if(command == -1) {
                curDir = static_cast<Direction>((static_cast<int>(curDir) + 1) % 4);
            } else if(command == -2) {
                curDir = static_cast<Direction>((static_cast<int>(curDir) - 1 + 4) % 4);
            } else {
                auto& dir = dirs[static_cast<int>(curDir)];
                int nxtX = pos.x + command * dir.x;
                int nxtY = pos.y + command * dir.y;
                if(curDir == NORTH) {
                    auto& s = obsByX[pos.x];
                    auto it = s.upper_bound(pos.y);
                    if(it != s.end() && *it <= nxtY) nxtY = *it - 1;
                    pos.y = nxtY;
                } else if(curDir == EAST) {
                    auto& s = obsByY[pos.y];
                    auto it = s.upper_bound(pos.x);
                    if(it != s.end() && *it <= nxtX) nxtX = *it - 1;
                    pos.x = nxtX;
                } else if(curDir == SOUTH) {
                    auto& s = obsByX[pos.x];
                    auto it = s.lower_bound(pos.y);
                    if(it != s.begin() && *(--it) >= nxtY) nxtY = *it + 1;
                    pos.y = nxtY;
                } else if(curDir == WEST) {
                    auto& s = obsByY[pos.y];
                    auto it = s.lower_bound(pos.x);
                    if(it != s.begin() && *(--it) >= nxtX) nxtX = *it + 1;
                    pos.x = nxtX;
                }
            }
            // cout << pos.first << " " << pos.second << endl; 
            ans = max(ans, pos.x * pos.x + pos.y * pos.y);
        }
        return ans;
    }
};