#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int l, r;
    cin >> l >> r;
    int hb = 1 << (32 - __builtin_clz(l ^ r) - 1);
    int v = (l & r & ~(hb - 1)) | hb;
    if (v == r) {
        v--;
    }
    cout << v - 1 << " " << v << " " << v + 1 << endl;
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