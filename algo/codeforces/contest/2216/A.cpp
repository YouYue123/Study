#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int constexpr INF = 0x3f3f3f3f;
struct Item {
    int idx;
    int val;
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> b(n);
    vector<Item> items;
    for(int i = 0; i < k; i ++) {
        cin >> a[i];
    }
    int b_sum = 0;
    int op_cnt = 0;
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        b_sum += b[i];
        // cout << "k + 1: " << k + 1 << " b[i]: " << b[i] << endl;
        op_cnt += k + 1 - b[i];
        items.emplace_back(i, b[i]);
    }
    int target = b.size() * (k + 1);
    if(b_sum > target || (target - b_sum) > 1000) {
        cout << -1 << endl;
        return;
    }

    sort(items.begin(), items.end(), [&] (auto& item1, auto& item2) {
        return item1.val > item2.val;
    });
    cout << op_cnt << endl;
    for(int i = 0; i < items.size(); i ++) {
        for(int j = 0; j < k + 1 - items[i].val; j ++) {
            cout << items[i].idx + 1 << " ";
        }
    }
    cout << endl;
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