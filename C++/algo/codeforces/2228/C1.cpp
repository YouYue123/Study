#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u128 = unsigned __int128;

void solve()
{
    ll a, n;
    if (!(cin >> a >> n)) return;
    
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());
    
    int min_d = d.front(), max_d = d.back();
    string S = to_string(a);
    u128 ans = -1;
    
    auto update_ans = [&](u128 val) {
        u128 diff = (val > a) ? (val - a) : (a - val);
        if (diff < ans) ans = diff;
    };
    
    // 1. 尝试构造比 a 少一位的数
    if (S.size() > 1) {
        u128 num = 0;
        for (size_t i = 0; i < S.size() - 1; i++) {
            num = num * 10 + max_d;
        }
        update_ans(num);
    }

    // 2. 尝试构造比 a 多一位的数 (排除只有数字 0 的极端情况)
    if(min_d != 0 || n > 1) {
        u128 num = (min_d == 0) ? d[1] : min_d;
        for(size_t i = 0; i < S.size(); i++) {
            num = num * 10 + min_d;
        }
        update_ans(num);
    }

    // 3. 同位数匹配：改用稳健的 DFS 避开贪心盲区
    auto dfs = [&](this auto&& dfs, int idx, u128 cur, bool is_less, bool is_greater) -> void {
        if (idx == S.size()) {
            update_ans(cur);
            return;
        }
        
        // 如果当前已经严格小了，后面直接全部无脑填最大，贪心结算
        if (is_less) {
            u128 num = cur;
            for (size_t i = idx; i < S.size(); i++) {
                num = num * 10 + max_d;
            }
            update_ans(num);
            return;
        }
        
        // 如果当前已经严格大了，后面直接全部无脑填最小，贪心结算
        if (is_greater) {
            u128 num = cur;
            for (size_t i = idx; i < S.size(); i++) {
                num = num * 10 + min_d;
            }
            update_ans(num);
            return;
        }
        
        int target_digit = S[idx] - '0';
        // 穷举当前位允许选的所有数字
        for (int i = 0; i < n; i++) {
            // 防前导零限制：第一位且长度大于1时，不能选0
            if (idx == 0 && d[i] == 0 && S.size() > 1) {
                continue;
            }
            if (d[i] < target_digit) {
                dfs(idx + 1, cur * 10 + d[i], true, false);
            } else if (d[i] > target_digit) {
                dfs(idx + 1, cur * 10 + d[i], false, true);
            } else {
                dfs(idx + 1, cur * 10 + d[i], false, false);
            }
        }
    };
    
    dfs(0, 0, false, false);
    
    cout << (ll)ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}