#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n + 1);
    vector<int> pos(n + 1, 0);
    vector<vector<int>> at_height(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = max(pos[a[i]], i);
        at_height[a[i]].push_back(i);
    }

    vector<int> R_max(n + 1, 0);
    for (int h = 1; h <= n; ++h) {
        R_max[h] = max(R_max[h - 1], pos[h - 1]);
    }

    vector<int> bit(n + 1, 0);
    auto update = [&](int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    };
    auto query = [&](int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    };

    ll initial_M = 0;
    for (int h = n; h >= 1; --h) {
        for (int i : at_height[h]) {
            update(i, 1);
        }
        if (R_max[h] > 1) {
            initial_M += query(R_max[h] - 1);
        }
    }

    ll max_delta = 0;
    for (int k = 1; k <= n; ++k) {
        int H = a[k];
        ll current_delta = 0;
        if (k < R_max[H]) {
            current_delta = -1;
        } else {
            current_delta = (ll)k - 1 - R_max[H];
        }
        max_delta = max(max_delta, current_delta);
    }

    cout << initial_M + max_delta << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}