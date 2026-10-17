#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for(int i = 0; i < n; i ++) {
        sum += a[i];
        pq.push(a[i]);
        while(sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}