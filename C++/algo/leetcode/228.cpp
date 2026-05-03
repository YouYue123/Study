// 228. Summary Ranges [E]
// LeetCode summary-ranges

class Solution {
public:
    string getStr(int start, int end) {
        string temp = "";
        temp += to_string(start);
        if(start != end) {
            temp += "->";
            temp += to_string(end);
        }
        return temp;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int start = nums[0];
        int end = nums[0];
        vector<string> ans;
        for(int i = 1; i < nums.size(); i ++) {
            int num = nums[i];
            if(end != num - 1) {
                ans.push_back(getStr(start, end));
                start = num;
            }
            end = num;
        }
        ans.push_back(getStr(start, end));
        return ans;
    }
};