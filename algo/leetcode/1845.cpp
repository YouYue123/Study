#include <bits/stdc++.h>
using namespace std;

// 1845. Seat Reservation Manager [M]
// LeetCode seat-reservation-manager

class SeatManager {
public:
    int thres = 1;
    set<int> dict;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if(dict.empty()) {
            int ans = thres;
            thres += 1;
            return ans;
        }
        int ans = * dict.begin();
        dict.erase(*dict.begin());
        return ans;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber < thres) {
            dict.insert(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */