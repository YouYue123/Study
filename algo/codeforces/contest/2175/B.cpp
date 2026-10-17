#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> S(n + 1);
    int cnt = 1;
    for(int i = 0; i <= n; i ++) {
        if(i == l - 1 || i == r) continue;
        S[i] = cnt;
        cnt += 1;
    }
    for(int i = 1; i <= n; i ++) {
        // S[i] XOR S[i-1] = S[i-1] XOR a[i] XOR S[i-1]
        int val = S[i] ^ S[i - 1];
        cout << val << " ";
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