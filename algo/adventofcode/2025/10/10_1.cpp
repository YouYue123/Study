#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int solve(string& target, vector<vector<int>>& buttons) {
    int n = target.size();
    ull target_mask = 0;
    for (int i = 0; i < n; ++i) {
        if (target[i] == '#') target_mask |= (1ULL << i);
    }
    vector<ull> masks;
    for (auto& button : buttons) {
        ull mask = 0;
        for (int pos : button) mask |= (1ULL << pos);
        masks.push_back(mask);
    }
    queue<pair<ull, int>> q;
    unordered_set<ull> visited;
    q.push({0, 0});
    visited.insert(0);
    while (!q.empty()) {
        auto [state, cnt] = q.front();
        q.pop();
        if (state == target_mask) return cnt;
        for (auto& mask : masks) {
            ull new_state = state ^ mask;
            if (visited.find(new_state) == visited.end()) {
                visited.insert(new_state);
                q.push({new_state, cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    ull ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while(getline(cin, line)) {
        if(line.empty()) continue;
        
        string target;
        vector<vector<int>> buttons;
        // Parse target
        int start_pos = line.find('[');
        int end_pos = line.find(']');
        if(start_pos != string::npos && end_pos != string::npos) {
            target = line.substr(start_pos + 1, end_pos - start_pos - 1);
        }
        int pos = end_pos + 1;
        while(pos < line.length()) {
            pos = line.find('(', pos);
            if(pos == string::npos || line[pos] == '{') break;
            int button_end = line.find(')', pos);
            if(button_end == string::npos) break;
            string button_str = line.substr(pos + 1, button_end - pos - 1);
            vector<int> button;
            stringstream button_ss(button_str);
            string num_str;
            while(getline(button_ss, num_str, ',')) {
                num_str.erase(remove_if(num_str.begin(), num_str.end(), ::isspace), num_str.end());
                if (!num_str.empty()) {
                    button.push_back(stoi(num_str));
                }
            }
            buttons.push_back(button);
            pos = button_end + 1;
        }
        ans += solve(target, buttons);
    }
    
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}