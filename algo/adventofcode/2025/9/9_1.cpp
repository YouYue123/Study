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
    vector<string> g;
    vector<pii> points;

    while(getline(cin, line)) {
        stringstream ss(line);
        string num;
        int x= 0, y = 0;
        // 7, 1
        // 11, 1
        while(getline(ss, num, ',')) {
            x = stoi(num);
            getline(ss, num, ',');
            y = stoi(num);
            points.emplace_back(x, y);
        }
    }
    cout << "points: " << points.size() << endl;
    ll ans = LLONG_MIN;
    for(int i = 0; i < points.size(); i++) {
        for(int j = i + 1; j < points.size(); j++) {
            cout << "p1: " << points[i].first << " " << points[i].second << endl;
            cout << "p2: " << points[j].first << " " << points[j].second << endl;
            ll dx = abs(points[j].first - points[i].first) + 1;
            ll dy = abs(points[j].second - points[i].second) + 1;
            ll area = dx * dy;
            cout << "area: " << area << endl;
            ans = max(ans, dx * dy);
        }
    }
    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}