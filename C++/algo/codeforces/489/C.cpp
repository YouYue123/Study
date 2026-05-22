#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m, s;
    cin >> m >> s;
    if(s == 0) {
        if(m == 1) {
            cout << "0 0" << endl;
            return 0;
        } else {
            cout << "-1 -1" << endl;
            return 0;
        }
    } 
    string min_ans = "", max_ans = "";
    int min_sum = 0, max_sum = 0;
    for(int i = 0; i < m; i ++) {
        int res = m - i - 1;
        bool min_ok = false, max_ok = false;
        for(int cand = 0; cand <= 9; cand ++) {
            if(min_ans.empty() && cand == 0) continue;
            int nxt_min = min_sum + cand + res * 0;
            int nxt_max = min_sum + cand + res * 9;
            if(nxt_min <= s && nxt_max >= s) {
                min_sum += cand;
                min_ans += cand + '0';
                min_ok = true;
                break;
            }
        }
        for(int cand = 9; cand >= 0; cand --) {
            if(max_ans.empty() && cand == 0) continue;
            int nxt_min = max_sum + cand + res * 0;
            int nxt_max = max_sum + cand + res * 9;
            if(nxt_min <= s && nxt_max >= s) { 
                max_sum += cand;
                max_ans += cand + '0';
                max_ok = true;
                break;
            }
        }
        if(!min_ok || !max_ok) {
            min_ans = "-1";
            max_ans = "-1";
            break;
        }
    }
    cout << min_ans << " " << max_ans << endl;
}