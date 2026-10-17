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
    int n = s.size();

    auto get_lps = [&] () {
        vector<int> lps(n, 0);
        for(int i = 1, match = 0; i < n; i ++) {
            while(match > 0 && s[i] != s[match]) match = lps[match - 1];
            if(s[match] == s[i]) match += 1;
            lps[i] = match;
        }
        return lps;
    };

    auto lps = get_lps();
    int candidate = lps.back();
    // bool ok = false;
    int max_lps_middle = 0;
    for(int i = 1; i < n - 1; i++) max_lps_middle = max(max_lps_middle, lps[i]);
    while(candidate > max_lps_middle) {
        candidate = lps[candidate - 1];
    }
    // while(candidate > 0) {
    //     for(int i = 1; i < n - 1; i ++) {
    //         if(lps[i] == candidate) {
    //             ok = true;
    //             break;
    //         }
    //     }
    //     if(!ok) candidate = lps[candidate - 1];
    //     else break;
    // }
    // cout << endl;
    if(candidate) cout << s.substr(0, candidate) << endl;
    else cout << "Just a legend" << endl;
}