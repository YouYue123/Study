#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int constexpr INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool impossible = false;
    unordered_set<int> dict ;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(dict.contains(a[i])) impossible = true;
        dict.insert(a[i]);
    }
    if(impossible) {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end(), greater<>());
    for(int num : a) {
        cout << num << " ";
    }
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