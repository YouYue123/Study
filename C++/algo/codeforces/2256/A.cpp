#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    cout << min(nums[2], nums[0] + nums[1]) - nums[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}