#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> nums;
    for(int i = 0; i < n; i ++) {
        int num = 0;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    ull ans = 0;
    for(int i = 0; i < n; i ++) {
        int t1 = l - nums[i], t2 = r - nums[i];
        // <= t1
        ull left = lower_bound(nums.begin() + i + 1, nums.end(), t1) - nums.begin();
        // > t2
        ull right = upper_bound(nums.begin() + i + 1, nums.end(), t2) - nums.begin();
        ans += right - left;
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