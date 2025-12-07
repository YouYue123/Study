#include <bits/stdc++.h>
const int MAX_N = 1e5;
bool isPrime[MAX_N + 1];
void sieve() {
    std::fill(isPrime, isPrime + MAX_N + 1, true);
    // 1 is not prime
    isPrime[1] = false;
    for (int p = 2; p * p <= MAX_N; ++p) {
        if (isPrime[p]) {
            for (int mult = p * p; mult <= MAX_N; mult += p) {
                // Mark multiples of non-prime
                isPrime[mult] = false; 
            }
        }
    }
}
