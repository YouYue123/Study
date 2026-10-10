#include <bits/stdc++.h>
using namespace std;

// 362. Design Hit Counter [M]
// LeetCode design-hit-counter

struct Count {
    int timestamp;
    int cnt;
};
class HitCounter {
private:
    int cnt = 0;
    queue<Count> q;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if(!q.empty() && q.back().timestamp == timestamp) {
            q.back().cnt += 1;
        } else {
            q.emplace(timestamp, 1);
        }
        cnt += 1;
    }
    
    int getHits(int timestamp) {
        while(!q.empty() && (timestamp - q.front().timestamp) >= 300) {
            cnt -= q.front().cnt;
            q.pop();
        }
        return cnt;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */