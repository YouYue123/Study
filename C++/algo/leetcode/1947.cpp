// 1947. Maximum Compatibility Score Sum [M]
// LeetCode maximum-compatibility-score-sum

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students[0].size();
        vector<int> studentScore, mentorScore;
        int mask = (1 << n) - 1;
        for(int i = 0; i < m; i ++) {
            int studentS = 0, mentorS = 0;
            for(int j = 0; j < n; j ++) {
                studentS |= (students[i][j] << j);
                mentorS |= (mentors[i][j] << j);
            }
            studentScore.push_back(studentS);
            mentorScore.push_back(mentorS);
        }
        vector memo(1 << m, -1);
        auto dfs = [&] (this auto&& dfs, int state) {
            int i = __builtin_popcount(state);
            if(i == m) return 0;
            if(memo[state] != -1) return memo[state]; 
            int ans = 0;
            for(int j = 0; j < m; j ++) {
                if(state & (1 << j)) continue;
                int score = __builtin_popcount(~(studentScore[i] ^ mentorScore[j]) & mask);
                ans = max(
                    ans,
                    dfs(state | (1 << j)) + score
                );
            }
            return memo[state] = ans;
        };
        return dfs(0);
    }
};