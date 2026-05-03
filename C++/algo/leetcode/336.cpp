// 336. Palindrome Pairs [H]
// LeetCode palindrome-pairs

class Solution {
public:


    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        int n = words.size();
        // 辅助函数：检查字符串的子串 [l, r] 是否为回文
        auto isP = [&] (string& s, int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l += 1;
                r -= 1;
            }
            return true;
        };
        // 1. 将所有单词存入哈希表，方便 O(1) 查找
        for (int i = 0; i < n; i++) dict[words[i]] = i;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            int m = word.size();

            // 2. 拆分单词为 prefix 和 suffix
            // 注意：j 的范围是 0 到 m，以包含空字符串的情况
            for (int j = 0; j <= m; j++) {
                // 情况 A: 如果 prefix 是回文，只要能找到 suffix 的翻转，就能构成 [rev_suffix, word]
                if (isP(word, 0, j - 1)) {
                    string suffix = word.substr(j);
                    reverse(suffix.begin(), suffix.end());
                    if (dict.contains(suffix) && dict[suffix] != i) {
                        ans.push_back({dict[suffix], i});
                    }
                }

                // 情况 B: 如果 suffix 是回文，只要能找到 prefix 的翻转，就能构成 [word, rev_prefix]
                // 注意 j != m 是为了避免与情况 A 在 j=0 时处理重复（如 word 本身和空串的组合）
                if (j < m && isP(word, j, m - 1)) {
                    string prefix = word.substr(0, j);
                    reverse(prefix.begin(), prefix.end());
                    if (dict.count(prefix) && dict[prefix] != i) {
                        ans.push_back({i, dict[prefix]});
                    }
                }
            }
        }
        return ans;
    }
};