// 1095. Find in Mountain Array [H]
// LeetCode find-in-mountain-array

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int peak = left;
        left = 0, right = peak;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) >= target) {
                if(mountainArr.get(mid) == target) return mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
         // Search right (descending) half with while (left < right)
        left = peak, right = mountainArr.length() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val <= target) {  // Reverse condition for descending order
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (mountainArr.get(left) == target) return left;
        return -1;
    }
};