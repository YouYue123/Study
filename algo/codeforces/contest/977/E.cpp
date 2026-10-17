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

struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }
    void unite (int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    }

    int find_root(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }

    int get_size(int x) {
        return size[find_root(x)];
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> g;
    auto uf = UF(n + 1);
    vector edge_cnt(n + 1, 0LL);
    vector self_connect(n + 1, false);
    for(int i = 0; i < m; i ++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.unite(u, v);
        edge_cnt[u] += 1;
        edge_cnt[v] += 1;
        // if(u == v) cout << "!!!! self connect" << endl;
    }
    ll ans = 0;
 
    vector visit(n + 1, false);
    for(ll i = 1; i <= n; i ++) {
        ll root = uf.find_root(i);
        if(visit[root]) continue;
        auto dfs = [&] (this auto&& dfs, ll cur) -> bool {
            if(edge_cnt[cur] != 2) return false;
            for(ll nxt : g[cur]) {
                if(visit[nxt]) continue;
                visit[nxt] = true;
                if(!dfs(nxt)) return false;
            }
            return true;
        };
        visit[i] = true;
        if(dfs(i)) ans += 1;
        visit[root] = true;
        
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}