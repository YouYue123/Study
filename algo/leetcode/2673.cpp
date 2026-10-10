#include <bits/stdc++.h>
using namespace std;

// 2673. Make Costs of Paths Equal in a Binary Tree [M]
// LeetCode make-costs-of-paths-equal-in-a-binary-tree

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n / 2 - 1; i >=0; i --) {
            // cout << "i: " << i;
            int left = i * 2 + 1, right = i * 2 + 2;
            // cout << "left: " << left << "right: " << right;
            ans += abs(cost[left] - cost[right]);
            // cout << "ans: " << ans << endl;
            cost[i] += max(cost[left], cost[right]);
        }
        return ans;
    }
};