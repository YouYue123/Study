#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // MurmurHash3 mixed-in，guarantee even distribution
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // Add Salt with system timestamp
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// struct BIT {
//     vector<ll> tree;
//     BIT (ll N) {
//         tree.resize(N, 0LL);
//     }
//     void update(int idx, vector<ll>& a) {
//         while(idx < tree.size()) {
//             tree[idx] = a[idx];
//             for(int i = 1; i < (idx & -idx); i *= 2) {
//                 tree[idx] = max(tree[idx], tree[idx - i]);
//             }
//             idx += idx & -idx;
//         }
//     }

//     int query (int idx) {
//         ll ans = 0;
//         while(idx > 0) {
//             ans = max(ans, tree[idx]);
//             idx -= idx & -idx;
//         }
//         return ans;
//     }
// };

struct Item {
    ll start;
    ll end;
    bool operator< (const Item& other) const {
        return get_len() < other.get_len();
    }
    bool is_broken(int x) {
        return start <= x && end >= x;
    }
    ll get_len() const {
        return end - start;
    }
};
// struct LazyHeap {
//     priority_queue
// };
void solve()
{
    ll x, n;
    cin >> x >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    set<ll> lights;
    multiset<ll> gaps;
    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);
    for(int i = 0; i < n; i ++) {
        ll cur = a[i];
        // cout << "for: " << cur << endl;
        auto it = lights.upper_bound(cur);
        ll L = *prev(it);
        ll R = *it;
        // cout << "remove: " << R - L << endl;
        gaps.erase(gaps.find(R - L));
        // cout << "add: " << cur - L << endl;
        gaps.insert(cur - L);
        // cout << "add: " << R - cur << endl;
        gaps.insert(R - cur);
        cout << *gaps.rbegin() << " ";
        lights.insert(cur);
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}