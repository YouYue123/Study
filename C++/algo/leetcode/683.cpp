#include <bits/stdc++.h>
using namespace std;

// 683. K Empty Slots [H]
// LeetCode k-empty-slots

struct MonoQueue {
    deque<int> minQ;
    deque<int> maxQ;
    deque<int> q;
    void push(int x) {
        q.push_back(x);
        while(!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);
        while(!maxQ.empty() && maxQ.back() < x) maxQ.pop_back();
        maxQ.push_back(x);
    }
    int min() { return minQ.front(); };
    int max() { return maxQ.front(); };
    void pop() {
        int item = q.front();
        q.pop_front();
        if(item == minQ.front()) minQ.pop_front();
        if(item == maxQ.front()) maxQ.pop_front();
    }
};
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int left = 0, right = 0;
        int ans = bulbs.size();
        MonoQueue mq;
        vector<int> days(bulbs.size(), 0);
        
        // 转换bulbs数组为days数组
        // days[x]表示位置x的灯泡在第几天开花
        for(int i = 0; i < bulbs.size(); i++) {
            days[bulbs[i] - 1] = i + 1;
        }
        
        for(int i = 0; i < days.size(); i++) {
            int day = days[i];
            mq.push(day);
            
            // 当窗口大小达到k+2时开始检查
            if(k <= i && i < days.size() - 1) {
                mq.pop();
                // 检查条件：窗口两端的天数都小于中间所有天数
                if(k == 0 || (days[i - k] < mq.min() && days[i + 1] < mq.min())) {
                    ans = min(ans, max(days[i - k], days[i + 1]));
                }
            }
        }
        return ans < days.size() ? ans : -1;
    }
};