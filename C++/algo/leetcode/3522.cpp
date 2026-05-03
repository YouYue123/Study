// 3522. Calculate Score After Performing Instructions [M]
// LeetCode calculate-score-after-performing-instructions

class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        unordered_map<int, bool> visited;
        int cur = 0;
        long long ans = 0;
        while(cur >= 0 && cur < instructions.size()) {
            if(visited[cur]) break;
            visited[cur] = true;
            string ins = instructions[cur];
            if(ins == "add") {
                ans += values[cur];
                cur += 1;
            } else {
                cur += values[cur];
            }
        }
        return ans;
    }
};