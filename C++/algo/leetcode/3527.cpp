// 3527. Find the Most Common Response [M]
// LeetCode find-the-most-common-response

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> dict;
        for(vector<string>& re : responses) {
            unordered_set<string> set;
            for(string s : re) set.insert(s);
            for(string s: set) {
                dict[s] += 1;
            }
        }
        vector<string> ans;
        int curMax = INT_MIN;
        // cout << "wer" << endl;
        for(auto p : dict) {
            // cout << p.first << " " << p.second << endl;
            if(p.second > curMax) {
                ans.clear();
                ans.push_back(p.first);
                curMax = p.second;
            } else if(p.second == curMax) {
                ans.push_back(p.first);
            }
        }
        // cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};