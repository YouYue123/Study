// 1539. Kth Missing Positive Number [E]
// LeetCode kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = -1, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] - (mid + 1) < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1 + k;
    }
};