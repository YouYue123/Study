#include <bits/stdc++.h>
using namespace std;

// 658. Find K Closest Elements [M]
// LeetCode find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        while(right - left + 1 > k) {
            if(abs(arr[right] - x) >= abs(arr[left] - x)) {
                right -= 1;
            } else {
                left += 1;
            }
        }
        vector<int> ans;
        for(int i = left; i <= right; i ++) ans.push_back(arr[i]);
        return ans;
    }
};