#include <bits/stdc++.h>
using namespace std;

// 352. Data Stream as Disjoint Intervals [H]
// LeetCode data-stream-as-disjoint-intervals

struct Interval {
    int left;
    int right;
    bool operator < (const Interval& other) const {
        return left < other.left;
    }
};
class SummaryRanges {
private:
    set<Interval> arr;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it = arr.lower_bound({ value, value });
        if(it != arr.end() && it->left == value) {
            // covered by current
            return;
        }
        auto prev = (it != arr.begin() ? std::prev(it) : arr.end());
        if(prev != arr.end() && prev->right >= value) {
            // covered by previous
            return;
        }
        bool linkLeft = (prev != arr.end() && prev->right == value - 1);
        bool linkRight = (it != arr.end() && it->left == value + 1 );
        if(linkLeft && linkRight) {
            int l = prev->left, r = it->right;
            arr.erase(prev);
            arr.erase(it);
            arr.emplace(l, r);
        } else if(linkLeft) {
            int l = prev->left;
            arr.erase(prev);
            arr.emplace(l, value);
        } else if(linkRight) {
            int r = it->right;
            arr.erase(it);
            arr.emplace(value, r);
        } else {
            arr.emplace(value, value);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto& item : arr) {
            ans.push_back({ item.left, item.right });
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */