// https://oi-wiki.org/basic/binary-lifting/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

ll constexpr MAX_N = 200001;
ll constexpr LOG = 30;
void build () {
    int up[LOG][MAX_N];
    memset(up, 0, sizeof(up));
    for(int i = 1; i <= MAX_N - 1; i ++) up[0][i] = 0;
    for(int j = 1; j < LOG; j ++) {
        for(int i = 1; i <= MAX_N - 1; i ++) {
            int prev = up[j - 1][i];
            up[j][i] = up[j - 1][prev];
        }
    }
}