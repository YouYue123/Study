#include <bits/stdc++.h>
using namespace std;

// 2170. Minimum Operations to Make the Array Alternating [M]
// LeetCode minimum-operations-to-make-the-array-alternating

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        unordered_map<int, int> even_freq;
        unordered_map<int, int> odd_freq;

        // 统计频数
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_freq[nums[i]]++;
            } else {
                odd_freq[nums[i]]++;
            }
        }

        // 辅助 lambda 函数：获取哈希表中出现次数最多和次多的两个数
        // 返回值格式：{最大数, 最大频数, 次大数, 次大频数}
        auto getTopTwo = [](const unordered_map<int, int>& freq) -> vector<int> {
            int first_num = 0, first_cnt = 0;
            int second_num = 0, second_cnt = 0;
            
            for (auto& [num, cnt] : freq) {
                if (cnt > first_cnt) {
                    second_cnt = first_cnt;
                    second_num = first_num;
                    first_cnt = cnt;
                    first_num = num;
                } else if (cnt > second_cnt) {
                    second_cnt = cnt;
                    second_num = num;
                }
            }
            return {first_num, first_cnt, second_num, second_cnt};
        };

        vector<int> even_res = getTopTwo(even_freq);
        vector<int> odd_res = getTopTwo(odd_freq);

        int e1 = even_res[0], e1_cnt = even_res[1], e2_cnt = even_res[3];
        int o1 = odd_res[0], o1_cnt = odd_res[1], o2_cnt = odd_res[3];

        // 如果奇数和偶数位置最多的数不相同，直接用最大频数相加
        if (e1 != o1) {
            return n - (e1_cnt + o1_cnt);
        }
        
        // 如果相同，取两种妥协方案中的最优解
        int planA = e1_cnt + o2_cnt; // 偶数用第1，奇数用第2
        int planB = e2_cnt + o1_cnt; // 偶数用第2，奇数用第1
        
        return n - max(planA, planB);
    }
};