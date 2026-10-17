#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    string ans = "NO";
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
        if(nums[i] == 100) {
            ans = "YES";
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