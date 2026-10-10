#include <bits/stdc++.h>
using namespace std;

// 3557. Find Maximum Number of Non Intersecting Substrings [M]
// LeetCode find-maximum-number-of-non-intersecting-substrings

// 为什么4个位置足够？
// 数学推导：

// 设当前字符位置为 i，历史位置为 j

// 要满足 i - j ≥ 3（即 j ≤ i - 3）

// 如果我们保留最多4个最近的 j，最旧的 j 是 i-4 或更早

// 检查条件：i - (i-4) = 4 ≥ 3（满足）

// 保留更多的历史位置（如第5个位置 i-5）会导致 i - (i-5) = 5 ≥ 3，虽然也满足，但：

// 更早的位置 j 对应的 dp[j] 值不会比最近的 j 更优（动态规划的非递减性质）

// 动态规划的最优子结构：

// dp[i] 是非递减的（因为我们可以选择不增加子串数量）

// 对于相同的字符 c，如果 j1 < j2，则 dp[j1] ≤ dp[j2]

// 因此，更近的 j 会给出更大的 dp[j] + 1，使得更早的 j 不可能成为最优解

// 反证法：

// 假设存在一个更早的位置 j_old（比如第5个历史位置）使得 dp[j_old] + 1 > dp[j_new] + 1

// 但由于 dp 是非递减的，且 j_old < j_new，必然有 dp[j_old] ≤ dp[j_new]

// 矛盾，因此假设不成立
class Solution {
public:
    int maxSubstrings(string word) {
        // 初始化26个字母的位置队列
        vector<deque<int>> last(26);
        for(int k = 0; k < 26; k++) {
            last[k] = deque<int>();
        }
        
        int n = word.size();
        vector<int> dp(n + 1, 0); // dp数组，dp[i]表示前i个字符的最大子串数
        
        for(int i = 0; i < n; i++) {
            int c = word[i] - 'a'; // 当前字符
            dp[i + 1] = dp[i]; // 默认不选当前字符
            // for(int j = i - 3; j >= 0; j --) {
            //     if(i - j + 1 >= 4 && word[i] == word[j]) dp[i + 1] = max(dp[i + 1], dp[j] + 1);
            // }
            // cout << dp[i + 1] << endl;
            // 检查该字符之前出现的位置
            for(int j : last[c]) {
                if(i - j + 1 >= 4) { // 如果距离足够大
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1); // 更新dp值
                }
            }
            
            // 维护该字符的位置队列（最多保留4个最近位置）
            last[c].push_back(i);
            if(last[c].size() > 4) last[c].pop_front();
        }
        
        return dp[n]; // 返回最终结果
    }
};