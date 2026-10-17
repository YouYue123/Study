#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    int pos_x = 0, pos_y = 0;
    for(int i = m - 1; i >= 0; i --) {
        if(y[i] == '1') {
            pos_y = m - i;
            break;
        }
    }
    for(int i = n - pos_y; i >= 0; i --) {
        if(x[i] == '1') {
            pos_x = n - i;
            break;
        }
    }
    cout << max(0, pos_x - pos_y) << endl;
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