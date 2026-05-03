#include <bits/stdc++.h>
using namespace std;

// 941. Valid Mountain Array [E]
// LeetCode valid-mountain-array

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        bool checkIncrease = true;
        bool hasIncrease = false, hasDecrease = false;
        for(int i = 1 ; i < n; i ++) {
            if(checkIncrease) {
                if(arr[i] == arr[i - 1]) return false;
                if(arr[i] < arr[i - 1]) {
                    checkIncrease = false;
                    hasDecrease = true;
                } else {
                    hasIncrease = true;
                }
            } else {
                if(arr[i] >= arr[i - 1]) return false;
            }
        }
        // cout << hasIncrease << " " << hasDecrease;
        return hasIncrease && hasDecrease;
    }
};