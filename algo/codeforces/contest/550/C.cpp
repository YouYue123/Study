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
    bool find = false;
    string ans = "";
    string cur = "";
    vector memo(n, vector(8, -1));
    auto dfs = [&] (this auto&& dfs, int i, int rem) -> bool {
        if(i == n) return false;
        if(memo[i][rem] != -1) return memo[i][rem] == 1;
        bool cur_ans = dfs(i + 1, rem);
        int cur_num = s[i] - '0';
        int cur_rem = (rem * 10 + cur_num) % 8;
        if(!cur.empty() || cur_num != 0) {
            if(cur_rem == 0) {
                find = true;
                ans = cur + s[i];
                cur_ans = true;
            } else {
                cur.push_back(s[i]);
                dfs(i + 1, cur_rem);  
                cur.pop_back(); 
            }
        } else if(cur_num == 0) {
            find = true;
            ans = "0";
            cur_ans = true;
        }
        return memo[i][rem] = (cur_num ? 1 : 0);
    };
    dfs(0, 0);
    cout << (find ? "YES" : "NO") << endl;
    if(find) cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}