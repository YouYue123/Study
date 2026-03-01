#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> getContinuousFailures(const vector<pair<string, string>>& events, int threshold) {
    unordered_map<string, int> fail_counts;
    unordered_set<string> result_set;

    for (const auto& event : events) {
        const string& user = event.first;
        const string& status = event.second;

        if (status == "Failure") {
            fail_counts[user]++;
            if (fail_counts[user] >= threshold) {
                result_set.insert(user);
            }
        } else {
            // 遇到 Pass，连续性中断，计数清零
            fail_counts[user] = 0;
        }
    }
    return vector<string>(result_set.begin(), result_set.end());
}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

struct Event {
    int time;
    string user;
    string status;
};

vector<string> getFailuresInTimeWindow(const vector<Event>& events, int threshold, int T) {
    // key: username, value: deque of timestamps for CURRENT continuous failures
    unordered_map<string, deque<int>> user_fail_windows;
    unordered_set<string> result_set;

    for (const auto& e : events) {
        // 如果该用户已经达标，可以根据需求选择是否跳过后续逻辑
        // if (result_set.count(e.user)) continue; 

        if (e.status == "Pass") {
            // 关键点：Pass 直接重置该用户的所有连续记录
            user_fail_windows[e.user].clear();
        } else {
            auto& window = user_fail_windows[e.user];
            window.push_back(e.time);

            // 维护滑动窗口：移除超出时间范围 T 的早期失败记录
            while (!window.empty() && (e.time - window.front() > T)) {
                window.pop_front();
            }

            if (window.size() >= threshold) {
                result_set.insert(e.user);
            }
        }
    }
    return vector<string>(result_set.begin(), result_set.end());
}

int main() {
    vector<Event> events = {
        {1, "Tom", "Failure"},
        {3, "Jack", "Pass"},
        {5, "Tom", "Failure"},
        {7, "Tom", "Failure"}, // 5到7在时间窗口内
        {10, "Tom", "Pass"}
    };

    auto results = getFailuresInTimeWindow(events, 2, 3); // 阈值2次，窗口3秒
    for (const string& name : results) {
        cout << name << " "; // 输出 Tom
    }
    return 0;
}