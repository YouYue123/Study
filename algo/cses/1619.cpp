#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
// struct Customer {
//     ll arrival_time;
//     ll leaving_time;
// };
struct Event {
    ll time;
    bool is_arrival;
};
void solve()
{
    int n;
    cin >> n;
    // vector<Customer> customers(n);
    // for(int i = 0; i < n; i ++) {
    //     cin >> customers[i].arrival_time >> customers[i].leaving_time;
    // }
    // sort(customers.begin(), customers.end(), [&] (auto& a, auto& b) {
    //     return a.arrival_time < b.arrival_time;
    // });
    // priority_queue<ll, vector<ll>, greater<>> pq;
    // ll ans = 0;
    // for(auto c : customers) {
    //     // cout << c.arrival_time << " - " << c.leaving_time << endl;
    //     pq.push(c.leaving_time);
    //     while(!pq.empty() && pq.top() <= c.arrival_time) {
    //         pq.pop();
    //     }
    //     ans = max(ans, (ll)pq.size());
    // }
    // cout << ans << endl;
    vector<Event> events;
    for(int i = 0; i < n; i ++) {
        ll a, b;
        cin >> a >> b;
        events.emplace_back(a, true);
        events.emplace_back(b, false);
    }

    sort(events.begin(), events.end(), [&] (auto& a, auto& b) {
        return a.time < b.time;
    });
    ll ans = 0, cur = 0;
    for(auto& event : events) {
        cur += event.is_arrival ? 1 : -1;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}