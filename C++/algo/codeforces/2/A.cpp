#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    unordered_map<string, ll> score_dict;
    vector<pair<string, int>> records(n);
    for(int i = 0; i < n; i ++) {
        cin >> records[i].first >> records[i].second;
        score_dict[records[i].first] += records[i].second;
    }
    ll m = 0;
    for(auto& [name, score] : score_dict) {
        if(m < score) m = score;
    } 
    // cout << score_dict["aawtvezfntstrcpgbzjbf"] << endl;
    // cout << 681 + 661 + -547 + 600 << endl;
    // cout << m << endl;
    string ans = "";
    unordered_map<string, ll> cur_dict;
    for(auto& [name, score] : records) {
        cur_dict[name] += score;
        if(cur_dict[name] >= m && score_dict[name] == m) {
            ans = name;
            break;
        }
    }
    // cout << 
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}