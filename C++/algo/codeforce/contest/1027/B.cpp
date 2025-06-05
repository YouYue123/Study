#include <iostream>
#include <string>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (char c : s)
    {
        if (c == '0')
            x += 1;
        else
            y += 1;
    }
    if (x < n / 2 - k || y < n / 2 - k)
    {
        cout << "NO" << endl;
        return;
    }
    x -= n / 2 - k;
    y -= n / 2 - k;
    if (x % 2 == 1 || y % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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