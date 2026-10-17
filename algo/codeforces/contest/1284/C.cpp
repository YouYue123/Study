#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 250001;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    ll fact[MAX_N];
    fact[0] = 1;
    fact[1] = 1;
    auto precompute = [&] () {
        for(int i = 2; i < MAX_N; i ++) {
            fact[i] = (fact[i - 1] * i) % m;
        }
    };
    auto mod_mult = [&] (ll a, ll b) {
        return a * b % m;
    };
    auto mod_add = [&] (ll a, ll b) {
        return (a + b) % m;
    };
    precompute();
    for(int len = 1; len <= n; len ++) {
        ans = mod_add(
            ans, 
            mod_mult(
                mod_mult(
                    n - len + 1, // 1. 数值区间的选择种数 (比如 1~3, 2~4)
                    fact[len]    // 2. 选定的这些数字在区间内的全排列
                ), 
                mod_mult(
                    n - len + 1,  // 3. 这个区间在 permutation 里的起始位置选择
                    fact[n - len] // 4. 剩余数字在区间外的全排列
                )
            )
        );
    }
    cout << ans << endl;
}