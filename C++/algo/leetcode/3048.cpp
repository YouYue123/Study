// 3048. Earliest Second to Mark Indices I [M]
// LeetCode earliest-second-to-mark-indices-i

class Solution {
public:
    // Checks if it's possible to mark all indices within givenSec seconds
    bool isValid(int givenSec, vector<int>& nums, vector<int>& changeIndices) {
        // Track last occurrence of each index in changeIndices
        vector<int> lastOcc(nums.size(), -1);
        // Record the last time each index appears in changeIndices up to givenSec
        for (int t = 0; t < givenSec; t++) {
            lastOcc[changeIndices[t] - 1] = t;
        }
        // If any index doesn't appear in changeIndices, return false
        for(int occ : lastOcc) {
            if(occ == -1) return false;
        }
        // Count available operations (increments) at each second
        int cnt = 0;
        for (int i = 0; i < givenSec; i++) {
            int idx = changeIndices[i] - 1;
            // If this is the last occurrence of the index
            if (i == lastOcc[idx]) { 
                // Check if we have enough operations to mark this index
                if (nums[idx] > cnt) return false;
                // Deduct the required operations for marking
                cnt -= nums[idx];
            } else {
                // Increment available operations for non-marking seconds
                cnt++;
            }
        }
        // Return true if all indices can be marked
        return true;
    }
    
    // Finds the earliest second to mark all indices
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        // If there are more indices than seconds, marking all is impossible
        if (n > m) return -1;
        // Binary search range: min seconds needed is at least n-1
        int left = n - 1, right = m;
        while(left < right) {
            // Calculate middle point for binary search
            int mid = left + (right - left) / 2;
            // If valid at mid seconds, try earlier time
            if(isValid(mid, nums, changeIndices)) {
                right = mid;
            } else {
                // If not valid, try later time
                left = mid + 1;
            }
        }
        // Verify if the found time is valid, return it or -1 if impossible
        return isValid(left, nums, changeIndices) ? left : -1;
    }
};