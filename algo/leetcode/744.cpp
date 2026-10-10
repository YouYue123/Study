#include <bits/stdc++.h>
using namespace std;

// 744. Find Smallest Letter Greater Than Target [E]
// LeetCode find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = -1, right = letters.size();
        char ans = letters[0];
        while(right > left + 1) {
            int mid = left + (right - left) / 2;
            if(letters[mid] > target) {
                ans = letters[mid];
                right = mid;
            } else {
                left = mid;
            }
        }
        // cout << left << " " << right << endl;
        return ans;
    }
};