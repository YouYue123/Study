#include <bits/stdc++.h>

using namespace std;
const long long INVALID_A_VALUE = -1e18;

void solve()
{
    int n;
    long long k;
    string s;
    cin >> n >> k >> s;

    vector<long long> a(n);
    vector<long long> pre(n);
    long long maxF = 0;
    long long f = 0;
    bool has0 = false;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        pre[i] = f;
        if (s[i] == '0')
        {
            a[i] = INVALID_A_VALUE;
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
        std::cout << "No" << endl;
        return;
    }

    long long suf = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            a[i] = k - pre[i] - suf;
            break; 
        }
        else
        {
            suf = max(suf + a[i], 0LL);
        }
    }

    std::cout << "Yes" << endl;
    for (int i = 0; i < n; ++i)
    {
        long long ans_val = a[i];
        std::cout << ans_val << (i == n - 1 ? "" : " ");
    }
    std::cout << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}