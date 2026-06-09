#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, t;
    cin >> n >> t;
    vector times(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> times[i];
    sort(times.begin(), times.end());
    ll min_time = *min_element(times.begin(), times.end());
    ll left = 0, right = t * min_time + 1;
    auto is_valid = [&] (ll x) {
        ll cnt = 0;
        for(auto time : times) {
            cnt += x / time;
            if(cnt >= t) return true;
        }
        return false;
    };
    while(left + 1 < right) {
        ll mid = left + (right - left) / 2;
        if(is_valid(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}