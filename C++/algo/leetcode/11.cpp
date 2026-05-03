// 11. Container With Most Water [M]
// LeetCode container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;
        while(left < right) {
            ans = max(
                ans,
                (right - left) * min(height[left], height[right])
            );
            if(height[left] >= height[right]) {
                right -= 1;
            } else {
                left += 1;
            }
        }
        return ans;
    }
};