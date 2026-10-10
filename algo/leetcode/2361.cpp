#include <bits/stdc++.h>
using namespace std;

// 2361. Minimum Costs Using the Train Line [H]
// LeetCode minimum-costs-using-the-train-line

class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector memo(n + 1, vector(2, -1LL));
        auto dfs = [&] (this auto&& dfs, int i, int state) -> long long {
            if(i == 0) {
                if(state == 1) return expressCost;
                return 0;
            }
            if(memo[i][state] != -1LL) return memo[i][state];
            long long ans = 0;
            if(state == 0) {
                ans = min(
                    dfs(i - 1, 0) + regular[i - 1], 
                    dfs(i - 1, 1) + express[i - 1]
                );
            } else if(state == 1) {
                ans = min(
                    dfs(i - 1, 1) + express[i - 1],
                    dfs(i - 1, 0) + regular[i - 1] + expressCost
                );
            }
            return memo[i][state] = ans;
        };
        dfs(n, 0);
        dfs(n, 1);
        vector<long long> ans;
        for(int i = 1; i <= n; i ++) {
            // cout << memo[i][0] << " " << memo[i][1] << endl;
            ans.push_back(min(
                memo[i][0],
                memo[i][1]
            ));
        }
        return ans;
    }
};