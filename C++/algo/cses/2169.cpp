#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct BIT {
    vector<int> tree;
    BIT(int N) {
        tree.resize(N + 1);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int idx, int val) {
        while(idx < tree.size()) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }
    int query(int idx) {
        int ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
 };
struct Item {
    ll x;
    ll y;
    int idx;
};
void solve() {
    int n;
    cin >> n;
    vector<Item> segs(n);
    vector<ll> nums;
    for(int i = 0; i < n; i ++) {
        ll x, y;
        cin >> x >> y;
        nums.push_back(x);
        nums.push_back(y);
        segs[i].x = x; 
        segs[i].y = y;
        segs[i].idx = i;
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for(auto& seg : segs) {
        int new_x_id = lower_bound(nums.begin(), nums.end(), seg.x) - nums.begin();
        int new_y_id = lower_bound(nums.begin(), nums.end(), seg.y) - nums.begin();
        seg.x = new_x_id + 1;
        seg.y = new_y_id + 1;
    }
    sort(segs.begin(), segs.end(), [&] (auto& a, auto& b) {
        if(a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });

    // for(auto& seg : segs) {
    //     cout << "idx: " << seg.idx << " x: " << seg.x << " " << " y: " << seg.y << endl;
    // }
    
    auto bit_1 = BIT(nums.size() + 2);
    vector<int> other_contains(n, 0), contains_other(n, 0);
    for(int i = 0; i < n; i ++) {
        auto& [ x, y, idx ] = segs[i];
        other_contains[idx] = bit_1.query(nums.size() + 2) - bit_1.query(y - 1);
        bit_1.update(y, 1);
    }
    auto bit_2 = BIT(nums.size() + 2);
    for(int i = n - 1; i >= 0; i --) {
        auto& [ x, y, idx ] = segs[i];
        contains_other[idx] = bit_2.query(y);
        bit_2.update(y, 1);
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