#include <bits/stdc++.h>
using namespace std;

// 3537. Fill a Special Grid [M]
// LeetCode fill-a-special-grid

class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        vector<vector<int>> ans(size, vector<int>(size, 0));
        auto fill = [&](auto&& self, int x, int y, int n, int cur) {
            if (n == 0) {
                ans[x][y] = cur;
                return;
            }
            int half = 1 << (n - 1);
            int q_size = 1 << (2 * n - 2);
            self(self, x, y + half, n - 1, cur);
            self(self, x + half, y + half, n - 1, cur + q_size);
            self(self, x + half, y, n - 1, cur + 2 * q_size);
            self(self, x, y, n - 1, cur + 3 * q_size);
        };
        fill(fill, 0, 0, N, 0);
        return ans;
    }
};