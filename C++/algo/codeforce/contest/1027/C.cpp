#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <unordered_map>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    n = unique(a.begin(), a.end()) - a.begin();

    int prev = -1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == prev + 1)
            continue;
        prev = a[i];
        ans += 1;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}