#include <bits/stdc++.h>
using namespace std;

// 359. Logger Rate Limiter [E]
// LeetCode logger-rate-limiter

class Logger {
public:
    unordered_map<string, int> dict;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(!dict.contains(message)) {
            dict[message] = timestamp;
            return true;
        } else {
            // cout << "Find previous " << message << " " << dict[message] << endl; 
            // cout << "gap since last call " <<  timestamp - dict[message] << endl;
            if(timestamp - dict[message]  < 10) {
                return false;
            } else {
                dict[message] = timestamp;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */