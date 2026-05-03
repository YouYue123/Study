#include <bits/stdc++.h>
using namespace std;

// 1217. Minimum Cost to Move Chips to The Same Position [E]
// LeetCode minimum-cost-to-move-chips-to-the-same-position

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> count(4, 0);
        for (int p : position) {
            if (p > 3) {
                p = p % 2 + 2;
            }
            count[p] += 1;
        }

        return count[1] + count[3] > count[2] ? count[2] : count[1] + count[3];
    }
};