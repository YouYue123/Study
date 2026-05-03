// 2896. Apply Operations to Make Two Strings Equal [M]
// LeetCode apply-operations-to-make-two-strings-equal

int constexpr INF = 0x3f3f3f3f; 
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
       int n = s1.size();
       vector memo(n, vector(2, vector(n, -1)));
       auto dfs = [&](this auto&& dfs, int i, bool prevFlipped, int flipCnt) {
            if(flipCnt < 0) return INF;
            if(i == n) return flipCnt == 0 && prevFlipped == false ? 0 : INF;
            if( memo[i][prevFlipped][flipCnt] != -1) return  memo[i][prevFlipped][flipCnt];
            int ans = INF;
            if(
                (!prevFlipped && s1[i] == s2[i]) ||
                (prevFlipped  && s1[i] != s2[i])
            ) {
                ans = min(ans, dfs(i + 1, false, flipCnt));
            } else {
                ans = min({
                    ans,
                    dfs(i + 1, true, flipCnt) + 1,
                    dfs(i + 1, false, flipCnt - 1),
                    dfs(i + 1, false, flipCnt + 1) + x
                });
            }
            return memo[i][prevFlipped][flipCnt] = ans;
       }; 
       int ans = dfs(0, false, 0);
       return ans >= INF ? -1 : dfs(0, false, 0);
    }
};