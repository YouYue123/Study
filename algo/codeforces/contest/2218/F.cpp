#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    // x for even, y for odd
    int x, y;
    cin >> x >> y;
    // size(u) = 1 + sum of size(child)
    int sum = x + y;
    bool is_total_even = sum % 2 == 0;
    int new_x = x, new_y = y;
    if(is_total_even) {
        if(x == 0) {
            cout << "NO" << endl;
            return;
        } else {
            new_x -= 1;
        }
    } else {
        if(y == 0) {
            cout << "NO" << endl;
            return;
        } else {
            new_y -= 1;
        }
    }
    // cout << "new_x"
    // for every even node there will be at least 1 odd node as its son
    if(new_x > new_y) {
        cout << "NO" << endl;
        return;
    }
    vector<int> odd_idxes;
    vector<int> even_idxes;
    int idx = 2;
    for(int i = 0; i < new_x; i ++) {
        even_idxes.push_back(idx);
        idx += 1;
    }
    for(int i = 0; i < new_y; i ++) {
        odd_idxes.push_back(idx);
        idx += 1;
    }
    vector<pair<int, int>> ans;
    int p1 = 0, p2 = 0;
    while(p1 < new_x) {
        ans.emplace_back(1, even_idxes[p2]);
        ans.emplace_back(even_idxes[p2], odd_idxes[p1]);
        p1 += 1;
        p2 += 1;
    }
    while(p2 < new_y) {
        ans.emplace_back(1, odd_idxes[p2]);
        p2 += 1;
    }
    cout << "YES" << endl;
    for(auto& pair : ans) {
        cout << pair.first << " " << pair.second << endl;
    }
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