#include <bits/stdc++.h>
using namespace std;

// 862. Shortest Subarray with Sum at Least K [H]
// LeetCode shortest-subarray-with-sum-at-least-k

int constexpr INF = 0x3f3f3f3f;
template<typename F>
concept Predicate = requires(F f, int a, int b) {
    { f(a, b) } -> convertible_to<bool>;
};
template<Predicate PushCmp, Predicate PopCmp>
struct MonoQueue {
    PushCmp push_cmp;
    PopCmp pop_cmp;
    deque<int> q;

    void push(int idx) {
        while(!q.empty() && push_cmp(q.back(), idx)) q.pop_back();
        q.push_back(idx);
    }

    void pop(int idx) {
        if(!q.empty() && pop_cmp(q.front(), idx)) {
            q.pop_front();
        }
    }

    int front() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector presum(n + 1, 0LL);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];
        auto push_cmp = [&] (int back_idx, int cur_idx) {
            return presum[back_idx] >= presum[cur_idx];
        };
        auto pop_cmp = [&] (int front_idx, int cur_idx) {
            return true;
        };
        auto mq = MonoQueue<decltype(push_cmp), decltype(pop_cmp)>(push_cmp, pop_cmp);
        int right = 0;
        int ans = INF;
        while(right < n + 1) {
            mq.push(right);
            while(!mq.empty() && presum[right] - presum[mq.front()] >= k) {
                ans = min(ans, right - mq.front());
                mq.pop(right);
            }
            right += 1;
        }
        return ans == INF ? -1 : ans;
    }
};