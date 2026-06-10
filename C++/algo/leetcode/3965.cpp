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
        // memo[i][j] 表示在[0, j - 1] 中选出恰好 i 个子数组，所选元素之和的最大值
        vector memo(m + 1, vector(n + 1, -INF));
        long long ans = -INF;
        ranges::fill(memo[0], 0);
    
        for(int i = 1; i <= m; i ++) {
            auto q = MonoQueue(memo[i - 1], presum);
            for(int j = i * l; j <= n; j ++) {
                // 1. 入
                q.push(j - l);
                 // 2.更新
                memo[i][j] = max(
                    memo[i][j - 1], 
                    q.get_max() + presum[j]
                );
                // 3.出
                q.slide(j - r);
            }
            ans = max(ans, memo[i][n]);
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