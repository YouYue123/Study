#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
double constexpr PI = 3.14159265358979323846264338327950288;
struct Cake {
    ll r;
    ll h;
    ll get_base() {
        return r * r * h;
    }
    double get_volume () {
        return PI * get_base();
    }
};
struct BIT {
    vector<ll> tree;
    BIT(int N) {
        tree.resize(N + 1);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void update (int idx, ll val) {
        while(idx < tree.size()) {
            tree[idx] = max(tree[idx], val);
            idx += lowbit(idx);
        }
    }
    ll query(int idx) {
        ll ans = 0;
        while(idx > 0) {
            ans = max(ans, tree[idx]);
            idx -= lowbit(idx);
        }
        return ans;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<Cake> cakes(n);
    vector<ll> bases;
    for(int i = 0; i < n; i ++) {
        cin >> cakes[i].r >> cakes[i].h;
        bases.push_back(cakes[i].get_base());
    }

    sort(bases.begin(), bases.end());
    bases.erase(unique(bases.begin(), bases.end()), bases.end());

    auto get_rank = [&] (Cake& cake) {
        return lower_bound(bases.begin(), bases.end(), cake.get_base()) - bases.begin() + 1;
    };
    auto bit = BIT(bases.size() + 2);
    ll max_base = 0;
    for(int i = 0; i < n; i ++) {
        auto cake = cakes[i];
        ll cur_base = cake.get_base();
        int rank = get_rank(cake);

        ll cur_dp = cur_base + bit.query(rank - 1);
        bit.update(rank, cur_dp);
        max_base = max(max_base, cur_dp);
    }
    cout << fixed << setprecision(9) << max_base * PI << endl;
    // double ans = 0.0;
    // for(int i = 0; i < n; i ++) {

    // }
    // vector memo(n, unordered_map<double, double>());
    // auto dfs = [&] (this auto&& dfs, int i, double cur_max) -> double {
    //     if(i == n) return 0.00;
    //     if(memo[i].contains(cur_max)) return memo[i][cur_max];
    //     // cout << "cake volume idx: " << i << " " << cakes[i].get_volume() << endl;
    //     double ans = dfs(i + 1, cur_max);
    //     if(cur_max < cakes[i].get_volume()) {
    //         ans = max(
    //             ans, 
    //             cakes[i].get_volume() + dfs(i + 1, cakes[i].get_volume())
    //         );
    //     }
    //     return memo[i][cur_max] = ans;
    // };

    // cout << fixed << setprecision(9) << dfs(0, 0.0) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}