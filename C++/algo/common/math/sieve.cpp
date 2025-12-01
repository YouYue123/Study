const int MAX_N = 1e5;
bool is_composite[MAX_N + 1]; // is_composite[i] = true if i is composite, false if i is prime

void sieve() {
    is_composite[1] = true; // 1 is not a prime number
    for (int p = 2; p * p <= MAX_N; ++p) {
        if (!is_composite[p]) { // If p is prime
            for (int multiple = p * p; multiple <= MAX_N; multiple += p) {
                is_composite[multiple] = true; // Mark multiples of p as composite
            }
        }
    }
}
