// 139. Word Break [M]
// LeetCode word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) return true;
            if(memo[i] != -1) return memo[i] == 1;
            bool ans = false;
            for(auto& w : wordDict) {
                if(s.substr(i, w.size()) ==  w) {
                    ans = dfs(i + w.size());
                }
                if(ans) break;
            }
            memo[i] = ans ? 1 : 0;
            return ans;
        };

        return dfs(0);
    }
};