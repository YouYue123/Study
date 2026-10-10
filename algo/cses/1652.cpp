#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

// All coordinate there is assuming as 0-based
struct Presum2D {
    vector<vector<ll>> presum;
    Presum2D(vector<string>& g) {
        int n = g.size();
        presum.assign(n + 1, vector(n + 1, 0LL));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                presum[i + 1][j + 1] = presum[i][j + 1] + presum[i + 1][j] - presum[i][j] + (g[i][j] == '*');
            }
        }
    }
    // assume (x_1, y_1) is top_left, (x_2, y_2) is bottom_right
    ll query (int x_1, int y_1, int x_2, int y_2) {
        return presum[x_2 + 1][y_2 + 1] - presum[x_1][y_2 + 1] - presum[x_2 + 1][y_1] + presum[x_1][y_1];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];

    auto presum = Presum2D(g);

    for(int i = 0; i < q; i ++) {
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        x_1 -= 1;
        y_1 -= 1;
        x_2 -= 1;
        y_2 -= 1;
        cout << presum.query(x_1, y_1, x_2, y_2) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}