#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    // a = p1^b1 * p2^b2 * px^bx
    // 2 3 6 4
    // 2 3 2*3 2*2 
    // j = 0, i = 0 -> 4
    // j = 1, i = 2 -> 36
    // i = 4, j = 3 -> 144
    // i = 4, j = 4 -> 576
    // 2 * 3 * 5 * 7 * 9 * 11 * 13 = ~2 * 1e5
    auto get_odd_prime_factors = [&] (ll num) {
        // cout << "a[i]: " << a[i] << endl;
        vector<ll> dict;
        for(ll p = 2; p * p <= num; p ++) {
            ll cnt = 0;
            while(num % p == 0) {
                // cout << "find!" << endl;
                num /= p;
                cnt += 1;
            }
            if(cnt % 2 == 1) dict.push_back(p);
        }
        // cout << dict.size() << endl;
        if(num > 1) dict.push_back(num);
        return dict;
    };
    vector<vector<ll>> dicts;
    unordered_map<ll, ll> freq;
    for(int i = 0; i < n; i ++) {
        // cout << "i: " << i << endl;
        auto odd_factors = get_odd_prime_factors(a[i]);
        dicts.push_back(odd_factors);
        ll key = 1;
        for(auto& f : odd_factors) {
            // cout << f << endl;
            key *= f;
        }
        freq[key] += 1;
    }
    unordered_set<ll> cur_dict;
    ll ans = 0;
    for(int j = 0; j < n; j ++) {
        auto factors = dicts[j];
        for(auto& f : factors) {
            if(cur_dict.contains(f)) {
                cur_dict.erase(f);
            } else {
                cur_dict.insert(f);
            }
        }
        if(cur_dict.size() > 7) continue;
        ll key = 1;
        bool ok = true;
        for(auto& f: cur_dict) {
            key *= f;
            if(key >= 1e7) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        ans += freq[key];
        // for(int i = 0; i < n; i ++) {
        //     // cout << "i: " << i << endl;
        //     auto another_factors = dicts[i];
        //     bool ok = true;
        //     auto dup_dict = cur_dict;
        //     for(auto& [f, cnt] : another_factors) dup_dict[f] ^= cnt;
        //     for(auto& [f, cnt] : dup_dict) {
        //         // cout << "f: " << f<< " cnt: " << cnt << endl;
        //         if(cnt == 1) {
        //             ok = false;
        //             break;
        //         }
        //     }
        //     if(ok) {
        //         // cout << "add! " << endl;
        //         ans += 1;
        //     }
        // }
    }
    cout << ans << endl;
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