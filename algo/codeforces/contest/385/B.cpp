#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int pre = -1;
    const string target = "bear";
    ll ans = 0;
    if (s.size() < target.size())
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.size() - 3; i++)
    {
        string subS = s.substr(i, 4);
        if (subS == target)
        {
            ans += (i - pre) * (s.size() - i - 3);
            pre = i;
        }
    }

    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}