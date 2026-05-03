// 3587. Minimum Adjacent Swaps to Alternate Parity [M]
// LeetCode minimum-adjacent-swaps-to-alternate-parity

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> pos;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] % 2 == 0) pos.push_back(i);
        }
        int evenCount = pos.size();
        int oddCount = nums.size() - evenCount;
        if(abs(oddCount - evenCount) > 1) return -1;
        auto calc = [&] (int start) -> int {
            if((nums.size() - start + 1) / 2 != pos.size()) {
                return INT_MAX;
            }
            int ans = 0;
            for(int i = 0; i < pos.size(); i ++) {
                ans += abs(pos[i] - (2 * i + start));
            }
            return ans;
        };
        return min(calc(0), calc(1));
    }
};