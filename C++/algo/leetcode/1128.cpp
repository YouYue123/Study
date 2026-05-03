// 1128. Number of Equivalent Domino Pairs [E]
// LeetCode number-of-equivalent-domino-pairs

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, unordered_map<int, int>> dict;
        int ans = 0;
        for(auto& d : dominoes) {
            ans += dict[d[0]][d[1]];
            if(d[0] != d[1]) ans += dict[d[1]][d[0]];
            dict[d[0]][d[1]] += 1;
        }
        return ans;
    }
};