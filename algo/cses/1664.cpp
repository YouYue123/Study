#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Movie {
    ll start;
    ll end;
};
struct Query {
    ll arrive;
    ll leave;
};

int constexpr LOG = 20;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<Movie> movies(n);
    vector<ll> all_time;
    for(int i = 0; i < n; i ++)  {
        cin >> movies[i].start >> movies[i].end;
        all_time.push_back(movies[i].start);
        all_time.push_back(movies[i].end);
    }
    vector<Query> queries(q);
    for(int i = 0; i < q; i ++) {
        cin >> queries[i].arrive >> queries[i].leave;
        all_time.push_back(queries[i].arrive);
    }
    sort(all_time.begin(), all_time.end());
    all_time.erase(unique(all_time.begin(), all_time.end()), all_time.end());
    int m = all_time.size();
    auto get_idx = [&] (int t) {
        return lower_bound(all_time.begin(), all_time.end(), t) - all_time.begin();
    };

    // candidate[i] = min end for items starting from all_time[i]
    vector<ll> cand(m, INF);
    for(auto& mv : movies) {
        int i = get_idx(mv.start);
        cand[i] = min(cand[i], mv.end);
    }

    // sufmin[i] = min(cand[i..M-1])
    vector<ll> suf_min(m + 1, INF);
    for(int i = m - 1; i >= 0; i --) {
        suf_min[i] = min(cand[i], suf_min[i + 1]);
    }

    // Sparse-table
    vector jump(LOG, vector<int>(m + 1));
    for(int i = 0; i < m; i ++) {
        jump[0][i] = suf_min[i] == INF ? m : get_idx(suf_min[i]);
    }
    jump[0][m] = m;
    for(int k = 1; k < LOG; k ++) {
        for(int i = 0; i <= m; i ++) {
            int nxt = jump[k - 1][i];
            jump[k][i] = jump[k - 1][nxt];
        }
    }

    for(auto& q : queries) {
        int cur = get_idx(q.arrive);
        ll ans = 0;
        for(int k = LOG - 1; k >=0 ; k --) {
            int nxt = jump[k][cur];
            if(nxt != m && all_time[nxt] <= q.leave) {
                cur = nxt;
                ans += (1LL << k);
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}