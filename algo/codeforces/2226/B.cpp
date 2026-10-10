#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    // Mg - mg = g
    // M - m = 1
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
        if(i >= 1) {
            int max_num = max(nums[i], nums[i - 1]);
            int min_num = min(nums[i], nums[i - 1]);
            int gap = max_num - min_num;
            // cout << max_num << " "  << min_num << endl;
            if(max_num % gap == 0 && min_num % gap == 0) {
                ans += 1;
            }
        }
    }
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