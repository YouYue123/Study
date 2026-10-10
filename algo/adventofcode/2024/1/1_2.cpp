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
    unordered_map<int, int> b;
    while (T--)
    {
        int tempA, tempB;
        cin >> tempA >> tempB;
        a.push_back(tempA);
        b[tempB] += 1;
    }
    long long ans = 0;
    for(int i = 0; i < a.size(); i ++) {
        ans += a[i] * b[a[i]];
    }
    cout << ans << endl;
}