#include <bits/stdc++.h>
using namespace std;

// 731. My Calendar II [M]
// LeetCode my-calendar-ii

struct Range {
    int start;
    int end;
};
class MyCalendarTwo {
private:
    vector<Range> booked;
    vector<Range> overlaps;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto& r : overlaps) {
            if(max(startTime, r.start) < min(endTime, r.end)) {
                return false;
            }
        }
        for(auto& r : booked) {
            if(max(startTime, r.start) < min(endTime, r.end)) {
                overlaps.push_back({
                    max(startTime, r.start),
                    min(endTime, r.end)
                });
            }
        }
        booked.push_back({ startTime, endTime });
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */