#include <bits/stdc++.h>
using namespace std;

// 855. Exam Room [M]
// LeetCode exam-room

class ExamRoom {
public:
    int n;
    set<int> seats;
    ExamRoom(int n):n(n) {
    }
    
    int seat() {
        if(seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int maxDist = *seats.begin(), seatToAdd = 0;
        int prev = *seats.begin();
        for(auto it = next(seats.begin()); it != seats.end(); ++it) {
            int cur = *it;
            int gap = (cur - prev) / 2;
            // cout << gap << endl;
            if(gap > maxDist) {
                maxDist = gap;
                seatToAdd = prev + gap;
            }
            prev = *it;
        }
        int lastSeat = *seats.rbegin();
        if(n - 1 - lastSeat > maxDist) {
            maxDist = n - 1 - lastSeat;
            seatToAdd = n - 1;
        }
        seats.insert(seatToAdd);
        return seatToAdd;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */