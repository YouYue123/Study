#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;
int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ull>> nums;
    string line = "";
    vector<pii> points;
    unordered_map<string, vector<string>> g;
    long long ans = 0;
    while(getline(cin, line)) {
        stringstream ss(line);
        string from = "";
        getline(ss, from, ':');
        string value_segment;
        getline(ss, value_segment);
        stringstream values_ss(value_segment);
        string val = "";
        while(values_ss >> val) {
            g[from].push_back(val);
        }
    }
    // for(auto& [key, vals] : g) {
    //     cout << "from: " << key << endl;
    //     cout << "to: ";
    //     for(auto& v : vals) cout << v << " ";
    //     cout << endl;
    // }
    queue<string> q;
    q.push("you");
    while(!q.empty()) {
        int len = q.size();
        // cout << len << endl;
        for(int i = 0; i < len; i ++) {
            auto cur = q.front();
            q.pop();
            if(cur == "out") {
                ans += 1;
                continue;
            }
            for(auto& nx : g[cur]) {
                q.push(nx);
            }
        }
    }
    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}