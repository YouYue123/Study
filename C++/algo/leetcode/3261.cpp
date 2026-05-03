// 3261. Count Substrings That Satisfy K-Constraint II [H]
// LeetCode count-substrings-that-satisfy-k-constraint-ii

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k,
                                                 vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> memo(n, 0); // memo[i] 表示以 s[i] 结尾的最远左边界
        vector<int> dict(2, 0); // 记录当前窗口中 0 和 1 的数量
        int left = 0;

        // 预处理：滑动窗口计算每个位置的 memo[i]
        for (int right = 0; right < n; ++right) {
            dict[s[right] - '0'] += 1;
            // 调整左边界，确保窗口中 0 和 1 的数量都不超过 k
            while (dict[0] > k && dict[1] > k) {
                dict[s[left] - '0'] -= 1;
                left += 1;
            }
            memo[right] = left;
        }

        // 计算前缀和数组 presum，presum[i] 表示前 i 个字符的满足条件的子串总数
        vector<long long> presum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + (i - memo[i - 1]);
        }
        vector<long long> preMemo(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            preMemo[i] = preMemo[i - 1] + memo[i - 1];
        }

        // 处理查询
        vector<long long> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            // total if we didn’t cap the window at l:
            long long total = presum[r + 1] - presum[l];

            // find first index m in [l..r] with memo[m] >= l
            int m = int(lower_bound(memo.begin() + l, memo.begin() + r + 1, l) -
                        memo.begin());
            long long cnt = m - l;
            long long sumMemo = preMemo[m] - preMemo[l];
            long long over = cnt * (long long)l - sumMemo;
            ans.push_back(total - over);
        }
        return ans;
    }
};