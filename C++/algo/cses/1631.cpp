#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    ll max_val = *max_element(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    cout << max(sum, 2 * max_val) << endl;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}