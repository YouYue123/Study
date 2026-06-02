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
    vector ans(n, vector(n, 0));
    vector row_dict(n,  unordered_set<int>());
    vector col_dict(n, unordered_set<int>());
    for(int i = 0; i < n; i ++) {
        ans[0][i] = i;
        row_dict[0].insert(i);
        col_dict[i].insert(i);
        ans[i][0] = i;
        row_dict[i].insert(i);
        col_dict[0].insert(i);
    }
    
    for(int r = 1; r < n; r ++) {
        for(int c = 1; c < n; c ++) {
            int num = 0;
            while(true) {
                if(!row_dict[r].contains(num) && !col_dict[c].contains(num)) {
                    row_dict[r].insert(num);
                    col_dict[c].insert(num);
                    ans[r][c] = num;
                    break;
                }
                num += 1;
            }
            
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}