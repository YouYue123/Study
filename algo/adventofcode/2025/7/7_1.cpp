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
    vector<vector<ull>> nums;
    string line = "";
    vector<string> g;
    while(getline(cin, line)) g.push_back(line);
    int n = g.size(), m = g[0].size();
    int sCol = 0;
    for(int j = 0; j < m; j ++) {
        if(g[0][j] == 'S') sCol = j;
    }
    // cout << sCol << endl;
    queue<int> q;
    q.push(sCol);
    int row = 0;
    while(row < n - 1) {
        int len = q.size();
        int nRow = row + 1;
        unordered_set<int> nT;
        for(int i = 0; i < len ; i ++) {
            int cur = q.front(); q.pop();
            if(g[nRow][cur] == '^') {
                if(cur - 1 >= 0) nT.insert(cur - 1);
                if(cur + 1 < m - 1) nT.insert(cur + 1);
                ans += 1;
            } else {
                nT.insert(cur);
            }
        }
        cout << "For row: " << nRow + 1 << endl;
        // ans += nT.size();
        for(int item : nT) {
            cout << item << " ";
            q.push(item);
        }
        cout << endl;
        // cout << nRow <<
        row = nRow;
    }
    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}