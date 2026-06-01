#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    ll total = 1 << n;
    for(int i = 0; i < total; i ++) {
        int gray = i ^ (i  >> 1);
        cout << bitset<32>(gray).to_string().substr(32 - n) << endl;
    }    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}