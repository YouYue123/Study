#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// void solve()
// {
//     vector<>
// }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1000;
    vector<int> a;
    vector<int> b;
    // cin >> T;
    while (T--)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        a.push_back(tempA);
        b.push_back(tempB);
    }
    long long ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i ++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;
}