#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 分块：区间加 + 统计等于 target 的元素个数
// 不变量：块 b 内位置 i 的真实值 actual[i] = arr[i] + lazy[b]
// freq[b] 统计块内未加 lazy 的 arr[i] 出现次数，查询时再补上 lazy
struct BlockDecomposition {
    int n, B, block_cnt;
    vector<ll> arr;                              // 底数（不含块懒标记）
    vector<ll> lazy;                             // 整块统一加的懒标记
    vector<unordered_map<int, int>> freq;        // 每块内 arr[i] 的频次
    BlockDecomposition(vector<int>& input) {
        for(int i = 0; i < input.size(); i ++) {
            arr.push_back(input[i]);
        }
        n = arr.size();
        B = sqrt(n) + 1;                         // 块长约 sqrt(n)
        block_cnt = (n + B - 1) / B;
        lazy.assign(block_cnt, 0);
        freq.resize(block_cnt);
        for(int i = 0; i < block_cnt; i ++) rebuild(i);
    }
    // 散块修改 arr 后，重建该块的频次表
    void rebuild(int b_idx) {
        freq[b_idx].clear();
        int start = b_idx * B;
        int end = min(n, start + B);
        for(int i = start; i < end; i ++) {
            freq[b_idx][arr[i]] += 1;
        }
    }

    // 区间 [left, right] 每个位置加 val
    void update (int left, int right, int val) {
        int start_b = left / B, end_b = right / B;
        if(start_b == end_b) {
            // 同一块：直接改 arr，lazy 不变
            for(int i = left; i <= right; i ++) arr[i] += val;
            rebuild(start_b);
        } else {
            // 左右散块：arr 加 val 后重建频次
            for(int i = left; i < (start_b + 1) * B; i ++) arr[i] += val;
            rebuild(start_b);
            for(int i = end_b * B; i <= right; i ++) arr[i] += val;
            rebuild(end_b);
            // 中间整块覆盖：只改 lazy，每块 O(1)
            for(int i = start_b + 1; i < end_b; i ++) lazy[i] += val;
        }
    }

    // 统计真实值等于 target 的位置个数
    int query(int target) {
        int cnt = 0;
        for(int i = 0; i < block_cnt; i ++) {
            // 真实值 == target 等价于 arr[i] == target - lazy[块]
            int t = target - lazy[i];
            if(freq[i].contains(t)) {
                cnt += freq[i][t];
            }
        }
        return cnt;
    }
};