// 1626. Best Team With No Conflicts [M]
// LeetCode best-team-with-no-conflicts

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        using pii = pair<int, int>;
        vector<pii> players;
        int n = scores.size();
        for(int i = 0; i < n; i ++) players.push_back({ ages[i], scores[i] });
        sort(players.begin(), players.end());
        vector memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) {
            if(i >= n) return 0;
            if(memo[i] != -1) return memo[i];
            auto& p = players[i];
            int curScore = p.second;
            int ans = curScore;;
            for(int j = 0; j < i; j ++) {
                if(players[j].second <= curScore) {
                    ans = max(
                        ans,
                        dfs(j) + curScore
                    );
                }
            }
            return memo[i] = ans;
        };
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};