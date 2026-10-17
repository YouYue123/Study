#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();

    // 1. 计算 KMP 的 lps 数组 (Prefix Function)
    // lps[i] 表示 s[0...i] 中最长的相等前后缀的长度
    vector<int> lps(n, 0);
    for(int i = 1, match = 0; i < n; i ++) {
        while(match > 0 && s[i] != s[match]) match = lps[match - 1];
        if(s[i] == s[match]) match += 1;
        lps[i] = match;
    }
    // 2. 统计每个前缀出现的次数
    // cnt[len] 表示长度为 len 的前缀在 s 中出现的次数
    vector<int> cnt(n + 1, 0);
    // 首先记录每个位置 i 贡献的最长相等前后缀
    for(int i = 0; i < n; i ++) {
        if(lps[i] > 0) {
            int len = lps[i];
            cnt[len] += 1;
        }
    }
    // 关键：逆向递推 (DP)
    // 如果长度为 len 的前缀出现了，那么它的最长相等前后缀 (lps[len-1]) 
    // 也一定在同样的位置出现过。我们必须从大到小累加，保证长前缀的贡献传递给短前缀。
    for(int len = n; len > 0; len --) {
        int prev_len = lps[len - 1];
        if(prev_len> 0) {
            cnt[prev_len] += cnt[len];
        }
    }
    // 每个长度为 len 的前缀在 s 的起始位置 (s[0...len-1]) 必然出现过一次
    for(int len = 1; len <= n; len ++) cnt[len] += 1;

    vector<pair<int, int>> ans;
    // 3. 筛选出既是前缀又是后缀的子串 (Borders)
    // 只有通过 n -> lps[n-1] -> lps[lps[n-1]-1] ... 这条路径跳回来的长度才是后缀
    int len = n;
    while(len > 0) {
        ans.emplace_back(len, cnt[len]);
        len = lps[len - 1];
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end(), [&](auto& a, auto& b) { return a.first < b.first; });
    for(auto& item : ans) {
        cout << item.first << " " << item.second << endl;
    }
}