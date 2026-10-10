#include <bits/stdc++.h>
using namespace std;

// 3714. Longest Balanced Substring II [M]
// LeetCode longest-balanced-substring-ii

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        // 一种字母
        auto case1 = [&] () {        
            int cnt = 1;
            for (int i = 1; i < n; i ++) {
                if(s[i] != s[i - 1]) {
                    cnt = 1;
                } else {
                    cnt += 1;
                }
                ans = max(ans, cnt);
            }
        };
        case1();

        // 两种字母
        auto case2 = [&](char x, char y) {
            unordered_map<int, int> memo;
            memo[0] = -1; 
            int curDiff = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == x) {
                    curDiff += 1;
                } else if (s[i] == y) {
                    curDiff -= 1;
                } else {
                    // 关键：遇到了第三种字符，强制重置
                    memo.clear();
                    curDiff = 0;
                    memo[0] = i;  // 新起点的差值为 0
                    continue;
                }
                if (memo.contains(curDiff)) {
                    ans = max(ans, i - memo[curDiff]);
                } else {
                    memo[curDiff] = i;
                }
            }
        };
        case2('a', 'b');
        case2('a', 'c');
        case2('b', 'c');

        // 三种字母
        auto case3 = [&]() {
            // 第一层 key: a-b, 第二层 key: b-c, value: 第一次出现的 index
            unordered_map<int, unordered_map<int, int>> memo;
            // 初始化哨兵值：当 a-b=0 且 b-c=0 时，索引为 -1
            memo[0][0] = -1;
            int a = 0, b = 0, c = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a') a++;
                else if (s[i] == 'b') b++;
                else if (s[i] == 'c') c++;

                int diff1 = a - b;
                int diff2 = b - c;
                if (memo.contains(diff1) && memo[diff1].contains(diff2)) {
                    ans = max(ans, i - memo[diff1][diff2]);
                } else {
                    // 记录第一次出现的位置
                    memo[diff1][diff2] = i;
                }
            }
        };
        case3();

        return ans;
    }
};