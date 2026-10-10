#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i ++) {
        int large_cnt = 0, small_cnt = 0;
        for(int j = i + 1; j < n; j ++) {
            if(a[j] > a[i]) large_cnt += 1;
            if(a[j] < a[i]) small_cnt += 1;
        }
        ans[i] = max(large_cnt, small_cnt);
    }
    for(int i = 0; i < n; i ++) {
        cout << ans[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl;
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