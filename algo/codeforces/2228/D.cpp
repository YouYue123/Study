#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Point {
    int x;
    int y;
};
void solve()
{
    int n;
    cin >> n;
    vector<Point> pts(n);
    vector<ll> cy(n);
    for(int i = 0; i < n; i ++) {
        cin >> pts[i].x >> pts[i].y;
        cy[i] = pts[i].y;
    }

    sort(cy.begin(), cy.end());
    cy.erase(unique(cy.begin(), cy.end()), cy.end());

    sort(pts.begin(), pts.end(), [&] (auto& a, auto& b) {
        return a.x < b.x;
    });

    vector<int> g_min, g_max;

    for(int i = 0; i < n; ) {
        int j = i;
        int c_min = pts[i].y;
        int c_max = pts[i].y;
        while(j < n && pts[j].x == pts[i].x) {
            c_min = min(c_min, pts[j].y);
            c_max = max(c_max, pts[j].y);
            j += 1;
        }
        g_min.push_back(c_min);
        g_max.push_back(c_max);
        i = j;
    }

    int n_groups = g_min.size();
    if(n_groups < 2) {
        cout << 0 << endl;
        return;
    }

    vector pre_min(n_groups, 0), pre_max(n_groups, 0);
    vector suf_min(n_groups, 0), suf_max(n_groups, 0);

    pre_min[0] = g_min[0];
    pre_max[0] = g_max[0];
    for(int i = 1; i < n_groups; i ++) {
        pre_min[i] = min(pre_min[i - 1], g_min[i]);
        pre_max[i] = max(pre_max[i - 1], g_max[i]);
    }

    suf_min[n_groups - 1] = g_min[n_groups - 1];
    suf_max[n_groups - 1] = g_max[n_groups - 1];
    for(int i = n_groups - 2; i >= 0; i --) {
        suf_min[i] = min(suf_min[i + 1], g_min[i]);
        suf_max[i] = max(suf_max[i + 1], g_max[i]);
    }
    
    ll ans = 0;
    for(int i = 0; i < n_groups - 1; i ++) {
        int L = max(pre_min[i], suf_min[i + 1]);
        int R = min(pre_max[i], suf_max[i + 1]) - 1;
        if(L <= R) {
            auto it1 = lower_bound(cy.begin(), cy.end(), L);
            auto it2 = upper_bound(cy.begin(), cy.end(), R);
            if(it2 > it1) {
                ans += distance(it1, it2);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}