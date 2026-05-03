// 3542. Minimum Operations to Convert All Elements to Zero [M]
// LeetCode minimum-operations-to-convert-all-elements-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> monoSt;
        int ans = 0;
        for(int num : nums) {
            while(!monoSt.empty() && monoSt.top() > num) {
                monoSt.pop();
                ans += 1;
            }
            if(!monoSt.empty() && monoSt.top() == num) continue;
            if(num == 0) continue;
            monoSt.push(num);
        }
        ans += monoSt.size();
        return ans;
    }
};