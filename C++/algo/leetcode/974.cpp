// 974. Subarray Sums Divisible by K [M]
// LeetCode subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // 4 9 9 7 4 5
        int sum = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        int ans = 0;
        for(int num : nums) {
            sum += num;
            int posMod = (sum % k + k) % k;   // 正余数
            ans += dict[posMod];
            dict[posMod] += 1;
        }
        return ans;
    }
};