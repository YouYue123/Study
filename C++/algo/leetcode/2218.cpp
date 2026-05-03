#include <bits/stdc++.h>
using namespace std;

// 2218. Maximum Value of K Coins From Piles [H]
// LeetCode maximum-value-of-k-coins-from-piles

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector memo(
            n,
            vector(k, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(cnt == k) return 0;
            if(i >= n) return INT_MIN;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int curCnt = cnt;
            int curSum = 0;
            int ans = dfs(i + 1, cnt);
            for(auto& c : piles[i]) {
                curCnt += 1;
                curSum += c;
                if(curCnt > k) break;
                ans = max(
                    ans,
                    dfs(i + 1, curCnt) + curSum
                );
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};