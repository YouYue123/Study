// 830. Positions of Large Groups [E]
// LeetCode positions-of-large-groups

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0;
        while(start < s.size()) {
            int finish = start;
            while(finish < s.size() && s[finish] == s[start]) {
                finish += 1;
            }
            if(finish - start >= 3) ans.push_back({start, finish - 1});
            start = finish;
        }
        return ans;
    }
};