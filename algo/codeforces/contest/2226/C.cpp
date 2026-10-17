#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
    }
    multiset<int> ms(nums.begin(), nums.end());
    auto is_valid = [&] (int x) -> bool {
        if(x == 0) return true;
        auto cur_set = ms;
        for(int k = x - 1; k >= 0; k --) {
            auto it = cur_set.find(k);
            if(it != cur_set.end()) {
                cur_set.erase(it);
            } else {
                int target = 2 * k + 1;
                auto it = cur_set.lower_bound(target);
                if(it == cur_set.end()) {
                    return false;
                }
                cur_set.erase(it);
            }
        }
        return true;
    };
    int left = -1, right = n + 1;
    while(left + 1 < right) {
        int mid = left + (right - left) / 2;
        if(is_valid(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
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