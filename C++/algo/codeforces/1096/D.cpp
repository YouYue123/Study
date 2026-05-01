#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int p1 = -1, p2 = -1;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(2 * n);
    vector<Pos> pos(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        if (pos[a[i]].p1 == -1) pos[a[i]].p1 = i;
        else pos[a[i]].p2 = i;
    }

    int ans = 1;
    set<int> centers;
    centers.insert(pos[0].p1 + pos[0].p2);
    centers.insert(2 * pos[0].p1);
    centers.insert(2 * pos[0].p2);

    vector<int> pref_bad(2 * n + 1, 0);
    vector<bool> is_bad(n, false);

    for (int S : centers) {
        for (int i = 0; i < n; i++) {
            if (pos[i].p1 + pos[i].p2 == S) is_bad[i] = false;
            else if (2 * pos[i].p1 == S) is_bad[i] = false;
            else if (2 * pos[i].p2 == S) is_bad[i] = false;
            else is_bad[i] = true;
        }

        for (int i = 0; i < 2 * n; i++) {
            pref_bad[i + 1] = pref_bad[i] + (is_bad[a[i]] ? 1 : 0);
        }

        int L = 2 * n, R = -1;
        for (int k = 0; k < n; k++) {
            if (is_bad[k]) break;
            if (pos[k].p1 + pos[k].p2 == S) {
                L = min(L, pos[k].p1);
                R = max(R, pos[k].p2);
            } else if (2 * pos[k].p1 == S) {
                L = min(L, pos[k].p1);
                R = max(R, pos[k].p1);
            } else { // 2 * pos[k].p2 == S
                L = min(L, pos[k].p2);
                R = max(R, pos[k].p2);
            }
            if (pref_bad[R + 1] - pref_bad[L] == 0) {
                ans = max(ans, k + 1);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}