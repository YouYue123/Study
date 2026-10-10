#include <bits/stdc++.h>
using namespace std;

// 762. Prime Number of Set Bits in Binary Representation [E]
// LeetCode prime-number-of-set-bits-in-binary-representation

const int MAX_N = 1e6;
bool isPrime[MAX_N + 1];
void sieve() {
    std:fill(isPrime, isPrime + MAX_N + 1, true);
    isPrime[1] = false;
    for(int p = 2; p * p <= MAX_N; p ++) {
        if(isPrime[p]) {
            for(int mult = p * p; mult <= MAX_N; mult += p) {
                isPrime[mult] = false;
            }
        }
    }
}
class Solution {
private:
public:
    int countPrimeSetBits(int left, int right) {
        if(isPrime[2] == false) sieve();
        int cnt = 0;
        int ans = 0;
        for(int i = left ; i <= right; i ++) {
            int oneCnt = __builtin_popcount(i);
            // cout << i << " " << oneCnt << endl;
            // cout << isPrime[oneCnt] << endl;
            if(isPrime[oneCnt]) {
                ans += 1;
            }
        }
        return ans;
    }
};