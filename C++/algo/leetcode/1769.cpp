// 1769. Minimum Number of Operations to Move All Balls to Each Box [M]
// LeetCode minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);
        int leftCount = 0, leftSum = 0;
        int rightCount = 0, rightSum = 0;
        for(int i = 0; i < boxes.size(); i ++) {
            ans[i] += leftSum;
            leftCount += boxes[i] - '0';
            leftSum += leftCount;
            int j = boxes.size() - 1 - i;
            ans[j] += rightSum;
            rightCount += boxes[j] - '0';
            rightSum += rightCount;
        }
        return ans;
    }
};