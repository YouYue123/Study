#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    cout << n << " ";
    while(n != 1) {
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n << " " ;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}