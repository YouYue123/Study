// 755. Pour Water [M]
// LeetCode pour-water

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int n = heights.size();
        while(volume > 0) {
            int left_low = heights[k];
            int left_low_idx = -1;
            for(int i = k - 1; i >= 0; i --) {
                if(heights[i] > left_low) break;
                if(heights[i] < heights[k] && heights[i] < left_low) {
                    left_low = heights[i];
                    left_low_idx = i;
                }
            }
            if(left_low_idx != -1) {
                heights[left_low_idx] += 1;
            } else {
                int right_low = heights[k];
                int right_low_idx = -1;
                for(int i = k + 1; i < n; i ++) {
                    if(heights[i] > right_low) break;
                    if(heights[i] < heights[k] && heights[i] < right_low) {
                        right_low = heights[i];
                        right_low_idx = i;
                    }
                }
                if(right_low_idx != -1) {
                    heights[right_low_idx] += 1;
                } else {
                    heights[k] += 1;
                }
            }
            volume -= 1;
        }
        return heights;
    }
};