#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> generatePalindromes(string s) {
            int n = s.size();
            vector cnt(26, 0);
            for(char c : s) cnt[c - 'a'] += 1;
            vector<string> ans;
            string mid = "";
            int odd_cnt = 0, odd_idx = 0;
            for(int i = 0; i < 26; i ++) {
                if(cnt[i] % 2 == 1) {
                    odd_cnt += 1;
                    odd_idx = i;
                }
            }
            if(odd_cnt > 1) {
                return ans;
            } else if(odd_cnt == 1) {
                mid += odd_idx + 'a';
                cnt[odd_idx] -= 1;
            }
            for(int i = 0; i < 26; i ++) cnt[i] /= 2;
    
            auto dfs = [&] (this auto&& dfs, string& cur) {
                if(cur.size() == n / 2) {
                    string back = cur;
                    reverse(back.begin(), back.end());
                    ans.push_back(
                        cur + mid + back
                    );
                    return;
                }
                for(int i = 0; i < 26; i ++) {
                    if(cnt[i] == 0) continue;
                    cnt[i] -= 1;
                    cur.push_back(i + 'a');
                    dfs(cur);
                    cur.pop_back();
                    cnt[i] += 1;
                }
            };
            string tmp = "";
            dfs(tmp);
            return ans;
        }
    };