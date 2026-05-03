// 3363. Find the Maximum Number of Fruits Collected [H]
// LeetCode find-the-maximum-number-of-fruits-collected

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector memo(n, vector<int>(n, -1)); // -1 表示没有计算过
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (j < n - 1 - i || j >= n) {
                return 0;
            }
            if (i == 0) {
                return fruits[i][j];
            }
            int& res = memo[i][j]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            return res = max({dfs(i - 1, j - 1), dfs(i - 1, j), dfs(i - 1, j + 1)}) + fruits[i][j];
        };

        int ans = 0;
        // 从 (0, 0) 出发的小朋友
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        // 从 (0, n - 1) 出发的小朋友（倒着走）
        ans += dfs(n - 2, n - 1); // 从下往上走，方便 1:1 翻译成递推

        // 从 (n - 1, 0) 出发的小朋友（按照主对角线翻转，然后倒着走）
        // 把下三角形中的数据填到上三角形中
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                fruits[j][i] = fruits[i][j];
            }
        }
        ranges::fill(memo, vector(n, -1));
        return ans + dfs(n - 2, n - 1);
    }
};