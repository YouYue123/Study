#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int cnt3 = 0, cnt2 = 0, cnt1 = 0;
    // cout << s << endl;
    for(char c : s) {
        if(c == '.') {
            cnt += 1;
        } else {
            if(cnt == 1) cnt1 += 1;
            else if(cnt == 2) cnt2 += 1;
            else if(cnt >= 3) cnt3 += 1; 
            cnt = 0;
        }
    }
    if(cnt == 1) cnt1 += 1;
    else if(cnt == 2) cnt2 += 1;
    else if(cnt >= 3) cnt3 += 1; 

    // cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;  
    if(cnt3 == 0) {
        cout << cnt1 + cnt2 * 2 << endl;
    } else {
        cout << 2 << endl;
    }
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