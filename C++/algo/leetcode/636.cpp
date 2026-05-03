// 636. Exclusive Time of Functions [M]
// LeetCode exclusive-time-of-functions

#include <vector>
#include <string>
#include <stack>
#include <regex>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        const std::regex pattern("^(\\d+):(start|end):(\\d+)$");    
        stack<int> st;
        vector<int> ans(n, 0);
        std::smatch matches;
        int prev_time = 0; 

        for(const string& s : logs) {
            // Check for match and capture groups
            if (std::regex_match(s, matches, pattern)) {
                int func_id = stoi(matches[1].str()); 
                string type = matches[2].str();
                int time = stoi(matches[3].str());
                if (type == "start") {
                    if (!st.empty()) {
                        int interrupted_id = st.top();
                        ans[interrupted_id] += time - prev_time;
                    }
                    st.push(func_id);
                    prev_time = time;

                } else { 
                    int duration = time - prev_time + 1;
                    ans[func_id] += duration;
                    st.pop();
                    prev_time = time + 1;
                }
            }
        }
        return ans;
    }
};