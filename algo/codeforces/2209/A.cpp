#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ull n, c, k;
    cin >> n >> c >> k;
    vector<ull> a(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    ull ans = c;
    sort(a.begin(), a.end());
    for(auto item : a) {
        if(item <= ans) {
            if(k > 0) {
                auto diff = min(ans - item, k);
                k -= diff;
                item += diff;
            }
            ans += item;
        }
    }
    cout << ans << endl;
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