#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Stat {
    ll start;
    ll end;
    ll base_num;
};
void solve()
{
    int q;
    cin >> q;
    ll start = 1, len = 1, k;
    vector<Stat> stats(19); 
    while(len <= 18) {
        ll cnt = 9 * pow(10LL, len - 1);
        // cout << "len: " << len << " cnt: " << cnt << endl;
        ll end = start + len * cnt - 1;
        // cout << start << " - " << end << endl;
        stats[len] = Stat(start, end, pow(10LL, len - 1));
        start = end + 1;
        len += 1;
    }

    auto solve = [&] (ll x) -> int {
        for(int len = 1; len <= 18; len ++) {
            auto& stat = stats[len]; 
            if(x <= stat.end) {
                // cout << "num len is: " << len << endl;
                ll step = (x - stat.start) / len;
                ll cur_num = step + stat.base_num;
                // if(x == 194) cout << "cur_num: " << cur_num << endl;
                ll rem = (x - stat.start) % len;
                // if(x == 194) cout << "pos: " << rem << endl;
                // cout << to_string(cur_num)[(len - rem + len) % len] << endl;
                return to_string((ll)cur_num)[rem] - '0';
            }
        }
        return -1;
    };

    // for(int tmp = 1; tmp <= 1000000; tmp += 1) {
    //     cout << solve(tmp) << " - ";
    // }
    // cout << endl;
    for(int i = 0; i < q; i ++) {
        ll k;
        cin >> k;
        cout << solve(k) << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}