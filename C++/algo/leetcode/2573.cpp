#include <bits/stdc++.h>
using namespace std;

// 2573. Find the String with LCP [H]
// LeetCode find-the-string-with-lcp

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 0); // 初始化长度为 n 的空字符串
        char cur = 'a';

        // 1. 贪心构造字符串
        for (int i = 0; i < n; i++) {
            if (s[i] != 0) continue; // 已经分配过字符
            if (cur > 'z') return ""; // 超过 26 个字母，无法构造
            
            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = cur;
                }
            }
            cur++;
        }

        // 2. 验证构造出的字符串是否完全符合 lcp 矩阵
        // 使用 DP 从右下角向上递推验证
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int actual_lcp = 0;
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1) {
                        actual_lcp = 1;
                    } else {
                        actual_lcp = lcp[i + 1][j + 1] + 1;
                    }
                }
                
                if (lcp[i][j] != actual_lcp) {
                    return "";
                }
            }
        }

        return s;
    }
};