#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int one_cnt = 0, zero_cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] == 1) one_cnt += 1;
        else zero_cnt += 1;
    }
    int len = 0 ;
    int item = 0;
    if(one_cnt <= n / 2) {
        len = n - one_cnt ;
        item = 0;
    } else {
        // zero_cont < n / 2
        if(one_cnt % 2 == 1) {
            len = one_cnt - 1;
        } else {
            len = one_cnt;
        }
        item = 1;
    }

    cout << len << endl;
    for(int i = 0; i < len; i ++) {
        cout << item << " ";
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