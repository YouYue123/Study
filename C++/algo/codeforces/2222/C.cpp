#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int constexpr INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<ll> nums(n);
    vector<ll> sorted_num(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        sorted_num[i] = nums[i];
    }
    sort(sorted_num.begin(), sorted_num.end());
    ll median = sorted_num[n / 2];
    vector<ll> memo(n, -1);
    auto dfs = [&] (this auto&& dfs, int i) -> ll {
        if(i == n) return 0;
        if(memo[i] != -1) return memo[i];
        int bias_cnt = 0;
        int equal_cnt = 0;
        ll ans = -INF;
        for(int j = i; j < n; j ++) {
            if(nums[j] > median) {
                bias_cnt += 1;
            } else if(nums[j] < median) {
                bias_cnt -= 1;
            } else {
                equal_cnt += 1;
            }
            bool is_odd_len = ((j - i + 1) % 2 != 0);
            if(is_odd_len && equal_cnt > abs(bias_cnt)) {
                ans = max(
                    ans,
                    1 + dfs(j + 1)
                );
            }
        }
        return memo[i] = ans;
    };
    cout << dfs(0) << endl;
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