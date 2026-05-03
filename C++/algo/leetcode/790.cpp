// 790. Domino and Tromino Tiling [M]
// LeetCode domino-and-tromino-tiling

class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, int> memoF;
    unordered_map<int, int> memoP;
    long f(int k) {
        if(k == 1) return 1;
        else if(k == 2) return 2;
        if(memoF.contains(k)) return memoF[k];
        return memoF[k] = (f(k - 1) + f(k - 2) + 2 * p (k - 1)) % mod;
    }
    long p(int k) {
        if(k == 2) return 1;
        if(memoP.contains(k)) return memoP[k];
        return memoP[k] = (p(k - 1) + f(k - 2)) % mod;
    }
    int numTilings(int n) {
        return f(n);
    }
};