#include <bits/stdc++.h>
using namespace std;

// 3433. Count Mentions Per User [M]
// LeetCode count-mentions-per-user

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        sort(events.begin(), events.end(), [&](auto& e1, auto& e2) {
            if(e1[1] == e2[1]) {
                if(e1[0] == "OFFLINE") return true;
            }
            return stoi(e1[1]) < stoi(e2[1]);
        }); 
        vector<int> offline(n, -1);
        vector<int> ans(n, 0);
        for(auto& e : events) {
            string act = e[0];
            int timestamp = stoi(e[1]);
            // cout << e[0] << " " << e[1] << " " << e[2] << endl;
            if(act == "MESSAGE") {
                if(e[2] == "ALL") {
                    for(int i = 0; i < n;i ++) ans[i] += 1;
                } else if(e[2] == "HERE") {
                    for(int i = 0; i < n; i ++) {
                        // cout << timestamp << " " << offline[i] << endl;
                        if(offline[i] != -1 && timestamp - offline[i] < 60) continue;
                        // cout << "online" << endl;
                        ans[i] += 1;
                    }
                } else {
                    stringstream ss(e[2]);
                    string idStr = "";
                    while(ss >> idStr) {
                        int id = stoi(idStr.substr(2));
                        // cout << "mention " << id << endl;
                        ans[id] += 1;
                    }
                }
            } else if(act == "OFFLINE") {
                int id = stoi(e[2]);
                offline[id] = timestamp;
            }
        }
        return ans;
    }
};