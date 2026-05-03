#include <bits/stdc++.h>
using namespace std;

// 295. Find Median from Data Stream [H]
// LeetCode find-median-from-data-stream

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<>> large;
    priority_queue<int> small; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if(large.size() > small.size()) {
            int cur = large.top();
            large.pop();
            small.push(cur);
        }
    }
    
    double findMedian() {
        if(large.size() == small.size()) {
            return (large.top() + small.top()) / 2.0;
        }
        return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */