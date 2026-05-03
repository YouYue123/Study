// 493. Reverse Pairs [H]
// LeetCode reverse-pairs

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 树状数组（Binary Indexed Tree）实现
struct BIT {
    vector<int> tree;  // 存储树状数组
    
    // 构造函数，初始化大小为n的树状数组
    BIT(int n): tree(n + 1, 0) {}
    
    // 单点更新操作：在index位置增加val
    void add(int index, int val) {
        while (index < tree.size()) {
            tree[index] += val;
            index += index & -index;  // 移动到父节点
        }
    }
    
    // 前缀查询操作：查询[1,index]的和
    int query(int index) {
        int ans = 0;
        while (index > 0) {
            ans += tree[index];
            index -= index & -index;  // 移动到前一个需要累加的节点
        }
        return ans;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // 第一步：离散化处理
        // 使用set自动排序并去重
        set<long> sorted(nums.begin(), nums.end());
        
       // 1. 预处理离散化（极其高效）
        vector<long> all_nums;
        for (int x : nums) all_nums.push_back(x);
        sort(all_nums.begin(), all_nums.end());
        all_nums.erase(unique(all_nums.begin(), all_nums.end()), all_nums.end());
        auto getRank = [&](long val) {
            return lower_bound(all_nums.begin(), all_nums.end(), val) - all_nums.begin() + 1;
        };
                
        BIT bit(all_nums.size());
        int ans = 0;
        
        // 第二步：从右往左遍历数组
        for (int i = nums.size() - 1; i >= 0; --i) {
            // 计算满足nums[i] > 2*nums[j]的target值
            // 处理正负数不同情况
            long target = nums[i] > 0 ? (nums[i] - 1) / 2 : nums[i] / 2 - 1;
            
            // 在离散化后的数组中找到第一个大于target的数
            auto it = sorted.upper_bound(target);
            
            // 如果存在比target小的数
            if (it != sorted.begin()) {
                // 计算这些数的最大排名
                int x = getRank(*prev(it));
                // 查询树状数组中比target小的数的个数
                ans += bit.query(x);
            }
            
            // 将当前数插入树状数组
            bit.add(getRank(nums[i]), 1);
        }
        
        return ans;
    }
};