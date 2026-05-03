// 3579. Minimum Steps to Convert String with Operations [H]
// LeetCode minimum-steps-to-convert-string-with-operations

class Solution {
public:
    int minOperations(string word1, string word2) {
        int n = word1.size();
        auto getOps = [&] (int start, int end, bool reversed) {
            int cnt[26][26]{};
            int ans = 0;
            for(int i = start; i <= end; i ++) {
                int x = word1[i] - 'a', y = 0;
                if(reversed) {
                    int reverseI = end + start - i;
                    // cout << "s: " << start << " e: " << end << " i : " << i << " r: " << reverseI << endl;
                    y = word2[reverseI] - 'a';
                } else {
                    y = word2[i] - 'a';
                }
                // cout << x << " " << y << endl;
                if(x != y) {
                    if(cnt[y][x] > 0) cnt[y][x] -= 1;
                    else {
                        cnt[x][y] += 1;
                        ans += 1;
                    }
                }
            }
            return ans;
        };
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                int fOps = getOps(i, j, false);
                int rOps = getOps(i, j, true) + 1;
                int remain = dfs(j + 1);
                if(remain != INT_MAX) ans = min(ans, remain + min(fOps, rOps));
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};