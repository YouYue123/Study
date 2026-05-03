// 2342. Max Sum of a Pair With Equal Sum of Digits [M]
// LeetCode max-sum-of-a-pair-with-equal-sum-of-digits

class Solution {
public:
    int getKey(int x) {
        int ans = 0;
        while(x > 0) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> dict;
        int ans = -1;
        for(int num : nums) {
            int key = getKey(num);
            if(dict.contains(key)) {
                ans = max(ans, dict[key] + num);
            }
            dict[key] = max(dict[key], num);
        }
        return ans;
    }
};