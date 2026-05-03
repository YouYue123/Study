// 657. Robot Return to Origin [E]
// LeetCode robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> dirs = {
            {'U', {1, 0}}, {'D', {-1, 0}},
            {'L', {0, -1}}, {'R', {0, 1}} 
        };
        pair<int, int> cur = {0, 0};
        for(char move : moves) {
            cur.first += dirs[move].first;
            cur.second += dirs[move].second;
        }
        return cur.first == 0 && cur.second == 0;
    }
};