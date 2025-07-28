#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    int mxa = 0, mxb = 0, mna = 0, mnb = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[mxa])
            mxa = i;
        if (a[i] < a[mna])
            mna = i;
        if (b[i] > b[mxb])
            mxb = i;
        if (b[i] < b[mnb])
            mnb = i;
    }
    int ans = INT_MAX;
    auto get_cost = [&](int idx) -> int
    {
        int t = (idx == 0 ? 1 : 0);
        int mxa = t, mxb = t, mna = t, mnb = t;
        for (int i = 0; i < n; i++)
        {
            if (i == idx)
                continue;
            if (a[i] > a[mxa])
                mxa = i;
            if (a[i] < a[mna])
                mna = i;
            if (b[i] > b[mxb])
                mxb = i;
            if (b[i] < b[mna])
                mnb = i;
        }
        int dx = a[mxa] - a[mna] + 1;
        int dy = b[mxb] - b[mnb] + 1;
        if (dx * dy == n - 1)
            return min(dx, dy) * (max(dx, dy) + 1);
        else
            return dx * dy;
    };
    ans = min(ans, get_cost(mxa));
    ans = min(ans, get_cost(mxb));
    ans = min(ans, get_cost(mna));
    ans = min(ans, get_cost(mnb));
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
