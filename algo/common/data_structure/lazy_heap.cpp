#include <deque>
using namespace std;
template<typename T, typename Compare = less<T>>
struct LazyHeap {
    pirority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> removeCnt;
    int size = 0;
    void applyRemove() {
        while(!pq.empty() && removeCnt[pq.top()] > 0) {
            removeCnt[pq.top()] -= 1;
            pq.pop();
        }
    }
    void remove(int x) {
        removeCnt[x] += 1;
        size -= 1;
    }
    void push(int x) {
        pq.push(x);
        size += 1;
    }
    T top() {
        applyRemove();
        return pq.top();   
    }
    void pop() {
        applyRemove();
        size -= 1;
        pq.pop();
    }
};

