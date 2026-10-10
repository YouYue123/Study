#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct MonoQueue {
    vector<ll>& prev;
    vector<ll>& presum;
    deque<int> q;
    void push (int idx) {
        while(!q.empty() && get_val(q.back()) <= get_val(idx)) {
            q.pop_back();
        }
        q.push_back(idx);
    }

    void slide(int idx) {
        if(q.front() <= idx) q.pop_front();
    }

    ll get_max() {
        return get_val(q.front());
    }
    
    ll get_val(int idx) {
        return prev[idx] - presum[idx];
    }
};
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> presum(n + 1);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];
        // memo[cnt][end]：前缀 nums[0..end-1] 中恰好 cnt 个子数组的最大和
        vector memo(m + 1, vector(n + 1, -INF));
        long long ans = -INF;
        ranges::fill(memo[0], 0);

        for (int cnt = 1; cnt <= m; ++cnt) {
            auto q = MonoQueue(memo[cnt - 1], presum);
            for (int end = cnt * l; end <= n; ++end) {
                // 1. 入
                q.push(end - l);
                // 2. 更新
                memo[cnt][end] = max(
                    memo[cnt][end - 1],
                    q.get_max() + presum[end]
                );
                // 3. 出
                q.slide(end - r);
            }
            ans = max(ans, memo[cnt][n]);
        }
        return ans;

        // auto dfs = [&] (this auto&& dfs, int i, int cnt) -> long long {
        //     if(cnt > m) return -INF;
        //     if(i == n) return cnt == 0 ? -INF : 0LL;
        //     if(memo[cnt][i] != INF) return memo[cnt][i];
        //     long long ans = dfs(i + 1, cnt);
        //     long long cur_sum = 0;
        //     for(int j = i; j < n; j ++) {
        //         cur_sum += nums[j];
        //         int len = j - i + 1;
        //         if(len < l) continue;
        //         if(len > r) break;
        //         ans = max(ans, cur_sum + dfs(j + 1, cnt + 1));
        //     }
        //     return memo[cnt][i] = ans;
        // };        
        // return dfs(0, 0);
    }
};