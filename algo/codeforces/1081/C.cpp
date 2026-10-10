#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = numeric_limits<ll>::max();
ll constexpr NEG_INF = numeric_limits<ll>::min();

void solve() {
    ll n, h, k;
    cin >> n >> h >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre_sum(n + 1, 0);
    vector<ll> pre_min(n + 1, INF);
    vector<ll> suf_max(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pre_sum[i + 1] = pre_sum[i] + a[i];
        pre_min[i + 1] = min(pre_min[i], a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf_max[i] = max(suf_max[i + 1], a[i]);
    }

    ll total_cycle_sum = pre_sum[n];    
    ll full_cycles = h / total_cycle_sum;
    ll full_steps = full_cycles * (n + k);
    ll remaining_h = h % total_cycle_sum;
    if (remaining_h == 0) {
        cout << full_steps - k << endl;
        return;
    }

    auto isValid = [&] (int x) {
        ll max_dmg = max(
            pre_sum[x] + (suf_max[x] - pre_min[x]),
            pre_sum[x]
        );
        return max_dmg >= remaining_h;
    };

    ll left = 0, right = n;
    while (left + 1 < right) {
        ll mid = left + (right - left) / 2;
        if (isValid(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    int extra_steps = left + 1;
    cout << full_steps + extra_steps << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    if (!(cin >> test_cases)) return 0;
    
    while (test_cases--) {
        solve();
    }
    
    return 0;
}