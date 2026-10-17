#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    map<ll, ll> dict;
    ll total = 0;
    ll max_ele = 0LL;
    for(int i = 0; i < n; i ++) {
        ll num, cnt;
        cin >> num >> cnt;
        dict[num] = cnt;
        total += cnt;
        max_ele = max(max_ele, num);
    }
    auto get = [&] (ll x) {
        auto it = dict.find(x);
        return it == dict.end() ? 0 : it->second;
    };
    auto is_valid = [&] (ll x) -> bool {
        ll p = 1, extra = 0, acc = 0;
        if(get(x) >= 1) return true;
        x -= 1;
        while(x > 0) {
            ll c = get(x);
            acc += c;
            if(c > p) extra += c - p;
            else p += p - c;
            if(p > total) return false;
            // cout << "x: " << x <<  " extra: " << extra << " p: " << p << endl;
            x -= 1;
        }
        extra += total - acc;
        // cout << "x: " << x <<  " extra: " << extra << " p: " << p << endl;
        return extra >= p;
    };
    // is_valid(5);
    ll left = max_ele, right = max_ele + 64;
    while(left + 1 < right) {
        ll mid = left + (right - left) / 2;
        // cout << mid << endl;
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