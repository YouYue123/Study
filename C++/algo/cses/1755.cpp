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
    vector cnt(26, 0);
    for(char c : s) {
        cnt[c - 'A'] += 1;
    }
    int odd_cnt = 0, odd_idx = 0;
    for(int i = 0; i < 26; i ++) {
        if(cnt[i] % 2 == 1) {
            odd_cnt += 1;
            odd_idx = i;
        }
    }
    string front = "", mid = "";
    if(odd_cnt > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    } else if (odd_cnt == 1) {
        mid += 'A' + odd_idx;
        cnt[odd_idx] -= 1;
    }
    for(int i = 0; i < 26; i ++) {
        char c = i + 'A';
        // cout << "c: " << c << " cnt[i]: " << cnt[i] << endl;
        for(int j = 0; j < cnt[i] / 2; j += 1) front += c;
        // cout << "front: " << front << endl;
    }
    string back = front;
    reverse(back.begin(), back.end());
    cout << front + mid + back << endl;

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}