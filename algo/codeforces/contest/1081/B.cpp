#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> pos1;
    vector<int> pos0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            pos1.push_back(i + 1);
        } else {
            pos0.push_back(i + 1);
        }
    }
    if(pos1.size() % 2 == 0) {
        cout << pos1.size() << endl;
        for(int idx : pos1) {
            cout << idx << " ";
        }
        if(pos1.size() != 0 )cout << endl;
        return;
    }
    if(pos0.size() % 2 != 0) {
        cout << pos0.size() << endl;
        for(int idx : pos0) {
            cout << idx << " "; 
        }
        cout << endl;
        return;
    }
    cout <<  -1 << endl;
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