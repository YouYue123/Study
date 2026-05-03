#include <bits/stdc++.h>
using namespace std;

// 756. Pyramid Transition Matrix [M]
// LeetCode pyramid-transition-matrix

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        string dict[6][6] {};
        for(string& s : allowed) dict[s[0] - 'A'][s[1] - 'A'] += s[2];
        int n = bottom.size();
        vector<string> arr(n);
        for(int i = 0; i < n; ++i) arr[i].resize(i + 1);
        arr[n - 1] = move(bottom);
        unordered_set<string> vis;
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i < 0) return true;
            if(j == i + 1) {
                if(!vis.insert(arr[i]).second) return false;
                return dfs(i - 1, 0);
            }
            char left = arr[i + 1][j];
            char right = arr[i + 1][j + 1];
            for(char cur : dict[left - 'A'][right - 'A']) {
                arr[i][j] = cur;
                if(dfs(i, j + 1)) return true;
            }
            return false;
        };
        return dfs(n - 2, 0);
    }
};