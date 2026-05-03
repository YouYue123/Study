// 315. Count of Smaller Numbers After Self [H]
// LeetCode count-of-smaller-numbers-after-self

struct BIT {
    vector<long long> tree;
    BIT(int n) {
        tree.assign(n, 0);
    }
    int lowbit(int i) {
        return i & (-i);
    }
    void add(long index , int x) {
        index += 1;
        while(index < tree.size()) {
            tree[index] += x;
            index += lowbit(index);
        }
    }
    int query(long index) {
        index += 1;
        long ans = 0;
        while(index > 0) {
            ans += tree[index];
            index -= lowbit(index);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        auto bit = BIT(2 * 1e4 + 2);
        for(int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i] + 1e4;
            ans[i] = bit.query(num - 1);
            bit.add(num, 1);
        }
        return ans;
    }
};