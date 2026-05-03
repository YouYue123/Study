#include <bits/stdc++.h>
using namespace std;

// 1756. Design Most Recently Used Queue [M]
// LeetCode design-most-recently-used-queue

class MRUQueue {
private:
    list<int> queue;
    // { val: it }
    // unordered_map<int, list<int>::iterator> dict;
    // vector<>
public:
    MRUQueue(int n) {
        for(int i = 1; i <= n; i ++) {
            queue.push_back(i);
            // dict[val] = prev(queue.end());
        }
    }
    
    int fetch(int k) {
        auto it = queue.begin();
        while(k > 1) {
            it ++;
            k -= 1;
        }
        int val = *it;
        queue.erase(it);
        queue.emplace_back(val);
        return val;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */