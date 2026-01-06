#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> cnts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnts[x]++;
    }

    // 1. 如果只有一种元素，显然可以
    if (cnts.size() == 1) {
        cout << "Yes" << endl;
    } else if (cnts.size() == 2) {
        int c1 = cnts.begin()->second;
        int c2 = next(cnts.begin())->second;        
        if (abs(c1 - c2) <= 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }  else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}