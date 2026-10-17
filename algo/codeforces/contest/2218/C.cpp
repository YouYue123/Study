#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n * 3, 0);
    for(int i = 0; i < n; i ++) {
        ans[i * 3] = i + 1;
    }
    int j = 0;
    for(int i = n; i < n * 3; i ++) {
        if(j % 3 == 0) j += 1;
        ans[j] = i + 1;
        j += 1;
    }
    for(int i = 0; i < n * 3; i ++) cout << ans[i] << " ";
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