#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using big_int = unsigned __int128;

void solve()
{
    ll a_input;
    int n;
    cin >> a_input >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    int min_d = d[0];
    int max_d = d[1];
    
    string S = to_string(a_input);
    big_int a = a_input;
    big_int ans = -1;
    
    auto update_ans = [&](big_int val) {
        big_int diff = (val > a) ? (val - a) : (a - val);
        if (diff < ans) {
            ans = diff;
        }
    };
    
    if (S.size() > 1) {
        big_int num = 0;
        for (int i = 0; i < S.length() - 1; i++) {
            num = num * 10 + max_d;
        }
        update_ans(num);
    }

    big_int num = 0;
    int first_digit = (min_d == 0) ? max_d : min_d;
    num = first_digit;
    for (int i = 0; i < S.length(); i++) {
        num = num * 10 + min_d;
    }
    update_ans(num);

    auto dfs = [&](this auto&& dfs, int idx, big_int cur, bool is_less, bool is_greater) -> void {
        if (idx == S.length()) {
            update_ans(cur);
            return;
        }

        if (is_less) {
            big_int num = cur;
            for (size_t i = idx; i < S.length(); i++) {
                num = num * 10 + max_d;
            }
            update_ans(num);
            return;
        }
        
        if (is_greater) {
            big_int num = cur;
            for (size_t i = idx; i < S.length(); i++) {
                num = num * 10 + min_d;
            }
            update_ans(num);
            return;
        }
        
        int target_digit = S[idx] - '0';
        for (int i = 0; i < n; i++) {
            if (idx == 0 && d[i] == 0 && S.length() > 1) {
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
    
    ll final_ans = (ll)ans;
    cout << final_ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    if (cin >> T) {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}