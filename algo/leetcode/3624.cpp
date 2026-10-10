#include <bits/stdc++.h>
using namespace std;

// 3624. Number of Integers With Popcount-Depth Equal to K II [H]
// LeetCode number-of-integers-with-popcount-depth-equal-to-k-ii

class FenwickTree {
private:
    std::vector<int> bit;
    int size;

public:
    FenwickTree(int n) : size(n), bit(n + 1, 0) {}

    void add(int idx, int delta) {
        for (++idx; idx <= size; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    int query_prefix(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    int query_range(int l, int r) {
        if (l > r) return 0;
        return query_prefix(r) - query_prefix(l - 1);
    }
};

int get_popcount_depth(long long n) {
    static int depth_precalc[61];
    static bool precomputed = []() {
        depth_precalc[1] = 0;
        for (int i = 2; i <= 60; ++i) {
            depth_precalc[i] = 1 + depth_precalc[__builtin_popcount((unsigned int)i)];
        }
        return true;
    }();

    if (n <= 60) {
        return depth_precalc[n];
    }
    
    int pc = __builtin_popcountll(n);
    return 1 + depth_precalc[pc];
}

class Solution {
public:
    std::vector<int> popcountDepth(std::vector<long long>& nums, std::vector<std::vector<long long>>& queries) {
        int n = nums.size();
        std::vector<FenwickTree> bits;
        for (int i = 0; i < 6; ++i) {
            bits.emplace_back(n);
        }

        for (int i = 0; i < n; ++i) {
            int d = get_popcount_depth(nums[i]);
            if (d < 6) {
                bits[d].add(i, 1);
            }
        }

        std::vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            if (q[0] == 1) {
                int l = static_cast<int>(q[1]);
                int r = static_cast<int>(q[2]);
                int k = static_cast<int>(q[3]);
                if (k >= 6) {
                    answer.push_back(0);
                } else {
                    answer.push_back(bits[k].query_range(l, r));
                }
            } else {
                int idx = static_cast<int>(q[1]);
                long long val = q[2];
                int old_d = get_popcount_depth(nums[idx]);
                if (old_d < 6) {
                    bits[old_d].add(idx, -1);
                }
                nums[idx] = val;
                int new_d = get_popcount_depth(val);
                if (new_d < 6) {
                    bits[new_d].add(idx, 1);
                }
            }
        }
        
        return answer;
    }
};