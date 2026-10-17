#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    auto get_lps = [&] (string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for(int i = 1, match = 0; i < n; i ++) {
            while(match > 0 && s[i] != s[match]) match = lps[match - 1];
            if(s[i] == s[match]) match += 1;
            lps[i] = match;
        }
        return lps;
    };
    auto cnt_cmd = [&] (ll a, ll b) {
        long long g = gcd(a, b);
        int cnt = 1;
        for (long long num = 2; num * num <= g; num += 1) {
            if (g % num == 0) {
                int cur_cnt = 0;
                while (g % num == 0) {
                    cur_cnt++;
                    g /= num;
                }
                cnt *= (cur_cnt + 1);
            }
        }
        if (g > 1) cnt *= 2;
        return cnt;
    };
    auto lps1 = get_lps(s1);
    auto lps2 = get_lps(s2);
    int p1_len = s1.size() - lps1.back();
    int p2_len = s2.size() - lps2.back();
    if(n % p1_len != 0 || m % p2_len != 0) {
        cout << 0 << endl;
    } else {
        string new_s1 = s1.substr(0, p1_len);
        string new_s2 = s2.substr(0, p2_len);
        if(new_s1 != new_s2) {
            if(new_s2 != s1 && new_s1 != s2) cout << 0 << endl;
            else cout << 1 << endl;
        } else {
            int rep1 = n / p1_len, rep2 = m / p2_len;
            cout << cnt_cmd(rep1, rep2) << endl;
        }
    }
    return 0;
}