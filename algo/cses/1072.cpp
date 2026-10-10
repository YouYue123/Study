#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    
    auto calc = [&] (ll x) {
        ll base = (x * x) * (x * x - 1) / 2;
        ll remove = 4 * (x - 1) * (x - 2);
        return base - remove;
    };
    for(int i = 1; i <= n; i ++) {
        cout << (ll)calc(i) << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}