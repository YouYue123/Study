// 1893. Check if All the Integers in a Range Are Covered [E]
// LeetCode check-if-all-the-integers-in-a-range-are-covered

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52);
        for(auto& r : ranges) {
            int s = r[0], e = r[1];
            diff[s] += 1;
            diff[e + 1] -= 1;
        }
        int cur = 0;
        for(int i = 0; i <= right; i ++) {
            cur += diff[i];
            if(i >= left && cur == 0) return false; 
        }
        return true;
    }
};