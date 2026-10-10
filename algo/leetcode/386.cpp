#include <bits/stdc++.h>
using namespace std;

// 386. Lexicographical Numbers [M]
// LeetCode lexicographical-numbers

class Solution {
public:
    int total = 0;
    int n = 0;
    vector<int> ans;
    void dfs(int cur) {
        // if(i > total) return;
        if(cur > n) return;
        ans.push_back(cur);
        for(int i = 0; i < 10; i ++) {
            dfs(cur * 10 + i);
        }
    }
    vector<int> lexicalOrder(int n) {
        this->n = n;
        // int temp = n;
        // while(temp > 0) {
        //     total += 1;
        //     temp /= 10; 
        // }
        for(int i = 1; i <= 9; i ++) {
            dfs(i);
        }
        return ans;
    }
};