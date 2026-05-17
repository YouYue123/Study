#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

i128 const INF_I128 = ((i128)1 << 120);

std::ostream &operator<<(std::ostream& os, i128 n) {
    if(n == 0) return os << 0;
    string s;
    while(n > 0) {
        s += '0' + (int)(n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

i128 abs_i128(i128 k) { return k >= 0 ? k : -k; }

void solve()
{
    ll a, n;
    cin >> a >> n;
    i128 a_i128 = (i128) a;
    
    // 现代不越界写法：直接用 0-indexed 的 vector
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end());
    
    ll b_min_digit = b.front(), b_max_digit = b.back();
    string a_s = to_string(a);
    int a_len = a_s.size();
    vector<int> a_digits(a_len);
    for(int i = 0; i < a_len; i++) a_digits[i] = a_s[i] - '0';

    i128 now = 0, ans = INF_I128;
    
    // 1. 尝试构造比 a 少一位的数
    if(a_len > 1) {
        for(int i = 1; i < a_len; i++) now = now * 10 + b_max_digit;
        ans = min(ans, abs_i128(a_i128 - now));
    }

    // 2. 特判全 0 的极端情况
    if(b_min_digit == 0 && b_max_digit == 0) {
        cout << a_i128 << "\n"; 
        return;
    } 
    
    // 3. 尝试构造比 a 多一位的数
    if(b_min_digit == 0) now = b_max_digit;
    else now = b_min_digit;
    for(int i = 2; i <= a_len + 1; i++) now = now * 10 + b_min_digit;
    ans = min(ans, abs_i128(a_i128 - now));

    // 4. 相同位数的数位匹配 (全面改用安全的 0-indexed)
    now = 0;
    bool ok = true;
    for(int i = 0; i < a_len; i++) {
        int cur_digit = a_digits[i];
        
        // Type A: 寻找严格大于 cur_digit 的最小数
        auto it_up = upper_bound(b.begin(), b.end(), cur_digit);
        if(it_up != b.end()) {
            i128 tmp = now * 10 + *it_up;
            for(int j = i + 1; j < a_len; j++) tmp = tmp * 10 + b_min_digit;
            ans = min(ans, abs_i128(a_i128 - tmp));
        }
        
        // Type B: 寻找严格小于 cur_digit 的最大数
        auto it_low = lower_bound(b.begin(), b.end(), cur_digit);
        if(it_low != b.begin()) {
            i128 tmp = now * 10 + *prev(it_low); // prev(it_low) 就是严格小于它的前一个数
            for(int j = i + 1; j < a_len; j++) tmp = tmp * 10 + b_max_digit;
            ans = min(ans, abs_i128(a_i128 - tmp));
        }
                
        if(binary_search(b.begin(), b.end(), cur_digit)) {
            now = now * 10 + cur_digit;
        } else {
            ok = false;
            break;
        }
    }

    if(ok) ans = min(ans, abs_i128(a_i128 - now));
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}