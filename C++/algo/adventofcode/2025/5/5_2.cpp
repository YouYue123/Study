#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Range = pair<ull, ull>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    vector<Range> ranges;
    while (getline(cin, line)) {
        if (line.empty()) break;

        size_t dash_pos = line.find('-');
        if (dash_pos != string::npos) {
            string start_str = line.substr(0, dash_pos);
            string end_str = line.substr(dash_pos + 1);
            ull start_num = stoull(start_str);
            ull end_num = stoull(end_str);
            ranges.push_back({start_num, end_num});
        }
    }

    ull ans = 0;
    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    ull curStart = ranges.front().first;
    ull curEnd = ranges.front().second;
    for(auto& range : ranges) {
        // cout << "range: " << range.first << " " << range.second << endl;
        if(range.first > curEnd) {
            ans += curEnd - curStart + 1;
            curStart = range.first;
            curEnd = range.second;
        } else {
            curEnd = max(curEnd, range.second);
        }
    }
    ans += curEnd - curStart + 1;
    cout << "ans:" << ans << endl;
}