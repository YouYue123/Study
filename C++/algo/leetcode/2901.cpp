#include <bits/stdc++.h>
using namespace std;

// 2901. Longest Unequal Adjacent Groups Subsequence II [M]
// LeetCode longest-unequal-adjacent-groups-subsequence-ii

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        auto isValid = [&] (string& a, string& b) {
            if(a.size() != b.size()) return false;
            int diff = 0;
            int m = a.size();
            for(int i = 0; i < m; i ++) diff += a[i] != b[i];
            return diff == 1;
        };
        vector<int> next(n, -1);
        vector memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = 0;
            for(int j = i + 1; j < n; j ++) {
                if(groups[j] == groups[i]) continue;
                if(!isValid(words[i], words[j])) continue;
                int candidate = dfs(j) + 1;
                if(candidate > ans) {
                    ans = candidate;
                    next[i] = j;
                }
            }
            return memo[i] = ans;
        };
        int maxLen = 0;
        int maxI = 0;
        for(int i = 0; i < n; i ++) {
            int candidate = dfs(i);
            if(candidate > maxLen) {
                maxLen = candidate;
                maxI = i;
            }
            // cout << i << " " << candidate << " " << maxI << endl;
        }
        vector<string> ans;
        for(int i = maxI; i >= 0; i = next[i]) {
            ans.push_back(words[i]);
        }
        return ans;
    }
};