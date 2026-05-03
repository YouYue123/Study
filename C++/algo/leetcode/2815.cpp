// 2815. Max Pair Sum in an Array [E]
// LeetCode max-pair-sum-in-an-array

class Solution {
public:
    int findL(int x) {
        int ans = 0;
        while(x > 0) {
            ans = max(ans, x % 10);
            x /= 10;
        }
        return ans;
    }
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> dict;
        int ans = -1;
        for(int num : nums) {
            int key = findL(num);
            if(dict.contains(key)) {
                ans = max(ans, dict[key] + num);
            }
            dict[key] = max(num, dict[key]);
        }
        return ans;
    }
};