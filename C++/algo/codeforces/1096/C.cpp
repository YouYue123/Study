#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> div_6;
    vector<int> div_3;
    vector<int> div_2;
    vector<int> rest;
    for(int i = 0; i < n; i ++) {
        int cur;
        cin >> cur;
        if(cur % 6 == 0) {
            div_6.push_back(cur);
        } else if(cur % 3 == 0) {
            div_3.push_back(cur);
        } else if(cur % 2 == 0) {
            div_2.push_back(cur);
        } else {
            rest.push_back(cur);
        }
    }
    vector<int> ans;
    int p = 0;
    for(int num : div_2) ans.push_back(num);
    for(int num : rest) ans.push_back(num);
    for(int num : div_3) ans.push_back(num);
    for(int num : div_6) ans.push_back(num);
    for(int i = 0; i < n; i ++) {
        cout << ans[i] << (i != n - 1 ? " " : "");
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