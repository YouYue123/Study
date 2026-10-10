#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ll MAX = 2000005;
ll fact[MAX], invFact[MAX];

ll power(ll base, ll exp) {
    ll ans = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp % 2 == 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return ans;
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for(int i = 1; i < MAX; i ++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for(int i = MAX - 2; i >= 1; i --) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int j = 0; j < q; j ++) {
        ll op, l, r, m;
        cin >> op >> l >> r >> m;
        ll s_fixed = 0;
        ll p = 0;
        for(int i = l; i <= r; i ++) {
            if(a[i] > 0) s_fixed += a[i];
            if(a[i] == -1) p += 1;
        }

        if(s_fixed > m) {
            cout << 0 << endl;
            continue;
        }

        if(p == 0) {
            if(s_fixed != m) {
                cout << 0 << endl;
            } else {
                ll F = 0, ans = 0;
                for(int i = l; i <= r; i ++) {
                    if(a[i] > 0) F = (F + a[i]) % MOD;
                    ans = (ans + F * F % MOD) % MOD;
                }
                cout << ans << endl;
            }
            continue;
        }

        ll rem = m - s_fixed;
        ll W = C(rem + p - 1, p - 1);
        ll Sigma_1 = C(rem + p - 1, p);
        ll Sigma_2 = C(rem + p - 1, p + 1);

        ll F = 0;
        p = 0;
        ll sum_F2 = 0, sum_Fp = 0, sum_p = 0, sum_p2 = 0;
        for(int i = l; i <= r; i ++) {
            if(a[i] > 0) F = (F + a[i]) % MOD;
            if(a[i] == -1) p = (p + 1) % MOD;
            sum_F2 = (sum_F2 + F * F % MOD) % MOD;
            sum_Fp = (sum_Fp + F * p % MOD) % MOD;
            sum_p = (sum_p + p) % MOD;
            sum_p2 = (sum_p2 + p * (p + 1) % MOD) % MOD;
        }
        ll ans = (W * sum_F2) % MOD;
        ans = (ans + 2 * Sigma_1 % MOD * sum_Fp) % MOD;
        ans = (ans + Sigma_1 * sum_p) % MOD;
        ans = (ans + Sigma_2 * sum_p2) % MOD;
        cout << ans << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    precompute();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}