// Problem: Registration System
// Contest: 4 | Index: C
// URL: https://codeforces.com/contest/4/problem/C
// Rating: 1300 | Tags: data structures, hashing, implementation
// Memory: 256 MB | Time: 0.5 s
// Author: Yue You

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    unordered_map<string, int> dict;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        dict[s] += 1;
        if(dict[s] == 1) cout << "OK" << endl;
        else cout << s << dict[s] - 1 << endl;
    }
}
