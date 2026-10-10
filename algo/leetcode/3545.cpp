#include <bits/stdc++.h>
using namespace std;

// 3545. Minimum Deletions for At Most K Distinct Characters [E]
// LeetCode minimum-deletions-for-at-most-k-distinct-characters

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> dict;
        int ans = 0;
        for(char c : s) dict[c] += 1;
        vector<pair<int, int>> ps;
        for(auto p : dict) {
            ps.push_back({ p.second, p.first });
        }
        sort(ps.begin(), ps.end(), greater<>());
        for(int i = 0; i < ps.size(); i ++) {
            // cout << i << endl;
            // cout << ps[i].first << endl;
            if(i >= k) ans += ps[i].first;
        }
        return ans;
    }
};