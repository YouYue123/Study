#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int num;
    int cnt;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    // if(n > m) 
    
    ll ans = 0;
    while(m > n) {
        if(m % 2 == 1) {
            m += 1;
        } else {
            m /= 2;
        }
        ans += 1;
    }
    
    ans += (n - m);
    cout << ans << endl;
}