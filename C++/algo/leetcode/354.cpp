// 354. Russian Doll Envelopes [H]
// LeetCode russian-doll-envelopes

struct Pair {
    int w;
    int h;
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](const auto& a, const auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> g;
        for(int i = 0; i < n ; i ++) {
            int h = envelopes[i][1];
            auto idx = lower_bound(g.begin(), g.end(), h) - g.begin();
            if(idx == g.size()) {
                g.push_back(h);
            } else {
                g[idx] = h;
            }
        }
        return g.size();
    }
};