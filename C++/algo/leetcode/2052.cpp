#include <bits/stdc++.h>
using namespace std;

// 2052. Minimum Cost to Separate Sentence Into Rows [M]
// LeetCode minimum-cost-to-separate-sentence-into-rows

class Solution {
public:
    int minimumCost(string sentence, int k) {
        vector<int> wLen;
        stringstream iss(sentence);
        string w = "";
        int wLenSum = 0;
        while(iss >> w) {
            wLen.push_back(w.size());
            wLenSum += w.size() + (wLenSum == 0 ? 0 : 1);
        }
        // cout << wLenSum << endl;
        if(k >= wLenSum) return 0;
        int n = wLen.size();
        vector<int> memo(n, -1);
        // for(int item: wLen) cout << item << " ";
        // cout << endl;
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int curLen = 0;
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                curLen += wLen[j] + (j == i ? 0 : 1);
                if(curLen > k) break;
                int remain = dfs(j + 1);
                int cost = (k - curLen) * (k - curLen);
                if(remain != INT_MAX) ans = min(ans, remain + (j + 1 == n ? 0 : cost ));
            }
            return memo[i] = ans;
        };
        // dfs(0);
        // for(int item : memo) cout << item << " ";
        return dfs(0);
    }
};