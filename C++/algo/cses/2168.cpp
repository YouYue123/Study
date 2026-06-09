#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll x;
    ll y;
    ll idx;
};
void solve() {
    int n;
    cin >> n;
    vector<Item> ranges; 
    for(ll i = 0; i < n; i ++) {
        ll x, y;
        cin >> x >> y;
        ranges.emplace_back(x, y, i);
    }
    sort(ranges.begin(), ranges.end(), [&] (auto& a, auto&b) {
        if(a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });
    ll max_R = 0LL, min_R = INF;
    vector<int> contains_other(n, 0), other_contains(n, 0);
    for(int i = 0; i < n; i ++) {
        ll L = ranges[i].x, R = ranges[i].y, idx = ranges[i].idx;
        if(max_R >= R) other_contains[idx] = 1;
        max_R = max(max_R, R);
    }
    for(int i = n - 1; i >= 0; i --) {
        ll L = ranges[i].x, R = ranges[i].y, idx = ranges[i].idx;
        if(min_R <= R) contains_other[idx] = 1;
        min_R = min(min_R, R);
    }
    for(int num : contains_other) {
        cout << num << " ";
    }
    cout << endl;
    for(int num : other_contains) {
        cout << num << " ";
    }
    cout << endl;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}