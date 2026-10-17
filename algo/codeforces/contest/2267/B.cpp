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
    map<ll, ll, greater<>> dict;
    map<ll, ll> taken;
    for(int i = 0; i < n; i ++) {
        dict[a[i]] += 1;
        taken[a[i]] = 0;
    }
    vector<int> ans;
    while(true) {
        bool ok = false;
        for(auto& [num, cnt] : dict) {
            if(cnt > taken[num]) {
                 ok = true;
                 ans.push_back(num);
                 taken[num] += 1;
            }
         }
         if(!ok) break;
    }
    for(auto num : ans) cout << num << " ";
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