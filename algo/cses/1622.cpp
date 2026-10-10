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
    vector cnt(26, 0);
    for(int i = 0; i < n; i ++) {
        cnt[s[i] - 'a'] += 1;
    }
    vector<string> ans;
    auto dfs = [&] (auto& dfs, string& cur) {
        if(cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < 26; i ++) {
            if(cnt[i] == 0) continue;
            cnt[i] -= 1;
            cur.push_back(i + 'a');
            dfs(dfs, cur);
            cur.pop_back();
            cnt[i] += 1;
        }
    };
    string tmp = "";
    dfs(dfs, tmp);

    cout << ans.size() << endl;

    for(auto& item : ans) {
        cout << item << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}