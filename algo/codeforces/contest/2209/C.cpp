#include <bits/stdc++.h>
using namespace std;
 
int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
 
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}
 
void answer(int k) {
    cout << "! " << k << endl;
    cout.flush();
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
 
        bool found = false;
 
        auto try_edge = [&](int u, int v) {
            if (found) return;
            int res = ask(u, v);
            if (res == 1) {
                answer(u);
                found = true;
            }
        };
 
        try_edge(2, 3);
        try_edge(3, 4);
        try_edge(2, 4);
 
        for (int i = 5; i <= 2 * n && !found; i += 2) {
            try_edge(i, i + 1);
        }
 
        if (!found) {
            answer(1);
        }
    }
 
    return 0;
}