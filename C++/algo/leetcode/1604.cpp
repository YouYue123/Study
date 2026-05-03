// 1604. Alert Using Same Key-Card Three or More Times in a One Hour Period [M]
// LeetCode alert-using-same-key-card-three-or-more-times-in-a-one-hour-period

// struct Time {
//     int hour;
//     int minute;
//     bool operator < (const Time& other) const {
//         if(hour == other.hour) return minute < other.minute;
//         return hour < other.hour;   
//     }
// };
struct Access {
    string name;
    int timestamp;
    Access(string name, string time) {
        this->name = name;
        this->timestamp = parseTime(time);
    }
    int parseTime(string& time) {
        int pos = time.find(':');
        int hour = stoi(time.substr(0, pos));
        int minute = stoi(time.substr(pos + 1));
        return hour * 60 + minute;
    }
};
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        vector<Access> records;
        for(int i = 0; i < n; i ++) records.emplace_back(keyName[i], keyTime[i]);
        sort(records.begin(), records.end(), [&] (auto& a, auto& b) {
            return a.timestamp < b.timestamp;
        });
        unordered_set<string> ans;
        unordered_map<string, deque<int>> dict;
        for(auto& record : records) {
            // cout << record.name << " " << record.timestamp << endl;
            string name = record.name;
            int timestamp = record.timestamp;
            while(!dict[name].empty() && abs(dict[name].front() - timestamp) > 60 ) {
                dict[name].pop_front();
            }
            dict[name].push_back(timestamp);
            // cout << dict[name].size() << endl;
            if(dict[name].size() >= 3) ans.insert(name);
        }
        vector<string> finalAns;
        for(auto name : ans) finalAns.push_back(name);
        sort(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};