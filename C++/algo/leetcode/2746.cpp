// 2746. Decremental String Concatenation [M]
// LeetCode decremental-string-concatenation

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        vector memo(n, vector(27, vector(27, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int first, int last) {
            // cout << i  << " " << first << " " << last << endl;
            if(i == n) return 0;
            if(memo[i][first][last] != -1) return memo[i][first][last];
            auto& w = words[i];
            int wFirst = w[0] - 'a', wLast = w[w.size() - 1] - 'a';
            int ans = min({
                dfs(i + 1, first, wLast) + (last == wFirst ? w.size() - 1 : w.size()),
                dfs(i + 1, wFirst, last) + (wLast == first ? w.size() - 1 : w.size())
            });
            return memo[i][first][last] = ans;
        };
        string& str0 = words[0];
        return dfs(1, str0[0] - 'a', str0[str0.size() - 1] - 'a') + str0.size();
    }
};