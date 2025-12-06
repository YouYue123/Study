#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ull, ull>;
int main() {
    auto start = chrono::high_resolution_clock::now();
    ull ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> numLines;
    string line = "";
    while(getline(cin, line)) {
        // cout << line << endl;
        stringstream ss(line);
        if(line[0] != '*') {
            numLines.push_back(line);
        } else {
            string op = "";
            vector<int> pointers(numLines.size());
            while(ss >> op) {
                // cout << op << " " << endl;
                vector<int> curNums;
                while(true) {
                    bool hasValid = false;
                    int cur = 0;
                    for(int i = 0; i < pointers.size(); i ++) {
                        int p = pointers[i];
                        string s = numLines[i];
                        if(isdigit(s[p])) {
                            cur = cur * 10 + (s[p] - '0');
                            hasValid = true;
                        }
                        pointers[i] += 1;
                    }
                    if(cur != 0) curNums.push_back(cur);
                    if(!hasValid) {
                        break;
                    }
                }
                // for(int num : curNums) cout << num << " ";
                // cout << endl;
                if(op == "+") {
                    for(int num : curNums) ans += num;
                } else if(op == "*") {
                    ull cur = 1;
                    for(int num : curNums) cur *= num;
                    ans += cur;
                }
            }
        }
    }

    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}