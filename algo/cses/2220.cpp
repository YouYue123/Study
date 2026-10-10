#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string a, b;
    cin >> a >> b;
    int len = max(a.size(), b.size());
    if (a.size() < len) a = string(len - a.size(), '0') + a;
    if (b.size() < len) b = string(len - b.size(), '0') + b;
    if(a > b) swap(a, b); 
    // cout << "a: " << a << endl;
    // cout << "b: " << b << endl;
    vector memo(len, vector(11, -1LL));
    auto dfs = [&] (auto& dfs, int i, int prev, bool is_low, bool is_high, bool leading_zero) -> ll {
        if(i == len) {
            return 1LL;
        }
        if(!is_low && !is_high && !leading_zero && memo[i][prev] != -1) return memo[i][prev];
        int low = is_low ? a[i] - '0' : 0;
        int high = is_high ? b[i] - '0' : 9;
        ll ans = 0;
        for(int num = low; num <= high; num ++) {
            if(num == prev && !leading_zero) continue;
            ans += dfs(dfs, i + 1, num, is_low && num == low, is_high && num == high, leading_zero && num == 0);
        }
        if(!is_low && !is_high && !leading_zero) memo[i][prev] = ans;
        return ans;
    };
    cout << dfs(dfs, 0, 10, true, true, true) << endl;;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}