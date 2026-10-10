#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Task {
    ll duration;
    ll deadline;
};
void solve() {
    int n;
    cin >> n;
    vector<Task> tasks(n);
    for(int i = 0; i < n; i ++) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }
    sort(tasks.begin(), tasks.end(), [&] (auto& a, auto& b) {
        if(a.duration == b.duration) return a.deadline < b.deadline;
        return a.duration < b.duration;
    });
    ll cur_time = 0;
    ll ans = 0;
    for(auto& [duration, deadline] : tasks) {
        cur_time += duration;
        // cout << "cur reward" << deadline - cur_time << endl;
        ans += deadline - cur_time;
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}