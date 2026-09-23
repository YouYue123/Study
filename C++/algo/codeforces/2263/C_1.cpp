#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector diff(n + 1, 0LL);
    for(int i = 0; i < n; i ++) {
        int k = i + 1;
        int low = a[i] * k;
        int high = (a[i] + 1) * k - 1;
        if(low > n - 1) continue;
        high = min(high, n - 1);
        diff[low] += 1;
        diff[high + 1] -= 1;
    }
    int cur = 0;
    vector<int> ans;
    for(int i = 0; i < n; i ++) {
        cur += diff[i];
        if(cur == 0) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int item : ans) cout << item << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}