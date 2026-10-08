#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Lab {
    ll a, b, c;
    ll sum () {
        return a + b + c;
    }
};
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<Lab> labs(n);
    ll left = INF, right = k + 1e9 * 3;

    for(int i = 0; i < n; i ++) {
        cin >> labs[i].a >> labs[i].b >> labs[i].c;
        left = min(left, labs[i].sum());
        if(labs[i].a == labs[i].b && labs[i].b == labs[i].c) right = min(right, labs[i].sum() + 1);
    }
    // a < c b -= 1
    // a < b c -= 1
    // b < c a -= 1
    // 1 10
    // -3 0 1
    // use 2, k = 8 -> -3 0 -1
    // 
    auto is_valid = [&] (ll x) {
        ll cur = k;
        // cout << "cur: " << cur << endl;
        for(auto& lab : labs) {
            // cout << "lab: " << lab.a << " " << lab.b << " " << lab.c << endl;
            if(lab.sum() >= x) continue;
            if(lab.a == lab.b && lab.b == lab.c) {
                return false;
            } else if(lab.a <= lab.b && lab.b <= lab.c && lab.a <= lab.c) {
                ll min_gap = min({lab.b - lab.a, lab.c - lab.b, lab.c - lab.a});
                // cout << "min_gap: " << min_gap << endl;
                ll final = lab.sum() - min_gap - 1;
                // cout << "final: " << final << endl;
                cur -= min_gap + 1;
                cur -= x - final;
            } else {
                cur -= x - lab.sum();
            }
            if(cur < 0) return false;
        }
        return cur >= 0;
    };
    // cout << is_valid(4) << endl;
    // cout << "left: " << left << " right: " << right << endl;
    while(left + 1 < right) {
        ll mid = left + (right - left) / 2;
        // cout << "mid: " << mid << endl;
        if(is_valid(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
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