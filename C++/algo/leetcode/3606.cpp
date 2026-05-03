// 3606. Coupon Code Validator [E]
// LeetCode coupon-code-validator

struct Node {
    string code;
    string businessLine;
};
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<Node> nodes;
        unordered_set<string> dict= {"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i = 0 ; i < n ; i++) {
            bool isValid = true;
            if(code[i].size() == 0) isValid = false; 
            if(code[i].size() > 0) {
                for(char c : code[i]) {
                    if(!isalnum(c) && c != '_') {
                        isValid = false;
                        break;
                    }
                }
            }
            if(!dict.contains(businessLine[i])) isValid = false;
            if(!isActive[i]) isValid = false;
            if(isValid) nodes.emplace_back(code[i], businessLine[i]);
        }
        sort(nodes.begin(), nodes.end(), [&] (const Node& a, const Node& b) {
            if(a.businessLine == b.businessLine) {
                return a.code < b.code;
            }
            return a.businessLine < b.businessLine;
        });
        vector<string> ans;
        for(auto& node : nodes) {
            ans.push_back(node.code);
        }
        return ans;
    }
};