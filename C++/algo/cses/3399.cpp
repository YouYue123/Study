#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO" << endl;;
        return;
    }
    
    if (a + b > 0 && (a == 0 || b == 0)) {
        cout << "NO" << endl;
        return;
    }
    
    int draw = n - a - b;
    vector<int> a_cards(n);
    vector<int> b_cards(n);
    
    for (int i = 0; i < n; i++)  a_cards[i] = i + 1;
    
    // 第一部分：前 draw 轮平局
    for (int i = 0; i < draw; i++) b_cards[i] = a_cards[i];
    
    // 第二部分：后 a + b 轮决出胜负
    int m = a + b;
    if (m > 0) {
        // A 的剩余牌是 a_cards[draw ... n-1]
        // B 拿到的是 A 这部分牌 循环左移 a 位 的结果
        for (int i = 0; i < m; i++) {
            b_cards[draw + i] = a_cards[draw + ((i + a) % m)];
        }
    }
    
    // 输出答案
    cout << "YES" << endl;;
    for (int i = 0; i < n; i++) cout << a_cards[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << b_cards[i] << " ";
    cout << endl;
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