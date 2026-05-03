// 1396. Design Underground System [M]
// LeetCode design-underground-system

struct Stats {
    long long sum;
    int cnt;
    double getAverage () {
        return 1.0 * sum / cnt;
    }
};
struct CheckinInfo {
    string stationName;
    int t;
};
class UndergroundSystem {
private:
    unordered_map<string, unordered_map<string, Stats>> stats;
    unordered_map<int, CheckinInfo> checkInDict;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(checkInDict.contains(id)) return;
        checkInDict[id] = {
            stationName,
            t,
        };
    }
    
    void checkOut(int id, string stationName, int t) {
        if(!checkInDict.contains(id)) return;
        auto& info = checkInDict[id];
        // cout << info.stationName << "-->" << stationName << endl;
        auto& stat = stats[info.stationName][stationName];
        stat.sum += t - info.t;
        stat.cnt += 1;
        checkInDict.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(!stats.contains(startStation) || !stats[startStation].contains(endStation)) {
            return -1.0;
        }
        return stats[startStation][endStation].getAverage();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */