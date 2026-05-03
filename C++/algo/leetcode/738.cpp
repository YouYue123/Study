#include <bits/stdc++.h>
using namespace std;

// 738. Monotone Increasing Digits [M]
// LeetCode monotone-increasing-digits

class Solution {
    string s;
    string memo[12][11]; // 记忆化：pos, pre

    // 返回从 pos 位开始，给定前一位 pre，能构造出的最大单调递增字符串
    string dfs(int pos, int pre, bool is_limit) {
        if (pos == s.size()) return ""; // 递归终点
        
        // 只有在非限制状态下才使用记忆化（限制状态下的结果不可复用）
        if (!is_limit && memo[pos][pre] != "") return memo[pos][pre];

        int up = is_limit ? s[pos] - '0' : 9; // 当前位的最大可选范围
        string res = "";

        // 贪心思路：为了让整体最大，当前位 i 应该从 up 开始倒着试
        for (int i = up; i >= pre; i--) {
            // 尝试填入 i，递归寻找后面能构造出的最大后缀
            string next_res = dfs(pos + 1, i, is_limit && (i == up));
            if (next_res != "-1") { // 如果后面能构造成功
                res = to_string(i) + next_res;
                break; // 既然是倒序试，第一个成功的肯定是最大的
            }
        }

        if (res == "") res = "-1"; // 无法构造则标记为 -1
        if (!is_limit) memo[pos][pre] = res;
        return res;
    }

public:
    int monotoneIncreasingDigits(int n) {
        s = to_string(n);
        // 清空 memo
        for(int i=0; i<12; i++) for(int j=0; j<11; j++) memo[i][j] = "";
        
        return stoi(dfs(0, 0, true));
    }
};