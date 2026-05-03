#include <bits/stdc++.h>
using namespace std;

// 3320. Count The Number of Winning Sequences [H]
// LeetCode count-the-number-of-winning-sequences

int MOD = 1e9 + 7;
class Solution {
public:
    int countWinningSequences(string s) {
        int n = s.size();
        // F: 1, W: 2, E: 3
        // F > E, E > W, W > F
        vector memo(n, vector(4, vector(2001, -1)));
        auto dfs = [&](this auto&& dfs, int i, int bobPrev, int score) {
            if(i == n) return score > 1000 ? 1 : 0;
            if(memo[i][bobPrev][score] != -1) return memo[i][bobPrev][score];
            int ans = 0;
            for(int bob = 1; bob <= 3; bob ++) {
                if(bob == bobPrev) continue;
                int nxtScore = score;
                if(s[i] == 'F') {
                    if(bob == 3) nxtScore -= 1;
                    if(bob == 2) nxtScore += 1; 
                } else if(s[i] == 'W') {
                    if(bob == 1) nxtScore -= 1;
                    if(bob == 3) nxtScore += 1;
                } else if(s[i] == 'E') {
                    if(bob == 2) nxtScore -= 1;
                    if(bob == 1) nxtScore += 1;
                }
                ans = (ans + dfs(i + 1, bob, nxtScore)) % MOD;
            }
            return memo[i][bobPrev][score] = ans;
        };

        return dfs(0, 0, 1000);
    }
};