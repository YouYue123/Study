#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int idx;
    int val;
};
void solve() {
    int n, x;
    cin >> n >> x;
    vector<Item> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].val;
        a[i].idx = i + 1;
    }
    sort(a.begin(), a.end(), [&] (auto& a, auto& b) {
        return a.val < b.val;
    });

    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            ll t = x - a[i].val - a[j].val;
            int left = j + 1, right = n - 1;
            while(left < right) {
                if(a[left].val + a[right].val > t) {
                    right -= 1;
                } else if(a[left].val + a[right].val < t) {
                    left += 1;
                } else {
                    // cout << a[i].val << " " << a[j].val << " "  << a[left].val << " " << a[right].val << endl;
                    cout << a[i].idx << " " << a[j].idx << " "  << a[left].idx << " " << a[right].idx << endl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}