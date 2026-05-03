#include <bits/stdc++.h>
using namespace std;

// 1320. Minimum Distance to Type a Word Using Two Fingers [H]
// LeetCode minimum-distance-to-type-a-word-using-two-fingers

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        using pii = pair<int, int>;
        auto getCoord = [&] (int pos) {
            return pii(pos / 6, pos % 6);
        };
        auto getDist = [&](const pii& a, const pii& b) {
            return abs(a.first - b.first) + abs(a.second - b.second);
        };
        vector memo(n, vector(27, vector(27, -1)));
        auto dfs = [&](this auto&& dfs, int i, int f1, int f2) {
            if(i == n) return 0;
            if(memo[i][f1][f2] != -1) return memo[i][f1][f2];
            int cur = word[i] - 'A';
            int ans = INF;
            auto coord1 = getCoord(f1);
            auto coord2 = getCoord(f2);
            auto coordNx = getCoord(cur);
            if(f1 == 26) {
                ans = min(ans, dfs(i + 1, cur, f2));
            } else {
                ans = min(ans, dfs(i + 1, cur, f2) + getDist(coord1, coordNx));
            }
            if(f2 == 26) {
                ans = min(ans, dfs(i + 1, f1, cur));
            } else {
                ans = min(ans, dfs(i + 1, f1, cur) + getDist(coord2, coordNx));
            }
            return memo[i][f1][f2] = ans;
        };
        return dfs(0, 26, 26);
    }
};