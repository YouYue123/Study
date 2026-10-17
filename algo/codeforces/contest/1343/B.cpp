#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    int cnt = n / 2;
    if(cnt % 2 == 1) {
        cout << "NO" << endl;
        return;
    } 
    cout << "YES" << endl;
    ll sum = 0;
    for(int i = 0; i < cnt; i ++) {
        int num = i * 2 + 2;
        cout << num << " ";
        sum += num;
    }
    for(int i = 0; i < cnt - 1; i ++) {
        int num = i * 2 + 1;
        cout << num << " ";
        sum -= num;
    }
    cout << sum << endl;
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