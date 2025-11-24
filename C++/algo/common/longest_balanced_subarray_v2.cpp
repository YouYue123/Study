#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // We'll use a different approach: track the difference between
        // distinct even and odd counts, and use a hash map to find
        // when this difference repeats, indicating a balanced subarray
        
        unordered_set<int> distinctEven, distinctOdd;
        unordered_map<int, int> diffToIndex;
        
        // Initialize with difference 0 at index -1
        diffToIndex[0] = -1;
        
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                distinctEven.insert(nums[i]);
            } else {
                distinctOdd.insert(nums[i]);
            }
            
            int diff = distinctEven.size() - distinctOdd.size();
            
            if (diffToIndex.find(diff) != diffToIndex.end()) {
                // We've seen this difference before
                // The subarray from diffToIndex[diff] + 1 to i is balanced
                int len = i - diffToIndex[diff];
                maxLen = max(maxLen, len);
            } else {
                // First time seeing this difference
                diffToIndex[diff] = i;
            }
        }
        
        return maxLen;
    }
};

// Test function
#include <iostream>
void testLongestBalanced() {
    Solution sol;
    
    // Test case 1: [2,5,4,3] -> 4
    vector<int> nums1 = {2, 5, 4, 3};
    cout << "Test 1: [2,5,4,3] -> " << sol.longestBalanced(nums1) << " (expected: 4)" << endl;
    
    // Test case 2: [3,2,2,5,4] -> 5
    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << "Test 2: [3,2,2,5,4] -> " << sol.longestBalanced(nums2) << " (expected: 5)" << endl;
    
    // Test case 3: [1,2,3,2] -> 3
    vector<int> nums3 = {1, 2, 3, 2};
    cout << "Test 3: [1,2,3,2] -> " << sol.longestBalanced(nums3) << " (expected: 3)" << endl;
    
    // Additional test cases
    vector<int> nums4 = {1, 1, 1, 1};
    cout << "Test 4: [1,1,1,1] -> " << sol.longestBalanced(nums4) << " (expected: 0)" << endl;
    
    vector<int> nums5 = {2, 4, 6, 8};
    cout << "Test 5: [2,4,6,8] -> " << sol.longestBalanced(nums5) << " (expected: 0)" << endl;
    
    vector<int> nums6 = {1, 2};
    cout << "Test 6: [1,2] -> " << sol.longestBalanced(nums6) << " (expected: 2)" << endl;
}

int main() {
    testLongestBalanced();
    return 0;
}
