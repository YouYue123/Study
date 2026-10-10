#include <bits/stdc++.h>
using namespace std;

// 3915. Maximum Sum of Alternating Subsequence With Distance at Least K [H]
// LeetCode maximum-sum-of-alternating-subsequence-with-distance-at-least-k

template<typename T>
class Fenwick {
    vector<T> f;

public:
    Fenwick(int n) : f(n) {}

    void update(int i, T val) {
        for (; i < f.size(); i += i & -i) {
            f[i] = max(f[i], val);
        }
    }

    T pre_max(int i) const {
        T res{};
        for (; i > 0; i &= i - 1) {
            res = max(res, f[i]);
        }
        return res;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        // 离散化 nums
        auto sorted = nums;
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());

        int n = nums.size();
        vector<long long> f_inc(n); // f_inc[i] 表示以 nums[i] 结尾且最后两项递增的交替子序列的最大和
        vector<long long> f_dec(n); // f_dec[i] 表示以 nums[i] 结尾且最后两项递减的交替子序列的最大和

        // 值域树状数组
        int m = sorted.size();
        Fenwick<long long> inc(m + 1); // 维护 f_inc[i] 的最大值
        Fenwick<long long> dec(m + 1); // 维护 f_dec[i] 的最大值

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                // 在这个时候才把 f_inc[i-k] 和 f_dec[i-k] 添加到值域树状数组中，从而保证转移来源的下标 <= i-k
                int j = nums[i - k];
                inc.update(m - j, f_inc[i - k]); // m-j 可以把后缀变成前缀
                dec.update(j + 1, f_dec[i - k]);
            }

            int x = nums[i];
            int j = ranges::lower_bound(sorted, x) - sorted.begin();
            nums[i] = j; // 注意这里修改了 nums[i]，这样上面的 nums[i-k] 无需二分

            f_inc[i] = dec.pre_max(j) + x;         // 计算满足 nums[i'] < x 的 f_dec[i'] 的最大值
            f_dec[i] = inc.pre_max(m - 1 - j) + x; // 计算满足 nums[i'] > x 的 f_inc[i'] 的最大值
            ans = max(ans, max(f_inc[i], f_dec[i])); // 枚举子序列以 nums[i] 结尾
        }

        return ans;
    }
};