#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g;
    vector<string> ans;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        g.push_back(s);
        ans.push_back(s);
    }
    // cout << "here" << endl;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            char c = g[i][j];
            char left_c = j > 0 ? ans[i][j - 1] : ' ';
            char top_c = i > 0 ? ans[i - 1][j] : ' ';
            for(char k = 'A'; k <= 'D'; k ++) {
                if(k == c || k == left_c || k == top_c) continue;
                ans[i][j] = k;
                break;
            }
        }
    }

    for(auto& row : ans) {
        cout << row << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}