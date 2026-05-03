// 1925. Count Square Sum Triples [E]
// LeetCode count-square-sum-triples

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        unordered_set<int> dict;
        for(int i = 1; i <= n; i ++) dict.insert(i * i);
        for(int i = 1; i <= n; i ++) {
            for(int j = i; j <= n; j ++) {
                int powC = i * i + j * j;
                // cout << powC << endl;
                if(dict.contains(powC)) {
                    // cout << i << " " << j << endl;
                    // cout << powC << endl;
                    ans += (i == j ? 1 : 2);
                }
            }
        }
        return ans;
    }
};