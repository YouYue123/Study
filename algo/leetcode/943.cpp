#include <bits/stdc++.h>
using namespace std;
/**
 * 【知识库】最短公共超串 (Shortest Superstring) - 状态压缩动态规划 (TSP变体)
 * 
 * * 1. 状态定义 (State Compression):
 * - 状态必须成对出现：dp[mask][last_idx]
 * - mask: 二进制位表示哪些单词已包含在当前超串中。
 * - last_idx: 最后一个加入超串的单词索引，决定了与下一个单词的“粘合度”。
 * 
 * * 2. 核心转化 (Reduction to TSP):
 * - 将单词抽象为“城市”，单词间的重叠长度抽象为“路径权重”。
 * - 原问题：构造最短长度超串。
 * - 转化后：求一条覆盖所有城市且【重叠长度之和最大】的 Hamiltonian 路径。
 * 
 * * 3. 路径还原 (Path Reconstruction):
 * - DP 仅存储最优值（Max Overlap），通过 path[mask][last] 记录转移决策。
 * - 从起始状态顺藤摸瓜，通过 mask |= (1 << nxt) 逐步还原完整字符串。
 * * 4. 复杂度分析:
 * - 时间复杂度: O(n² * 2ⁿ + ∑len)，其中 n 为单词数量，2ⁿ 是状态数。
 * - 空间复杂度: O(n * 2ⁿ)，主要是 memo 和 path 数组。
 */

class Solution {
    public:
        string shortestSuperstring(vector<string>& words) {
            int n = words.size();
            int full = (1 << n) - 1;
            vector<vector<int>> overlap(n, vector(n, 0));
            for(int i = 0; i < n; i ++) {
                for(int j = 0; j < n; j ++) {
                    if(i == j) continue;
                    int len1 = words[i].size(), len2 = words[j].size();
                    for(int k = min(len1, len2); k > 0; k --) {
                        if(words[i].substr(len1 - k) == words[j].substr(0, k)) {
                            overlap[i][j] = k;
                            break;
                        }
                    }
                }
            }
            vector memo(1 << n, vector(n, -1));
            vector path(1 << n, vector(n, -1));
            auto dfs = [&] (this auto&& dfs, int state, int prev) {
                if(full == state) return 0;
                if(memo[state][prev] != -1) return memo[state][prev];
                int ans = -1;
                for(int i = 0; i < n; i ++) {
                    if(state & (1 << i)) continue;
                    int cur = overlap[prev][i] + dfs(state | (1 << i), i);
                    if(cur > ans) {
                        ans = cur;
                        path[state][prev] = i;
                    }
                }
                return memo[state][prev] = ans;
            };
            int maxOverlap = -1;
            int firstWord = -1;
            for(int i = 0; i < n; i ++) {
                int cur = dfs(1 << i, i);
                if(cur > maxOverlap) {
                    maxOverlap = cur;
                    firstWord = i;
                }
            }
            string ans = words[firstWord];
            int curState = 1 << firstWord;
            int curLast = firstWord;
            while(path[curState][curLast] != -1) {
                int nxt = path[curState][curLast];
                ans += words[nxt].substr(overlap[curLast][nxt]);
                curState |= (1 << nxt);
                curLast = nxt;
            } 
            return ans;
        }
    };