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
void solve() {
    ll n, x;
    cin >> n >> x;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    unordered_map<ll, int, safe_hash> cnt;
    cnt[0] = 1;
    ll sum = 0, ans = 0;
    for(int i = 0; i < n; i ++) {
        sum += a[i];
        ll t = sum - x;
        if(cnt.contains(t)) ans += cnt[t];
        cnt[sum] += 1;
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}