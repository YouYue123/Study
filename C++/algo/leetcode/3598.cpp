// 3598. Longest Common Prefix Between Adjacent Strings After Removals [M]
// LeetCode longest-common-prefix-between-adjacent-strings-after-removals

class Solution {
public:
    int getLcp(string& a, string& b) {
        int len = min(a.size(), b.size());
        int cur = 0;
        while(cur < len && a[cur] == b[cur]) cur += 1;
        return cur;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n, 0);
        if(n <= 2) return ans;
        vector<int> lcp(n - 1, 0);
        for(int i = 0; i < n - 1; i ++) {
            lcp[i] = getLcp(words[i], words[i + 1]);
        }
        vector<int> prefixMax(n - 1, 0);
        vector<int> suffixMax(n - 1, 0);
        prefixMax[0] = lcp[0];
        for(int i = 1; i < n - 1; i ++) {
            prefixMax[i] = max(prefixMax[i - 1], lcp[i]);
        }
        suffixMax[n - 2] = lcp[n - 2];
        for(int i = n - 3; i >= 0; i --) {
            suffixMax[i] = max(suffixMax[i + 1], lcp[i]);
        }
        for(int i = 0; i < n; i ++) {
            int leftMax = 0;
            if(i - 2 >= 0) leftMax = prefixMax[i - 2];
            int rightMax = 0;
            if(i + 1 <= n - 2) rightMax = suffixMax[i + 1];
            int maxLcp = max(leftMax, rightMax);
            if(i - 1 >= 0 && i + 1 < n) {
                maxLcp = max(maxLcp, getLcp(words[i - 1], words[i + 1]));
            }
            ans[i] = maxLcp;
        }
        return ans;
    }
};