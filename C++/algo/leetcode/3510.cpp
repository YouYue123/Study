// 3510. Minimum Pair Removal to Sort Array II [H]
// LeetCode minimum-pair-removal-to-sort-array-ii

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        // 存储所有相邻对：{元素和, 左侧元素下标}
        // set 默认升序，begin() 即为当前和最小的相邻对
        set<pair<long long, int>> pairs; 
        int dec = 0; // 记录当前序列中 a[i] > a[i+1] 的对数

        // 初始化：统计递减对并填充 pairs 集合
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] > nums[i + 1]) dec++;
            pairs.emplace(1L * nums[i] + nums[i + 1], i);
        }

        // 维护当前存在的下标，方便寻找前驱(prev)和后继(next)
        set<int> idxes;
        for (int i = 0; i < n; i++) idxes.insert(i);

        // 使用 long long 防止合并后溢出
        vector<long long> a(nums.begin(), nums.end());
        int ans = 0;

        // 只要还存在递减的情况，就继续合并
        while (dec > 0) {
            ans++; // 操作次数加 1

            // 贪心：取出当前和最小的相邻对进行合并
            auto [s, i] = *pairs.begin();
            pairs.erase(pairs.begin());

            // 找到当前下标 i 在 idx 集合中的位置
            auto it = idxes.lower_bound(i);
            // 找到 i 的下一个元素 nxt
            auto nxt_it = next(it);
            int nxt = *nxt_it;

            // --- 步骤 1: 更新当前合并对对 dec 的影响 ---
            // 即将合并 i 和 nxt，这一对旧的递减关系消失
            dec -= a[i] > a[nxt]; 

            // --- 步骤 2: 更新左侧邻居 (pre, i) 的关系 ---
            if (it != idxes.begin()) {
                int pre = *prev(it);
                // 1. 移除旧的 (pre, i) 关系对 dec 的贡献
                dec -= a[pre] > a[i]; 
                // 2. 移除旧的 (pre, i) 在 pairs 中的记录
                pairs.erase({a[pre] + a[i], pre});
                
                // 3. 计算合并后新的关系：(pre, i的新值)
                dec += a[pre] > s; 
                // 4. 将新的和放入 pairs
                pairs.emplace(a[pre] + s, pre);
            }

            // --- 步骤 3: 更新右侧邻居 (nxt, nxt2) 的关系 ---
            auto nxt2_it = next(nxt_it);
            if (nxt2_it != idxes.end()) {
                int nxt2 = *nxt2_it;
                // 1. 移除旧的 (nxt, nxt2) 关系对 dec 的贡献
                dec -= a[nxt] > a[nxt2];
                // 2. 移除旧的 (nxt, nxt2) 在 pairs 中的记录
                pairs.erase({a[nxt] + a[nxt2], nxt});

                // 3. 合并后，i 的新右邻居变成了 nxt2
                dec += s > a[nxt2]; 
                // 4. 将新的关系 (i, nxt2) 放入 pairs
                pairs.emplace(s + a[nxt2], i);
            }

            // --- 步骤 4: 执行合并操作 ---
            a[i] = s;       // 更新 i 的值为合并后的和
            idxes.erase(nxt); // 从存活下标中彻底删除 nxt
        }
        return ans;
    }
};