#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
struct Item {
    char color;
    int cnt;
    Item(char color, int cnt): color(color), cnt(cnt) {};
};

void solve()
{
    int r, g, b;
    cin >> r >> g >> b;
    vector<Item> colors;
    colors.emplace_back('R', r);
    colors.emplace_back('G', g);
    colors.emplace_back('B', b);
    string ans = "";
    auto isValid = [&] (char color) -> bool {
        int n = ans.size();
        if(n > 0 && ans.back() == color) return false;
        if(n >= 3 && ans[n - 3] == color) return false;
        return true;
    };
    while(true) {
        sort(colors.begin(), colors.end(), [&] (auto& a, auto& b) {
            return a.cnt > b.cnt;
        });
        bool find = false;
        int n = ans.size();
        for(int i = 0; i < 3; i ++) {
            if(colors[i].cnt > 0 && isValid(colors[i].color)) {
                ans += colors[i].color;
                find = true;
                colors[i].cnt -= 1;
                break;
            }
        }
        if(!find) break;
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}