#include <bits/stdc++.h>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int q;
        cin >> q;

        long long n = 0; 
        long long s = 0; 
        long long ss = 0; 
        long long revS = 0;

        deque<int> left; 
        deque<int> right; 

        for (int i = 0; i < q; ++i) {
            int op;
            cin >> op;

            if (op == 1) {
                long long v;
                if (!right.empty()) {
                    v = right.back();
                    right.pop_back();
                } else {
                    v = left.front();
                    left.pop_front(); 
                }
                left.push_back(v);
                
                ss += s - v * n; 
                revS += v * n - s;

            } else if (op == 2) {
                left.swap(right);
                swap(ss, revS);
            } else { // op == 3
                long long v_val;
                cin >> v_val;
                right.push_back(v_val);
                n++;
                ss += v_val * n;
                s += v_val;
                revS += s;
            }
            cout << ss << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}