#include <bits/stdc++.h>
using namespace std;

// 912. Sort an Array [M]
// LeetCode sort-an-array

class Solution {
private:
   void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        // 1. 随机选基准值
        int pivot = nums[l + rand() % (r - l + 1)];

        // 2. 初始化三个指针
        int left = l;      // [l, left-1] 存储小于 pivot 的元素
        int i = l;       // [left, mid-1] 存储等于 pivot 的元素
        int right = r;     // [right+1, r] 存储大于 pivot 的元素

        // mid 是侦察兵，当它超过 right 边界时，说明全部处理完毕
        while (i <= right) {
            if (nums[i] < pivot) {
                // 发现小的，扔到左边区间
                // 此时 swap 过来的一定是等于 pivot 的数（或是 mid 自身），所以 mid 可以放心前进
                swap(nums[left], nums[i]);
                left++;
                i++;
            } else if (nums[i] > pivot) {
                // 发现大的，扔到右边区间
                // 注意：从 right 换回来的数 mid 还没看过，所以 mid 不能加 1
                swap(nums[i], nums[right]);
                right--;
            } else {
                // 等于 pivot，侦察兵直接继续走
                i++;
            }
        }

        // 3. 递归解决“小”和“大”的部分
        // 此时 [left, right] 区间全是等于 pivot 的数，已经排好了
        quickSort(nums, l, left - 1);
        quickSort(nums, right + 1, r);
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }    
};