#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(2 * n, 0);
    int x = -1, y = -1;
    int ans = 1;
    for(int i = 0; i < 2 * n; i ++) {
        cin >> nums[i];
        if(nums[i] == 0) {
            if(x == -1) {
                x = i;
            } else if(y == -1) {
                y = i;
            }
        }
    }
    // cout << endl;
    // cout << "x: " << x << " y: " << y << endl;
    auto expand = [&] (int left, int right) {
        // cout << "left: " << left << " right: " << right << endl;
        // cout << nums[left] << " " << nums[right] << endl;
        set<int> dict;
        for(int i = 0; i <= n; i ++) dict.insert(i);
        while(left >= 0 && right < 2 * n && nums[left] == nums[right]) {
            if(dict.contains(nums[left])) {
                // cout << "erase: " << nums[left] << endl;
                dict.erase(nums[left]);
            }
            left -= 1;
            right += 1;
        }
        // cout << left << " " << right << endl;
        // cout << "result: " << *dict.begin() << endl;
        return *dict.begin();
    };
    ans = max({
        ans,
        expand(x, x),
        expand(y, y),
        expand((x + y) / 2, (x + y) / 2),
        expand((x + y) / 2, (x + y) / 2 + 1)
    });
    cout << ans << endl;
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