// 3768. Minimum Inversion Count in Subarrays of Fixed Length [H]
// LeetCode minimum-inversion-count-in-subarrays-of-fixed-length

struct BIT {
    vector<long long> tree;
    BIT(int n): tree(n + 1, 0) {}
    int lowbit(int i) {
        return i & (-i);
    }
    void add(int idx, int delta) {
        while(idx <  tree.size()) {
            tree[idx] += delta;
            idx += lowbit(idx);
        }
    }
    int query(int idx) {
        long long ans = 0;
        while(idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
};
class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        if(k == 1) return 0;
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(),sorted.end()), sorted.end());
        auto getRank = [&] (int val) {
            return lower_bound(sorted.begin(), sorted.end(), val) - sorted.begin() + 1;
        };
        BIT bit(sorted.size());
        long long cur = 0;
        for(int i = 0; i < k; i ++) {
            int rank = getRank(nums[i]);
            cur += (i - bit.query(rank));
            bit.add(rank, 1);
        }
        long long ans = cur;
        for(int i = 0; i < n - k; i ++) {
            int outVal = nums[i];
            int inVal = nums[i + k];
            int outRank = getRank(outVal);
            int inRank = getRank(inVal);
            bit.add(outRank, -1);
            cur -= bit.query(outRank - 1);
            cur += ((k - 1) - bit.query(inRank));
            bit.add(inRank, 1);
            ans = min(ans, cur);
        }
        // int ans = INT_MAX;
        // for(int i = 0; i < n; i ++) {
        //     BIT bit(ranks.size());
        //     int cnt = 0;
        //     for(int j = i + k - 1; j < n && j >= 0; j --) {
        //         long target = nums[j] / 2 - 1;
        //         auto it = sorted.upper_bound(target);
        //         if(it != sorted.begin()) {
        //             int x = ranks[*prev(it)];
        //             cnt += bit.query(x);
        //         }
        //         bit.add(ranks[nums[j]], 1);
        //     }
        //     ans = min(ans, cnt);
        // }
        return ans;
    }
};