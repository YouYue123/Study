#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ll = long long;
struct Block {
    ll B, n, idx;
    ll lazy = 0;
    unordered_map<int, int> freq;
    
    void build (vector<ll>& arr) {
        freq.clear();
        int start_origin_idx = idx * B;
        int end_origin_idx = min(n, start_origin_idx + B);
        for(int i = start_origin_idx; i < end_origin_idx; i ++) {
            auto elem = arr[i];
            freq[elem] += 1;
        }
    }
};
struct BlockManager {
    int B, blk_cnt;
    vector<ll> arr;                  
    vector<Block> blks;
    BlockManager(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++)  arr.push_back(nums[i]);
        int n = arr.size();
        B = sqrt(arr.size()) + 1;        
        blk_cnt = (n + B - 1) / B;
        for(int i = 0; i < blk_cnt; i ++) {
            auto blk = Block(B, n, i);
            blk.build(arr);
            blks.push_back(blk);
        }
    }
    void update(int left, int right, int val) {
        int start_b = left / B, end_b = right / B;
        if (start_b == end_b) {
            for (int i = left; i <= right; i++) arr[i] += val;
            blks[start_b].build(arr);
            return; 
        }
        for (int i = left; i < (start_b + 1) * B; i++) arr[i] += val;
        blks[start_b].build(arr);
        for (int i = end_b * B; i <= right; i++) arr[i] += val;
        blks[end_b].build(arr); 
        for (int i = start_b + 1; i < end_b; i++) {
            blks[i].lazy += val;
        }
    }

    int query(int target) {
        int ans = 0;
        for(auto& blk : blks) {
            int t = target - blk.lazy;
            if(blk.freq.contains(t)) ans += blk.freq[t];
        }
        return ans;
    }
};