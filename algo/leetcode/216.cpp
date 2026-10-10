#include <bits/stdc++.h>
using namespace std;

// 216. Combination Sum III [M]
// LeetCode combination-sum-iii

class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, bool> visited; 
    void dfs(int k, int n, vector<int>& cur, int start) {
        if(n == 0) {
            if(cur.size() == k) ans.push_back(cur);
            return;
        }
        if(n < 0) return;
        for(int i = start; i <= 9; i ++) {
            if(visited[i]) continue;
            visited[i] = true;
            cur.push_back(i);
            dfs(k, n - i, cur, i + 1);
            cur.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        dfs(k, n, cur, 1);
        return ans;
    }
};