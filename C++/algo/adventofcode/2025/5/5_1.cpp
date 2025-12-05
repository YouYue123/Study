#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Range = pair<ull, ull>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    vector<Range> fresh_ranges;
    vector<ull> available_ids;
    bool reading_ranges = true;
    while (getline(cin, line)) {
        if (line.empty()) {
            reading_ranges = false;
            continue;
        }

        if (reading_ranges) {
            size_t dash_pos = line.find('-');
            if (dash_pos != string::npos) {
                string start_str = line.substr(0, dash_pos);
                string end_str = line.substr(dash_pos + 1);

                ull start_num = stoull(start_str);
                ull end_num = stoull(end_str);

                fresh_ranges.push_back({start_num, end_num});
            }
        } else {
            ull id = stoull(line);
            available_ids.push_back(id);
        }
    }

    ull ans = 0;

    for (ull id : available_ids) {
        bool is_fresh = false;

        for (const auto& range : fresh_ranges) {
            if (id >= range.first && id <= range.second) {
                is_fresh = true;
                break;
            }
        }

        if (is_fresh) {
            ans++;
        }
    }


    cout << "ans:" << ans << endl;
}