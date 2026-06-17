#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;

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
    int n, m;
    cin >> n >> m;

    vector memo(m, vector(n + 1, unordered_map<ll, ll, safe_hash>()));
    auto dfs = [&] (auto& dfs, int i, int j, ll mask) -> ll {
        if(i == m) return mask == 0 ? 1LL : 0LL;
        if(memo[i][j].contains(mask)) return memo[i][j][mask];
        ll ans = 0;
        if(j == n) {
            ans += dfs(dfs, i + 1, 0, mask);
        } else {
            bool occupied = mask & (1 << j);
            if(occupied) {
                ans = (ans + dfs(dfs, i, j + 1, mask ^ (1 << j))) % MOD;
            } else {
                ans = (ans + dfs(dfs, i, j + 1, mask | (1 << j))) % MOD;
                if(j + 1 < n) {
                    bool is_nxt_occupied = mask & (1 << (j + 1));
                    if(!is_nxt_occupied) {
                        ans = (ans + dfs(dfs, i, j + 2, mask)) % MOD;
                    }
                }
            }
        }
        return memo[i][j][mask] = ans;
    };

    cout << dfs(dfs, 0, 0, 0) << endl;

    // for(int h = 1; h <= n; h ++) {
    //     for(int w = 1; w <= m; w ++) {
    //         cout << "for h: " << h << " w: " << w << endl;
    //         cout << memo[h][w] << endl;
    //     }
    // }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}