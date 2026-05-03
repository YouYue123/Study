// 3767. Maximize Points After Choosing K Tasks [M]
// LeetCode maximize-points-after-choosing-k-tasks

class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long ans = 0;
        vector<long long> g(n);
        for(int i = 0; i < n; i ++) {
            ans += technique2[i];
            g[i] = (long long) technique1[i]  - technique2[i];
        }
        sort(g.begin(), g.end(), greater<>());
        for(int i = 0; i < k; i ++) ans += g[i];
        for(int i = k; i < n; i ++) {
            if(g[i] > 0) ans += g[i];
        }
        return ans;

    }
};