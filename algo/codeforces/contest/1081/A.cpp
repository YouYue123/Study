#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int K = 0;
    bool hasConsec = false;
    for(int i = 0 ; i < n; i ++) {
        int nxIdx = (i + 1) % n;
        if(s[i] != s[nxIdx]) {
            K += 1;
        } else {
            hasConsec = true;
        }
    }
    if(K == 0) {
        cout << 1 << endl;
        return;
    }
    if(hasConsec) {
        cout << K + 1 << endl;
        return;
    } else {
        cout << K << endl;
        return;
    }
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