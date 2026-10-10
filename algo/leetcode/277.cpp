#include <bits/stdc++.h>
using namespace std;

// 277. Find the Celebrity [M]
// LeetCode find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        if (n == 1) return 0;
        // 将所有候选人装进队列
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        // 一直排除，直到只剩下一个候选人停止循环
        while (q.size() >= 2) {
            // 每次取出两个候选人，排除一个
            int cand = q.front();
            q.pop();
            int other = q.front();
            q.pop();
            if (knows(cand, other) || !knows(other, cand)) {
                // cand 不可能是名人，排除，让 other 归队
                q.push(other);
            } else {
                // other 不可能是名人，排除，让 cand 归队
                q.push(cand);
            }
        }

        // 现在排除得只剩一个候选人，判断他是否真的是名人
        int cand = q.front();
        for (int other = 0; other < n; other++) {
            if (other == cand) {
                continue;
            }
            // 保证其他人都认识 cand，且 cand 不认识任何其他人
            if (!knows(other, cand) || knows(cand, other)) {
                return -1;
            }
        }
        // cand 是名人
        return cand;
    }
};