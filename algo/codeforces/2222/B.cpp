#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> nums;
    vector<ll> a(n);
    vector<ll> x(m);
    priority_queue<ll> odd, even;

    for(int idx = 0; idx < n; idx ++) {
        cin >> a[idx];
        if((idx + 1) % 2 == 0) {
            even.push(a[idx]);
        } else {
            odd.push(a[idx]);
        }
    }
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    // cout << "sum: " << ans << endl;
    bool is_even = false, is_odd = false;
    for(int i = 0; i < m; i ++) {
        cin >> x[i];
        if(x[i] % 2 == 0) {
            if(even.empty()) continue;
            if(even.top() > 0 || !is_even) {
                // cout << "remove from even: " << even.top() << endl;
                ans -= even.top();
                even.pop();
                is_even = true;
            }
        } else {
            if(odd.empty()) continue;
            if(odd.top() > 0 || !is_odd)  {
                // cout << "remove from odd: " << odd.top() << endl;
                ans -= odd.top();
                odd.pop();
                is_odd = true;
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