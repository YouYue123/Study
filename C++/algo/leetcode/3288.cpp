#include <bits/stdc++.h>
using namespace std;

// 3288. Length of the Longest Increasing Path [H]
// LeetCode length-of-the-longest-increasing-path

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int kx = coordinates[k][0], ky = coordinates[k][1];
        sort(coordinates.begin(), coordinates.end(), [&](auto& a, auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> g;
        for(auto& p : coordinates) {
            int x = p[0], y = p[1];
            if(x < kx && y < ky || x > kx && y > ky) {
                auto idx = lower_bound(g.begin(), g.end(), y) - g.begin();
                if(idx == g.size()) g.push_back(y);
                else g[idx] = y;
            }
        }
        return g.size() + 1;
    }
};