#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll MOD = 676767677;
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    unordered_map<int, int> cnt;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
        if(nums[i] > 1) ans += nums[i];
        if(nums[i] == 1 && i == n -1) ans += nums[i];
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