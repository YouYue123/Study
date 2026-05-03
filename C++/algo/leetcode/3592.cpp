// 3592. Inverse Coin Change [M]
// LeetCode inverse-coin-change

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> f(n + 1);
        f[0] = 1;
        vector<int> ans;
        for(int i = 1; i <= n; i ++) {
            int w = numWays[i - 1];
            if(w == f[i]) continue;
            if(w != f[i] + 1) return {};
            ans.push_back(i);
            for(int j = i; j <= n; j += 1) {
                f[j] += f[j - i];
            }
        }
        return ans;
    }
};