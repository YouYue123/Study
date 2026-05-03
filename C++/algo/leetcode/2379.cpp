// 2379. Minimum Recolors to Get K Consecutive Black Blocks [E]
// LeetCode minimum-recolors-to-get-k-consecutive-black-blocks

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, right = 0;
        int blackCount = 0;
        int ans = INT_MAX;
        while(right < blocks.size()) {
            if(blocks[right] == 'B') blackCount += 1;
            if(right - left + 1 > k) {
                if(blocks[left] == 'B') blackCount -= 1;
                left += 1;
            }
            if(right - left + 1 == k) {
                ans = min(ans, k - blackCount);
            }
            right += 1;
        }
        return ans;
    }
};