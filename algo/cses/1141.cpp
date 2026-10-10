#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
// 自定义高性能安全哈希结构体
struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // MurmurHash3 的关键混合步骤，保证位分布极其均匀
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // 引入基于当前系统时间的随机“盐”
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector k(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> k[i];
    
    ll left = 0, right = 0;
    unordered_map<ll, ll, safe_hash> cnt;
    // cnt.reserve(1e9);
    ll ans = 0;
    while(right < n) {
        cnt[k[right]] += 1;
        while(cnt[k[right]] > 1) {
            cnt[k[left]] -= 1;
            left += 1;
        }
        ans = max(ans, right - left + 1LL);
        right += 1;
    }
    cout << ans << endl;

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}