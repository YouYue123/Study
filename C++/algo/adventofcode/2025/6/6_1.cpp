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
    while(getline(cin, line)) {
        // cout << line << endl;
        stringstream ss(line);
        if(line[0] != '*') {
            ull num;
            vector<ull> temp;
            while(ss >> num) temp.push_back(num);
            nums.push_back(temp);
        } else {
            string op = "";
            int i = 0; 
            while(ss >> op) {
                // cout << op << " " << endl;
                if(op == "+") {
                    for(auto& arr : nums) ans += arr[i];
                } else if(op == "*") {
                    ull cur = 1;
                    for(auto& arr : nums) cur *= arr[i];
                    ans += cur;
                }
                i += 1;
            }
        }
    }

    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}