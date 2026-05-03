// 372. Super Pow [M]
// LeetCode super-pow

class Solution {
public:
    int MOD = 1337;
    long long binpow(long long a, long long b) {
        a %= MOD;
        long long ans = 1;
        while(b > 0) {
            if(b % 2) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        int part1 = binpow(a, last);
        int part2 = binpow(superPow(a, b), 10);
        return (part1 * part2) % MOD;
    }
};