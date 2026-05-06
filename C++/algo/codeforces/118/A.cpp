// Problem: String Task
// Contest: 118 | Index: A
// URL: https://codeforces.com/contest/118/problem/A
// Rating: N/A | Tags: N/A
// Memory: N/A | Time: N/A
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
    string s;
    cin >> s;
    unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'y' };
    string ans = "";
    for(char c : s) {
        if(!vowels.contains(tolower(c))) {
            ans += '.';
            ans += tolower(c); 
        }
    }
    cout << ans << endl;
}
