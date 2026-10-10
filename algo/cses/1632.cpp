#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll start;
    ll end;
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<Item> items(n);
    for(int i = 0; i < n; i ++) {
        cin >> items[i].start >> items[i].end;
    }
    sort(items.begin(), items.end(),[&] (auto& a, auto& b) {
        // if(a.end == b.end) return a.start < b.start;
        return a.end < b.end;
    });

    multiset<ll> cur_end;
    ll ans = 0;
    for(auto& item : items) {
        auto it = cur_end.upper_bound(item.start);
        if(it != cur_end.begin()) {
            it --;
            // cout << "erase: " <<  *it << endl;
            cur_end.erase(it);
            // cout << "find existing valid end for " << item.start << " - " << item.end << endl;
            cur_end.insert(item.end);
            ans += 1;
        } else if(cur_end.size() < k) {
            // cout << "push in: " << item.start << " - " << item.end << endl;
            cur_end.insert(item.end);
            ans += 1;
        }
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}