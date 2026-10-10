#include <bits/stdc++.h>
using namespace std;

// 3508. Implement Router [M]
// LeetCode implement-router

class Router {
public:
    int limit;
    queue<vector<int>> q;
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> hasDup;
    unordered_map<int, deque<int>> destDict;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        // cout << "addPacket " <<  source << " " << destination << " " << timestamp << endl;
        if(hasDup[source][destination][timestamp]) return false;
        if(q.size() == limit) forwardPacket();
        hasDup[source][destination][timestamp] = true;
        q.push({ source, destination, timestamp });
        destDict[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto item = q.front();
        q.pop();
        hasDup[item[0]][item[1]][item[2]] = false;
        if(destDict[item[1]][0] == item[2]) destDict[item[1]].pop_front();
        return item;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& packetList = destDict[destination];
        return lower_bound(packetList.begin(), packetList.end(), endTime + 1) - lower_bound(packetList.begin(), packetList.end(), startTime); 
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */