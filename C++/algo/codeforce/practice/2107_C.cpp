#include <bits/stdc++.h>
using namespace std;
void solve()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<long long> a(n, 0);
    vector<long long> pre(n, 0);
    int maxF = 0;
    int f = 0;
    bool has0 = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i] = f;
        if (s[i] == '0')
        {
            a[i] = -1e18;
            f = 0;
            has0 = true;
        }
        else
        {
            f = max(f + a[i], 0LL);
            maxF = max(maxF, f);
        }
    }
    if (maxF > k || (maxF < k && !has0))
    {
        cout << "NO" << endl;
        return;
    }
    int suf = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            a[i] = k - pre[i] - suf;
            break;
        }
        suf = max(suf + a[i], 0LL);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        int ans = a[i];
        if(a[i] == -1e18) ans = 0;
        cout << ans << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}