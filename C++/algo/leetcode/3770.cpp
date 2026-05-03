// 3770. Largest Prime from Consecutive Prime Sum [M]
// LeetCode largest-prime-from-consecutive-prime-sum

const int MAX_N = 500000;
bool isComp[MAX_N + 1];
vector<int> primes;
void sieve() {
    isComp[1] = true;
    for(int p = 2; p * p <= MAX_N; ++p) {
        if(!isComp[p]) {
            for(int mul = p * p; mul <= MAX_N; mul += p) {
                isComp[mul] = true;
            }
        }
    }
    for(int i = 2; i <= MAX_N; i ++) {
        if(!isComp[i]) primes.push_back(i);
    }
}
class Solution {
public:
    int largestPrime(int n) {
        if(isComp[3] == false) sieve();
        int ans = 0;
        long long cur = 0;
        for(int p : primes) {
            cur += p;
            if(cur > n) break;
            if(cur <= MAX_N && !isComp[cur]) ans = cur;
        }
        return ans;
    }
};