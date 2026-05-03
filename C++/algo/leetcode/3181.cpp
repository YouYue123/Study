// 3181. Maximum Total Reward Using Operations II [H]
// LeetCode maximum-total-reward-using-operations-ii

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // 1. 预处理：排序并去重
        // 排序是为了满足约束条件：当前总和 < 下一个奖励值
        ranges::sort(rewardValues);

        // 2. 动态规划状态数组
        // 使用bitset来记录可达的总奖励值，f[i]=1表示可以达成总奖励i
        // 初始状态：总奖励0总是可达的
        bitset<100000> f{1};

        // 3. 处理每个奖励值
        for (int v : rewardValues) {
            // 取 f 的低 v 位，再左移 v 位，然后 OR 到 f 中
            // 左移 shift 再右移 shift，把所有 >= v 的比特位置 0
            f |= f << (f.size() - v) >> (f.size() - v) << v;
        }

        // 4. 寻找最大可达的总奖励值
        // 从理论最大值开始向下搜索：最大奖励值的2倍-1
        // 因为约束条件限制了最大可能值不会超过2*max(rewardValues)-1
        for (int i = rewardValues.back() * 2 - 1; ; i--) {
            if (f[i]) {
                return i;  // 返回第一个找到的可达的最大值
            }
        }
    }
};