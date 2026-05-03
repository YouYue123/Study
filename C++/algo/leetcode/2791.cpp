// 2791. Count Paths That Can Form a Palindrome in a Tree [H]
// LeetCode count-paths-that-can-form-a-palindrome-in-a-tree

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = s.size();
        unordered_map<int, vector<int>> g;
        for(int i = 1; i < n; i ++) {
            int p = parent[i];
            g[p].push_back(i);
        }
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        auto dfs = [&] (this auto&& dfs, int i, int val) -> void {
            for(int nxt : g[i]) {
                int nxtVal = val ^ (1 << (s[nxt] - 'a'));
                ans += cnt.contains(nxtVal) ? cnt[nxtVal] : 0;
                for(int j = 0; j < 26; j ++) {
                    int t = nxtVal ^ (1 << j);
                    ans += cnt.contains(t) ? cnt[t] : 0;
                }
                cnt[nxtVal] += 1;
                dfs(nxt, nxtVal);
            }
        };
        dfs(0, 0);
        return ans;
    }
};