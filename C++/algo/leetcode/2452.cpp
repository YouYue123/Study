// 2452. Words Within Two Edits of Dictionary [M]
// LeetCode words-within-two-edits-of-dictionary

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        auto is_valid = [&] (string& q, string& d) {
            int len = q.size();
            int cnt = 0;
            for(int i = 0; i < len ;i ++) {
                if(q[i] != d[i]) cnt += 1;
            }
            return cnt <= 2;
        };
        vector<string> ans;
        for(auto& q : queries) {
            for(auto& d : dictionary) {
                if(is_valid(q, d)) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};