#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Seg {
    ll l;
    ll r;
    int idx;
};
void solve() {
    int n;
    cin >> n;
    vector<Seg> segs(n);
    for(int i = 0; i < n; i ++) {
        cin >> segs[i].l >> segs[i].r;
        segs[i].idx = i;
    }
    sort(segs.begin(), segs.end(), [&] (auto& a, auto& b) {
        if(a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });
    ll max_r = 0, max_r_idx = -1;
    for(int i = 0; i < n; i ++) {
        auto& [l, r, idx] = segs[i];
        if(max_r >= r) {
            cout << idx + 1 << " " << max_r_idx + 1 << endl;
            return;
        } else {
            max_r = r;
            max_r_idx = idx;
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}