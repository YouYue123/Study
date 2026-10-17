#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// 5 10
// 10 4 15 1 8 
// 2

// 3 42
// 1000000000 1000000000 1000000000
// 3

// 10 30
// 29 25 2 12 15 42 14 6 16 9
// 6

// 10 1000000
// 1 1 1 1 1 1 1 1 1 864026633
// 1 

void solve()
{
    int n, c;
    std::cin >> n >> c;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++)  cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    int cnt = 0;
    int k = 1;
    int i = 0;
    // cout << "Case " << endl;
    while(i < n) {
        if(a[i] * k <= c) {
            // cout << a[i] << " ";
            cnt += 1;
            k *= 2;
        }
        i += 1;
    }
    // cout << endl;
    cout << n - cnt << endl;
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