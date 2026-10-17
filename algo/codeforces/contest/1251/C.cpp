#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{   
    string s;
    cin >> s;
    int n = s.size();
    vector<char> odd;
    vector<char> even;
    for(char c : s) {
        int num = c - '0';
        if(num % 2 == 1) odd.push_back(c);
        else even.push_back(c);
    }
    string ans = "";
    int p1 = 0, p2 = 0;
    while(p1 < odd.size() && p2 < even.size()) {
        if(odd[p1] < even[p2]) {
            ans += odd[p1];
            p1 += 1;
        } else {
            ans += even[p2];
            p2 += 1;
        }
    }
    while(p1 < odd.size()) {
        ans += odd[p1];
        p1 += 1;
    }
    while(p2 < even.size()) {
        ans += even[p2];
        p2 += 1;
    }
    cout << ans << endl;
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