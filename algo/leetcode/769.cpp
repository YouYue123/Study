#include <bits/stdc++.h>
using namespace std;

// 769. Max Chunks To Make Sorted [M]
// LeetCode max-chunks-to-make-sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int right = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i ++) {
            right = max(right, arr[i]);
            if(right == i) ans += 1;
        }
        return ans;
    }
};