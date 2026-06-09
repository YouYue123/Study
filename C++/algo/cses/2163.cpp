#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct BIT {
    vector<ll> tree;
    BIT(int N) {
        tree.resize(N + 1);
    }
    int lowbit (int x) {
        return x & -x;
    }
    void update (int idx, ll val) {
        while(idx < tree.size()) {
            tree[idx] += val;
            idx += lowbit(idx);
        }
    }

    ll query(int idx) {
        ll ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
};

void solve()
{
    ll n, k;
    cin >> n >> k;
    BIT bit(n);
    for(int i = 1; i <= n; i ++) {
        bit.update(i, 1);
    }
    int head = 1;
    while(n) {
        int target = (head + k) % n;
        if(target == 0) target = n;
        int left = 0, right = n + 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(bit.query(mid) >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << right << " ";
        bit.update(right, -1);
        head = target;
        n -= 1;
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}