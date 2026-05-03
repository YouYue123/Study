// 16. 3Sum Closest [M]
// LeetCode 3sum-closest

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = -INF;
        for(int i = 0; i < n - 2; i ++) {
            int num = nums[i];
            int curTarget = target - num;
            int left = i + 1, right = n - 1;
            // cout << num << " " << curTarget << endl;
            while(left < right) {
                int curAns = num + nums[left] + nums[right];
                // cout << num << " " << nums[left]  << " " << nums[right] << endl;
                // cout << curAns << endl;
                if(abs(curAns - target) < abs(ans - target)) {
                    ans = curAns;
                }
                if(nums[left] + nums[right] < curTarget) {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }
        return ans;
    }
};