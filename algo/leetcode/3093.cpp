#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 0x3f3f3f3f;
ll BASE_1 = 131, MOD_1 = 1e9 + 7;
ll BASE_2 = 13331, MOD_2 = 1e9 + 9; 
struct Item {
    int idx;
    int s_len;
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size(), m = wordsQuery.size();
        unordered_map<ll, Item> dict;
        int default_idx = 0, min_dist = INF;
        for(int i = 0; i < n; i ++) {
            auto& w = wordsContainer[i];
            // cout << w << endl;
            ll h1 = 0, h2 = 0;
            if(w.size() < min_dist) {
                default_idx = i;
                min_dist = w.size();
            }
            for(int j = w.size() - 1; j >= 0; j --) {
                h1 = (h1 * BASE_1 % MOD_1 + w[j]) % MOD_1;
                h2 = (h2 * BASE_2 % MOD_2 + w[j]) % MOD_2;
                ll hash_val = h1 << 32 | h2;
                if(dict.contains(hash_val)) {
                    if(dict[hash_val].s_len > w.size()) {
                        dict[hash_val].s_len = w.size();
                        dict[hash_val].idx = i;
                    }
                } else {
                   dict[hash_val] = Item(i, w.size());
                }
            }
        }
        vector<int> ans(m, default_idx);
        for(int i = 0; i < m; i ++) {
            auto& q = wordsQuery[i];
            ll h1 = 0, h2 = 0;
            for(int j = q.size() - 1; j >= 0; j --) {
                h1 = (h1 * BASE_1 % MOD_1 + q[j]) % MOD_1;
                h2 = (h2 * BASE_2 % MOD_2 + q[j]) % MOD_2;
                ll hash_val = h1 << 32 | h2;
                if(dict.contains(hash_val)) {
                    // cout << "match: " << q.substr(j, q.size() - j) << endl;
                    ans[i] = dict[hash_val].idx;
                }
            }
        }

        return ans;
    }
};