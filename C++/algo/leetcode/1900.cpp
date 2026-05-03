#include <bits/stdc++.h>
using namespace std;

// 1900. The Earliest and Latest Rounds Where Players Compete [H]
// LeetCode the-earliest-and-latest-rounds-where-players-compete

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector memo(n + 1, vector(n + 1, vector<pair<int, int>>(n + 1)));

        auto dfs = [&](this auto&& dfs, int n, int first, int second) -> pair<int, int> {
            // AB 相遇
            if (first + second == n + 1) {
                return {1, 1};
            }

            // 保证 A 左边人数比 B 右边人数少
            // 注：题目已保证 first < second
            if (first + second > n + 1) {
                tie(first, second) = pair(n + 1 - second, n + 1 - first);
            }

            auto& res = memo[n][first][second]; // 注意这里是引用
            if (res.first) { // 之前计算过
                return res;
            }

            int m = (n + 1) / 2; // 下一回合人数
            // AB 之间保留 [min_mid, max_mid) 个人
            int min_mid = second <= m ? 0 : second - n / 2 - 1;
            int max_mid = second <= m ? second - first : m - first;
            int earliest = INT_MAX;
            int latest = 0;

            for (int left = 0; left < first; left++) { // 枚举 A 左侧保留 left 个人
                for (int mid = min_mid; mid < max_mid; mid++) { // 枚举 AB 之间保留 mid 个人
                    // 无需枚举 B 右侧保留多少个人，因为剩下的 m-2-left-mid 个人都在 B 右侧
                    auto [e, l] = dfs(m, left + 1, left + mid + 2);
                    earliest = min(earliest, e);
                    latest = max(latest, l);
                }
            }

            // 加上当前回合
            return res = {earliest + 1, latest + 1};
        };

        auto [earliest, latest] = dfs(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};