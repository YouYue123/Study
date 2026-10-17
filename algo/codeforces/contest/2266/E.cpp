#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 1e5 * 3;
bool isPrime[MAX_N];
vector<ll> prime_nums;
void sieve() {
    fill(isPrime, isPrime + MAX_N, true);
    // 1 is not prime
    isPrime[1] = false;
    for (int p = 2; p * p <= MAX_N; ++p) {
        if (isPrime[p]) {
            for (int mult = p * p; mult < MAX_N; mult += p) {
                // Mark multiples of non-prime
                isPrime[mult] = false; 
            }
        }
    }
    for(int num = 2; num < MAX_N; num ++) {
        if(isPrime[num]) prime_nums.push_back(num);
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll, greater<>> dict;
    for(int i = 0; i < n; i ++) {
        ll num = 0;
        cin >> num;
        dict[num] += 1;
    }
    auto get_prime_factors = [&] (ll num) {
        vector<ll> f;
        for(ll p : prime_nums) {
            if(p * p > num) break;
            while(num % p == 0) {
                f.push_back(p);
                num /= p;
            }
        }
        if(num > 1) f.push_back(num);
        return f; 
    };
    vector memo(1e5 * 2 + 1, -1LL);
    auto dfs = [&] (this auto&& dfs, ll num) {
        if(num <= k) return 0LL;
        if(memo[num] != -1LL) return memo[num];
        auto f = get_prime_factors(num);
        ll ans = INF;
        for(auto p : f) {
            ans = min(ans, 1 + dfs(num / p) * p);
        }
        return memo[num] = ans;
    };
    ll ans = 0;
    for(auto& [num, cnt] : dict) {
        ans += cnt * dfs(num);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}