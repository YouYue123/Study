#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int constexpr INF = 0x3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int cnt = 1, max_cnt = 1;
    for(int i = 1; i < n; i ++) {
        // cout << a[i - 1] << " " << a[i] << endl;
        // cout << (a[i - 1] == a[i] ? "E" : "NE") << endl;
        if(a[i] == a[i - 1]) {
            cnt += 1;
        } else {
            cnt = 1;
        }
        max_cnt = max(max_cnt, cnt);
    }
    // cout << max_cnt << endl;
    cout << (max_cnt < m ? "YES" : "NO") << endl;
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