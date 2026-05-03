// 233. Number of Digit One [H]
// LeetCode number-of-digit-one

class Solution {
public:
    int countDigitOne(int n) {
         string s = to_string(n);
         vector memo(
            s.size(),
            vector(
                s.size(),
                -1
            )
         );
         auto dfs = [&](this auto&& dfs, int i, int cnt, bool isLimit) {
            if(i == s.size())  return cnt;
            if(isLimit == false && memo[i][cnt] != -1) return memo[i][cnt];
            int ans = 0;
            int up = isLimit ? s[i] - '0' : 9;
            for(int num = 0; num <= up; num += 1) {
                ans += dfs(i + 1, cnt + (num == 1), isLimit && num == up);
            }
            return memo[i][cnt] = ans;
         };
         return dfs(0, 0, true);
    }
};