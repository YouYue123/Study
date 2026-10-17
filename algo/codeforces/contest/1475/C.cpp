#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    vector boys(k, 0LL);
    for(int i = 0; i < k; i ++) cin >> boys[i];
    vector girls(k, 0LL);
    for(int i = 0; i < k; i ++) cin >> girls[i];

    unordered_map<int, int> cnt_boy, cnt_girl;
    unordered_map<int, unordered_map<int, int>> cnt_both;
    for(int i = 0; i < k; i ++) {
        ll boy = boys[i], girl = girls[i];
        cnt_boy[boy] += 1;
        cnt_girl[girl] += 1;
        cnt_both[boy][girl] += 1;
    }
    ll ans = 0;
    for(int i = 0; i < k; i ++) {
        ll boy = boys[i], girl = girls[i];
        ll remove =  cnt_boy[boy] + cnt_girl[girl] - cnt_both[boy][girl];
        ans += k - remove;
    }
    cout << ans / 2 << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}