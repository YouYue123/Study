#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;

    auto ask = [&] (int x, int y) {
        cout << "? " << x + 1 << " " << y + 1 << endl;
        int z;
        cin >> z;
        return z;
    };

    vector<int> ans(n);
    int mx = 0;
    for(int i = 1; i < n; i ++) {
        int a = ask(mx, i);
        int b = ask(i, mx);
        if(a > b) {
            ans[mx] = a;
            mx = i;
        } else {
            ans[i] = b;
        }
    }
    ans[mx] = n;
    cout << "! ";
    for(int i = 0; i < n; i ++) cout << ans[i] << " ";
    cout << endl;
}