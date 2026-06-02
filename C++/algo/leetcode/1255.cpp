#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
            int n = words.size(), m = letters.size();
            int cnt[26] = {0};
            for(char c: letters) cnt[c - 'a'] += 1;
            vector memo((1 << 16), -1);
            auto dfs = [&] (this auto&& dfs, int mask) -> int {
                if(memo[mask] != -1) return memo[mask];
                int ans = 0;
                for(int i = 0; i < n; i ++) {
                    if(mask & (1 << i)) continue;
                    auto& w = words[i];
                    int cur = 0;
                    bool ok = true;
                    for(char c : w) {
                        if(cnt[c - 'a'] <= 0) ok = false;
                        cur += score[c - 'a'];
                        cnt[c - 'a'] -= 1;
                    }
                    if(ok) ans = max(ans, cur + dfs(mask | (1 << i)));
                    for(char c: w) cnt[c - 'a'] += 1;
                }
                return memo[mask] = ans;
            };
            return dfs(0);
        }
    };