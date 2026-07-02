#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct ST {
    vector<vector<ll>> f;
    ST(vector<ll>& nums) {
        int n = nums.size();
        int w = __lg(n) + 1;
        f.resize(n, vector(w, 0LL));
        for(int i = 0; i < n; i ++) {
            f[i][0] = nums[i];
        }
        for(int k = 1; k < w; k ++) {
            for(int i = 0; i < n; i++) {
                ll mid = i + (1 << (k - 1));
                if(mid >= n) break;
                f[i][k] = min(f[i][k - 1], f[mid][k - 1]);
            }
        }
    }

    int query_min(int left, int right) {
        int k = __lg((right - left + 1));
        return min(
            f[left][k],
            f[right - (1 << k) + 1][k]
        );
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> x[i];
    auto st = ST(x);
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        cout << st.query_min(a, b) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}