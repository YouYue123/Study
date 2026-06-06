#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    int size() const {
        return end - start + 1;
    }
    bool operator<(const Interval& other) const {
        return start < other.start;
    }
};
class CountIntervals {
private:
    set<Interval> dict;
    int cnt = 0;
public:
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        // 寻找第一个可能与 [left, right] 有交集的区间
        auto it = dict.lower_bound({left, 0});
        if(it != dict.begin() && prev(it)->end >= left) {
            it = prev(it);
        }
        int cur_start = left, cur_end = right;
        while (it != dict.end() && it->start <= right) {
            cur_start = min(cur_start, it->start);
            cur_end = max(cur_end, it->end);
            cnt -= it->size();
            it = dict.erase(it); // erase 返回下一个有效迭代器，自动完成递增
        }
        // cout << "at end add elements: " << cur_end - cur_start + 1 << endl;
        cnt += cur_end - cur_start + 1;
        dict.emplace(cur_start, cur_end);
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */