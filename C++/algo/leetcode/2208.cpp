// 2208. Minimum Operations to Halve Array Sum [M]
// LeetCode minimum-operations-to-halve-array-sum

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double totalSum = 0;

        for(int num : nums) {
             pq.push(num);
             totalSum += num;
        }
        int ans = 0;
        double cur = 0;
        while(cur < totalSum / 2) {
            double top = pq.top();
            pq.pop();
            cur += top / 2;
            pq.push(top / 2);
            ans += 1;
        }
        return ans;
    }
};