// 3371. Identify the Largest Outlier in an Array [M]
// LeetCode identify-the-largest-outlier-in-an-array

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> dict;

        for(int num : nums) {
            sum += num;
            dict[num] += 1;
        }
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 0; i --) {
            int restSum = sum - nums[i];
            if(abs(restSum) % 2 == 1) continue;
            int targetSum = restSum / 2;
            if(dict[targetSum] == 0) continue;
            if(targetSum == nums[i] && dict[targetSum] == 1) continue; 
            // cout << restSum << endl;
            // cout << targetSum << endl;

            return nums[i];
        }
        return -1;
    }
};