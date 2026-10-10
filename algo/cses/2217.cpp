#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector x(n, 0LL);
    unordered_map<ll, ll> pos;
    unordered_set<ll> dict;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> x[i];
        pos[x[i]] = i + 1;
        if(!dict.contains(x[i] - 1)) {
            ans += 1;
        }
        dict.insert(x[i]);
    }
    // cout << "initial ans: " << ans << endl;
    for(int i = 0; i < m; i ++) {
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        ll num_a = x[a - 1], num_b = x[b - 1];
        // cout << "swap: " << num_a << " " << num_b << endl;
        
        if(pos[num_a + 1] > a && pos[num_a + 1] < b) {
            // cout << "num_a + 1 is in between add one for num_a" << endl; 
            ans += 1;
        }
        if(pos[num_a - 1] > a && pos[num_a - 1] < b) {
            // cout << "num_a - 1 is in between minus one for num_a" << endl; 
            ans -= 1;
        }

        if(pos[num_b - 1] > a && pos[num_b - 1] < b) {
            // cout << "num_b - 1 is in between add one for num_b" << endl; 
            ans += 1;
        }
        if(pos[num_b + 1] > a && pos[num_b + 1] < b) {
            // cout << "num_b + 1 is in between minus one for num_b" << endl; 
            ans -= 1;
        }
        if(num_b - num_a == 1) {
            // cout << "exact bad swap add one" << endl;
            ans += 1;
        } else if(num_a - num_b == 1){
            // cout << "exact good swap minus one" << endl;
            ans -= 1;
        }
        pos[num_a] = b;
        pos[num_b] = a;
        swap(x[a - 1], x[b - 1]);
        cout << ans << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}