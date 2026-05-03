// 134. Gas Station [M]
// LeetCode gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minSum = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i ++) {
            sum += gas[i] - cost[i];
            if(sum < minSum) {
                start = i + 1;
                minSum = sum;
            }
        }
        if(sum < 0) return -1;
        return start == gas.size() ? 0 : start;
    }
};