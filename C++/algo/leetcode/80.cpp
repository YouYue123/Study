// 80. Remove Duplicates from Sorted Array II [M]
// LeetCode remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int p1 = 2, p2 = 2;
        while(p2 < nums.size()) {
            nums[p1] = nums[p2];
            if(nums[p1] != nums[p1 - 2]) p1 += 1;
            p2 += 1;
        }
        return p1;
    }
};