// 1431. Kids With the Greatest Number of Candies [E]
// LeetCode kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = INT_MIN;
        for(int can: candies) maxNum = max(maxNum, can);
        vector<bool> ans;
        for(int can : candies) {
            if(can + extraCandies >= maxNum) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};