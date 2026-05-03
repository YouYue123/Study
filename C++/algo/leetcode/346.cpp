#include <bits/stdc++.h>
using namespace std;

// 346. Moving Average from Data Stream [E]
// LeetCode moving-average-from-data-stream

class MovingAverage {
private:
    queue<int> q;
    int size;
    int sum = 0;
public:
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return (1.0 * sum) / q.size(); 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */