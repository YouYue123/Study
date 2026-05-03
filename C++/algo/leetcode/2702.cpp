// 2702. Minimum Operations to Make Numbers Non-positive [H]
// LeetCode minimum-operations-to-make-numbers-non-positive

class Solution {
public:
    bool isValid(long long ops, vector<int>& nums, int x, int y) {
        long long cnt = 0;
        for(int num : nums) {
            if(ops < 0) return false;
            if(num <= 0) continue;
            if(num > ops * x) {
                return false;
            } else if(num <= ops * y) {
                continue;
            } else {
                num -= ops * y;
                cnt += ceil((double)num / (x - y));
            }
        }
        return cnt <= ops;
    }
    int minOperations(vector<int>& nums, int x, int y) {
        long long left = 0, right = 1e9;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, nums, x, y)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};