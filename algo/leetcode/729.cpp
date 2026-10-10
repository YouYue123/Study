#include <bits/stdc++.h>
using namespace std;

// 729. My Calendar I [M]
// LeetCode my-calendar-i

using pii = pair<int, int>;
class MyCalendar {
private:
    vector<pii> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto& booking : bookings) {
            if(max(booking.first, startTime) < min(booking.second, endTime)) {
                return false;
            }
        }
        bookings.emplace_back(startTime, endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */