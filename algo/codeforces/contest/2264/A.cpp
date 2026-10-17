#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector p(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> p[i];
    vector<int> mark_idxes;
    for(int i = 0; i < n; i ++) {
        if(p[i] != i + 1) mark_idxes.push_back(i);
    }
    int m = mark_idxes.size();
    // cout << m << endl;
    for(int i = 0; i < m / 2; i ++) {
        int a_idx = mark_idxes[i];
        int b_idx = mark_idxes[m - i - 1];
        // cout << a_idx << " " << b_idx << endl;
        int tmp = p[a_idx];
        p[a_idx] = p[b_idx];
        p[b_idx] = tmp;
    }
    bool ok = true;
    for(int i = 0; i < n; i ++) {
        if(p[i] != i + 1) { ok = false; break; }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}