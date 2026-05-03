#include <bits/stdc++.h>
using namespace std;

// 732. My Calendar III [H]
// LeetCode my-calendar-iii

class MyCalendarThree {
public:
    map<int, int> cnt;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int ans = 0;
        int cur = 0;
        cnt[startTime] += 1;
        cnt[endTime] -= 1;
        for(auto& [time, freq] : cnt) {
            cur += freq;
            ans = max(cur, ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */