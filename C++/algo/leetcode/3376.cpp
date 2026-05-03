#include <bits/stdc++.h>
using namespace std;

// 3376. Minimum Time to Break Locks I [M]
// LeetCode minimum-time-to-break-locks-i

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int full = (1 << n) - 1;
        vector memo(vector(1 << n, -1));
        auto dfs = [&] (this auto&& dfs, int state) {
            if(state == full) return 0;
            if(memo[state] != -1) return memo[state];
            int ans = INF;
            int cnt = __builtin_popcount(state);
            int factor = cnt * k + 1;
            // cout << factor << " " << state << endl;
            for(int i = 0; i < n; i ++) {
                int curRep = (1 << i);
                if(state & curRep) continue;
                int s = strength[i];
                int t = s / factor + (s % factor == 0 ? 0 : 1);
                int nxtState = state | curRep;
                ans = min(
                    ans,
                    dfs(nxtState) + t
                );
            }
            return memo[state] = ans;
        };
        return dfs(0);
    }
};