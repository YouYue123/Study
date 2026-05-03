// 2707. Extra Characters in a String [M]
// LeetCode extra-characters-in-a-string

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector memo(n, - 1);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        auto dfs = [&] (this auto&& dfs, int r) {
            if(r < 0) return 0;
            if(memo[r] != -1) return memo[r];
            int ans = dfs(r - 1) + 1;
            for(int l = 0; l <= r; l ++) {
                string subs = s.substr(l, r - l + 1);
                if(dict.contains(subs)) {
                    ans = min(ans, dfs(l - 1));
                }
            }
            return memo[r] = ans;
        };
        return dfs(n - 1);
    }
};