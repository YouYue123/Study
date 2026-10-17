#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int p;
    cin >> p;
    vector b(n + 2, 0);
    b[0] = 1;
    b[n + 1] = 1;
    for(int i = 0; i < n; i ++) {
        if(a[i] == a[p - 1]) {
            b[i + 1] = 1;
        } else {
            b[i + 1] = 0;
        }
    }
    int left_cnt = 0, right_cnt = 0;
    for(int i = 0; i <= n; i ++) {
        if(b[i] != b[i + 1]) {
            if(i < p) {
                left_cnt += 1;
            } else {
                right_cnt += 1;
            }
        }
    }
    cout << max(left_cnt, right_cnt) << endl;
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