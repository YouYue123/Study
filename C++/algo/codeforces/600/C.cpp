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
    int n = s.size();
    vector cnt(26, 0);
    for(char c : s) cnt[c - 'a'] += 1;
    int odd_cnt = 0;
    deque<char> q;
    for(int i = 0; i < 26; i ++) {
        if(cnt[i] % 2 == 1) {
            odd_cnt += 1;
            q.push_back(i + 'a');
            cnt[i] -= 1;
        }
    }
    string front = "";
    for(int i = 0; i < 26; i ++) {
        char c = i + 'a';
        while(q.size() > 1 && q.front() < c) {
            front.push_back(q.front());
            q.pop_front();
            q.pop_back();
        }
        while(cnt[i] > 0) {
            front += i + 'a';
            cnt[i] -= 2;
        }
    }
    string mid = "";
    if(q.size() != 0) mid += q.front();
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