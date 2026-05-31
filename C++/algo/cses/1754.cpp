#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i ++) {
        ll a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) {
            cout << "YES" << endl;
            continue;   
        }
        if(a == 0 || b == 0) {
            cout << "NO" << endl;
            continue;
        }
        if((a + b) % 3 != 0) {
            cout << "NO" << endl;
            continue;
        }
        if(min(a, b) * 2 < max(a, b)) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}